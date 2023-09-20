#include "coord_system.h"

//--------------------------------------------------------------------------------------------------------------------

Coord_System::Coord_System(double x0, double y0, double base_len, sf::Color color) :
	x0 (x0),
	y0 (y0),
	base_len (base_len),
	color    (color)
	{}


Coord_System::~Coord_System()
{
	this->x0       = std::numeric_limits<double>::signaling_NaN();
	this->y0       = std::numeric_limits<double>::signaling_NaN();
	this->base_len = std::numeric_limits<double>::signaling_NaN();
}

//--------------------------------------------------------------------------------------------------------------------

void DrawCircles(sf::RenderWindow* window, Coord_System* coord_system)
{
	sf::CircleShape circle(RADIUS);
    circle.setFillColor(coord_system->color);

	double div_x = (coord_system->x0) / (coord_system->base_len);
	double div_y = (coord_system->y0) / (coord_system->base_len);
	double x = coord_system->base_len * (div_x - floor(div_x));
	double y = coord_system->base_len * (div_y - floor(div_y));

	for (; x <= WIDTH_OF_WINDOW;  x += coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(x - RADIUS, coord_system->y0 - RADIUS));
		window->draw(circle);
	}
	for (; y <= HEIGHT_OF_WINDOW; y += coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(coord_system->x0 - RADIUS, y - RADIUS));
		window->draw(circle);
	}
}

//--------------------------------------------------------------------------------------------------------------------

void Coord_System::draw(sf::RenderWindow* window)
{
	sf::Vertex x_coord[] =
	{
		sf::Vertex(sf::Vector2f(Coord_System::x0, 0.f),              Coord_System::color),
		sf::Vertex(sf::Vector2f(Coord_System::x0, HEIGHT_OF_WINDOW), Coord_System::color)
	};
	window->draw(x_coord, 2, sf::Lines);

	sf::Vertex y_coord[] =
	{
		sf::Vertex(sf::Vector2f(0.f,             Coord_System::y0), Coord_System::color),
		sf::Vertex(sf::Vector2f(WIDTH_OF_WINDOW, Coord_System::y0), Coord_System::color)
	};
	window->draw(y_coord, 2, sf::Lines);

	DrawCircles(window, this);
}