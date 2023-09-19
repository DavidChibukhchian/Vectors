#include <SFML\Graphics.hpp>
#include <limits>

//---------------------------------------------------------------------------------------------------------------------

class Coord_System
{
	public:

	double x0_position;
	double y0_position;
	double base_length;
	sf::Color color;

	void draw(sf::RenderWindow* window);

	Coord_System(double x0, double y0, double length, sf::Color color);
	~Coord_System();
};

//---------------------------------------------------------------------------------------------------------------------