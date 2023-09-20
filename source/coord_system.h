#include <SFML\Graphics.hpp>
#include <limits>

//---------------------------------------------------------------------------------------------------------------------

class Coord_System
{
	public:

	double x0;
	double y0;
	double base_len;
	sf::Color color;

	void draw(sf::RenderWindow* window);

	Coord_System(double x0, double y0, double len, sf::Color color);
	~Coord_System();
};

//---------------------------------------------------------------------------------------------------------------------