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
	const float radius = 2.0;

	sf::CircleShape circle(radius);
    circle.setFillColor(coord_system->color);
	circle.setPosition(sf::Vector2f(coord_system->x0 - radius, coord_system->y0 - radius));

	window->draw(circle);

	for (float x_position = coord_system->x0; x_position <= 192*5.f; x_position += coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(x_position - radius, coord_system->y0 - radius));
		window->draw(circle);
	}

	for (float x_position = coord_system->x0; x_position >= 0.f; x_position -= coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(x_position - radius, coord_system->y0 - radius));
		window->draw(circle);
	}

	for (float y_position = coord_system->y0; y_position >= 0.f; y_position -= coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(coord_system->x0 - radius, y_position - radius));
		window->draw(circle);
	}

	for (float y_position = coord_system->y0; y_position <= 108*5.f; y_position += coord_system->base_len)
	{
		circle.setPosition(sf::Vector2f(coord_system->x0 - radius, y_position - radius));
		window->draw(circle);
	}
}

//--------------------------------------------------------------------------------------------------------------------

void Coord_System::draw(sf::RenderWindow* window)
{
	sf::Vertex x_coord[] =
	{
		sf::Vertex(sf::Vector2f(Coord_System::x0, 0.f),     Coord_System::color),
		sf::Vertex(sf::Vector2f(Coord_System::x0, 108*5.f), Coord_System::color)
	};
	window->draw(x_coord, 2, sf::Lines);

	sf::Vertex y_coord[] =
	{
		sf::Vertex(sf::Vector2f(0.f,     Coord_System::y0), Coord_System::color),
		sf::Vertex(sf::Vector2f(192*5.f, Coord_System::y0), Coord_System::color)
	};
	window->draw(y_coord, 2, sf::Lines);

	DrawCircles(window, this);
}