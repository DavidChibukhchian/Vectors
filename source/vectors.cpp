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

void VecRotate(Vec* vec, double angle)
{
	double new_x = vec->x * cos(angle) + vec->y * sin(angle);
	double new_y = - vec->x * sin(angle) + vec->y * cos(angle);

	vec->x = new_x;
	vec->y = new_y;
}


//---------------------------------------------------------------------------------------------------------------------

void calculate_an_arrow(double len, sf::Vertex* arrow, double side_coef, Vec vec, Coord_System cs,
						sf::Color color, Vec small_opposite_vec)
{
	double normal_vec_x = 0;
	double normal_vec_y = 0;

	if (vec.y == 0)
	{
		normal_vec_x = 0;
		normal_vec_y = len * side_coef;
	}
	else
	{
		double coef = - (vec.x / vec.y);
		normal_vec_x = len / (sqrt(1 + (coef * coef))) * side_coef;
		normal_vec_y = coef * normal_vec_x;
	}

	Vec  normal_vec(normal_vec_x, normal_vec_y);

	Vec  arrow_vec = VecAdd(normal_vec, small_opposite_vec);
	arrow[0]  = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len *  vec.x,
	                                	cs.y0 - cs.base_len *  vec.y),                color);
	arrow[1]  = sf::Vertex(sf::Vector2f(cs.x0 + cs.base_len * (vec.x + arrow_vec.x),
	                                    cs.y0 - cs.base_len * (vec.y + arrow_vec.y)), color);
}

//---------------------------------------------------------------------------------------------------------------------

static void calculate_arrows(sf::Vertex* left_arrow, sf::Vertex* right_arrow, Vec vec, Coord_System cs, sf::Color color)
{
	double small_opposite_vec_x = (-1) * (vec.x) / MULTIPLIER;
	double small_opposite_vec_y = (-1) * (vec.y) / MULTIPLIER;
	Vec small_opposite_vec(small_opposite_vec_x, small_opposite_vec_y);

	double  len = sqrt((vec.x)*(vec.x) + (vec.y)*(vec.y)) / MULTIPLIER;

	calculate_an_arrow(len,  left_arrow,  1, vec, cs, color, small_opposite_vec);
	calculate_an_arrow(len, right_arrow, -1, vec, cs, color, small_opposite_vec);
}

//---------------------------------------------------------------------------------------------------------------------

static void draw_arrows(sf::Vertex* left_arrow, sf::Vertex* right_arrow, sf::RenderWindow* window)
{
	window->draw(left_arrow,  2, sf::Lines);
	window->draw(right_arrow, 2, sf::Lines);
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
	calculate_arrows(left_arrow, right_arrow, vec, cs, color);
	draw_arrows(left_arrow, right_arrow, window);
}

//---------------------------------------------------------------------------------------------------------------------