#ifndef _COORD_SYSTEM_H
#define _COORD_SYSTEM_H

//---------------------------------------------------------------------------------------------------------------------

#include <SFML\Graphics.hpp>
#include <limits>
#include <math.h>
#include "common.h"

//---------------------------------------------------------------------------------------------------------------------

class Coord_System
{
	public:

	double x0;
	double y0;
	double basis_len;
	sf::Color color;

	void draw(sf::RenderWindow* window);

	Coord_System(double x0, double y0, double len, sf::Color color);
	~Coord_System();
};

//---------------------------------------------------------------------------------------------------------------------

#endif // _COORD_SYSTEM_H