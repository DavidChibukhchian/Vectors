#include "vectors.h"
#include "common.h"

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

//---------------------------------------------------------------------------------------------------------------------

static void calculate_arrow(sf::Vertex* left_line, sf::Vertex* right_line, Vec vec, Coord_System cs, sf::Color color)
{
	double opposite_vec_x = (-1) * (vec.x) / MULTIPLIER;
	double opposite_vec_y = (-1) * (vec.y) / MULTIPLIER;
	Vec opposite_vec(opposite_vec_x, opposite_vec_y);

	double  len = sqrt((vec.x)*(vec.x) + (vec.y)*(vec.y)) / MULTIPLIER;
	double coef = - (vec.x / vec.y);

	double left_normal_x = len / (sqrt(1 + (coef * coef)));
	double left_normal_y = coef * left_normal_x;
	Vec  left_normal(  left_normal_x,   left_normal_y);
	Vec right_normal(- left_normal_x, - left_normal_y);
	
	Vec  left_arrow = VecAdd(left_normal,  opposite_vec);
	left_line[0]  = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len *  vec.x,                  cs.y0 - cs.base_len *  vec.y),                 color);
	left_line[1]  = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len * (vec.x + left_arrow.x),  cs.y0 - cs.base_len * (vec.y + left_arrow.y)), color);

	Vec right_arrow = VecAdd(right_normal, opposite_vec);
	right_line[0] = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len *  vec.x,                  cs.y0 - cs.base_len *  vec.y),                  color);
	right_line[1] = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len * (vec.x + right_arrow.x), cs.y0 - cs.base_len * (vec.y + right_arrow.y)), color);
}

//---------------------------------------------------------------------------------------------------------------------

static void draw_arrow(sf::Vertex* left_line, sf::Vertex* right_line, sf::RenderWindow* window)
{
	window->draw(left_line,  2, sf::Lines);
	window->draw(right_line, 2, sf::Lines);
}

//---------------------------------------------------------------------------------------------------------------------

void VecDraw(Vec vec, Coord_System cs, sf::RenderWindow* window, sf::Color color)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(cs.x0                      , cs.y0                      ), color),
		sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len * vec.x, cs.y0 - cs.base_len * vec.y), color)
	};
	window->draw(line, 2, sf::Lines);

	sf::Vertex  left_arrow[2];
	sf::Vertex right_arrow[2];
	calculate_arrow(left_arrow, right_arrow, vec, cs, color);
	draw_arrow(left_arrow, right_arrow, window);
}

//---------------------------------------------------------------------------------------------------------------------