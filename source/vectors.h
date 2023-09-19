#include <SFML\Graphics.hpp>
#include <limits>

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

Vec VecOpposite(Vec a);

Vec VecMul(Vec a, double scalar);

Vec VecAdd(Vec a, Vec b);

Vec VecSub(Vec a, Vec b);