#include "vectors.h"
#include "coord_system.h"

const unsigned int WIDTH  = 192*5;
const unsigned int HEIGHT = 108*5;

int main()
{
	sf::Image image;
	image.create(WIDTH, HEIGHT, sf::Color::Blue);

	sf::Texture background;
	background.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(background);


	Vec a(3, 4);
	Vec b(4, 5);
	Vec c = VecAdd(a, b);
	Vec d = VecMul(b, 2);


	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Vectors");

	Coord_System coord_system(50, 50, 10, sf::Color::Red);


	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	
		coord_system.draw(&window);







		window.display();
	}

	return 0;
}