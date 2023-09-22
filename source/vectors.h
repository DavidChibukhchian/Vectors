#ifndef _VECTORS_H
#define _VECTORS_H

//---------------------------------------------------------------------------------------------------------------------

#include <SFML\Graphics.hpp>
#include <limits>
#include "coord_system.h"

//---------------------------------------------------------------------------------------------------------------------

class Vec
{
	public:

	double x;
	double y;	

	Vec(double x, double y);
	~Vec();
};

//---------------------------------------------------------------------------------------------------------------------

Vec  VecOpposite(Vec a);

Vec  VecMul(Vec a, double scalar);

Vec  VecAdd(Vec a, Vec b);

Vec  VecSub(Vec a, Vec b);

void VecDraw(Vec vec, Coord_System cs, sf::RenderWindow* window, sf::Color color);

//---------------------------------------------------------------------------------------------------------------------

#endif // _VECTORS_H