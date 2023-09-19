#include "vectors.h"

//---------------------------------------------------------------------------------------------------------------------

Vec::Vec(double x, double y) :
	x (x),
	y (y)
	{}

Vec::~Vec()
{
	this->x = std::numeric_limits<double>::signaling_NaN();
	this->y = std::numeric_limits<double>::signaling_NaN();
}

//---------------------------------------------------------------------------------------------------------------------

Vec VecOpposite(Vec a)
{
	Vec res((-1)*(a.x), (-1)*(a.y));

	return res;
}

//---------------------------------------------------------------------------------------------------------------------

Vec VecMul(Vec a, double scalar)
{
	Vec res(scalar * a.x, scalar * a.y);

	return res;
}

//---------------------------------------------------------------------------------------------------------------------

Vec VecAdd(Vec a, Vec b)
{
	Vec res(a.x + b.x, a.y + b.y);

	return res;
}

//---------------------------------------------------------------------------------------------------------------------

Vec VecSub(Vec a, Vec b)
{
	Vec res = VecAdd(a, VecOpposite(b));

	return res;
}