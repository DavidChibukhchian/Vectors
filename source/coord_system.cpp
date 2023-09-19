#include "coord_system.h"

Coord_System::Coord_System(double x0, double y0, double length, sf::Color color) :
	x0_position (x0),
	y0_position (y0),
	base_length (length),
	color       (color)
	{}

Coord_System::~Coord_System()
{
	this->x0_position = std::numeric_limits<double>::signaling_NaN();
	this->y0_position = std::numeric_limits<double>::signaling_NaN();
	this->base_length = std::numeric_limits<double>::signaling_NaN();
}

void Coord_System::draw(sf::RenderWindow* window)
{
	sf::Vertex line[] =
	{
    	sf::Vertex(sf::Vector2f(300.f, 0.f), Coord_System::color),
    	sf::Vertex(sf::Vector2f(300.f, 400), Coord_System::color)
	};
	
	window->draw(line, 20, sf::Lines);
}