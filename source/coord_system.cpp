#include "coord_system.h"

//--------------------------------------------------------------------------------------------------------------------

Coord_System::Coord_System(double x0, double y0, double basis_len, sf::Color color) :
	x0        (x0),
	y0        (y0),
	basis_len (basis_len),
	color     (color)
	{}


Coord_System::~Coord_System()
{
	this->x0        = std::numeric_limits<double>::signaling_NaN();
	this->y0        = std::numeric_limits<double>::signaling_NaN();
	this->basis_len = std::numeric_limits<double>::signaling_NaN();
}

//--------------------------------------------------------------------------------------------------------------------

static void DrawCircles(sf::RenderWindow* window, Coord_System* cs)
{
	sf::CircleShape circle(RADIUS);
	circle.setFillColor(cs->color);

	for (double x = cs->x0; (x <= cs->x0 + LEN_OF_AXIS - RADIUS) and (x <= WIDTH_OF_WINDOW - RADIUS);  x += cs->basis_len)
	{
		circle.setPosition(sf::Vector2f(x - RADIUS, cs->y0 - RADIUS));
		window->draw(circle);
	}
	
	for (double y = cs->y0; (y <= cs->y0 + LEN_OF_AXIS - RADIUS) and (y <= HEIGHT_OF_WINDOW - RADIUS); y += cs->basis_len)
	{
		circle.setPosition(sf::Vector2f(cs->x0 - RADIUS, y - RADIUS));
		window->draw(circle);
	}

	for (double x = cs->x0; (x >= cs->x0 - LEN_OF_AXIS + RADIUS) and (x >= RADIUS); x -= cs->basis_len)
	{
		circle.setPosition(sf::Vector2f(x - RADIUS, cs->y0 - RADIUS));
		window->draw(circle);
	}

	for (double y = cs->y0; (y >= cs->y0 - LEN_OF_AXIS + RADIUS) and (y >= RADIUS); y -= cs->basis_len)
	{
		circle.setPosition(sf::Vector2f(cs->x0 - RADIUS, y - RADIUS));
		window->draw(circle);
	}
}

//--------------------------------------------------------------------------------------------------------------------

void Coord_System::draw(sf::RenderWindow* window)
{
	float x_right = 0;
	float x_left  = 0;
	
	if (Coord_System::x0 + LEN_OF_AXIS < WIDTH_OF_WINDOW) x_right = Coord_System::x0 + LEN_OF_AXIS;
	else                                                  x_right = WIDTH_OF_WINDOW;        

	if (Coord_System::x0 - LEN_OF_AXIS > 0)               x_left  = Coord_System::x0 - LEN_OF_AXIS;
	else                                                  x_left  = 0;

	sf::Vertex x_axis[] =
		{ sf::Vertex(sf::Vector2f(x_left,  Coord_System::y0), Coord_System::color),
		  sf::Vertex(sf::Vector2f(x_right, Coord_System::y0), Coord_System::color) };
	window->draw(x_axis, 2, sf::Lines);


	float y_down  = 0;
	float y_up    = 0;

	if (Coord_System::y0 + LEN_OF_AXIS < HEIGHT_OF_WINDOW) y_down = Coord_System::y0 + LEN_OF_AXIS;
	else                                                   y_down = HEIGHT_OF_WINDOW;

	if (Coord_System::y0 - LEN_OF_AXIS > 0)                y_up   = Coord_System::y0 - LEN_OF_AXIS;
	else                                                   y_up   = 0;

	sf::Vertex y_axis[] =
		{ sf::Vertex(sf::Vector2f(Coord_System::x0, y_down),  Coord_System::color),
		  sf::Vertex(sf::Vector2f(Coord_System::x0, y_up),    Coord_System::color) };
	window->draw(y_axis, 2, sf::Lines);


	DrawCircles(window, this);
}

//---------------------------------------------------------------------------------------------------------------------