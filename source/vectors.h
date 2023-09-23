#ifndef _VECTORS_H
#define _VECTORS_H

//---------------------------------------------------------------------------------------------------------------------

#include <SFML\Graphics.hpp>
#include <limits>
#include "common.h"
#include "coord_system.h"

//---------------------------------------------------------------------------------------------------------------------

class Vec
{
	public:

	double x;
	double y;	

	Vec operator-();

	Vec(double x, double y);
	~Vec();
};

//---------------------------------------------------------------------------------------------------------------------

Vec operator*(const double scalar, const Vec vec);

Vec operator+(const Vec a, const Vec b);

Vec operator-(const Vec a, const Vec b);

Vec VecSetByMouse(sf::RenderWindow* window, Coord_System cs);

void VecRotate(Vec* vec, double angle);

void VecDraw(Vec vec, Coord_System cs, sf::RenderWindow* window, sf::Color color);

//---------------------------------------------------------------------------------------------------------------------

#endif // _VECTORS_H