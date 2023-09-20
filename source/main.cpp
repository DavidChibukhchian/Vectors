#include "common.h"
#include "coord_system.h"
#include "vectors.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "Vectors");
	
	sf::Image image; sf::Texture texture; sf::Sprite sprite;
	create_sprite(&image, &texture, &sprite);
	window.draw(sprite);

	Coord_System coord_system(200, 400, 35, sf::Color::Red);
	coord_system.draw(&window);


	Vec a(3, 4);
	Vec b(4, 5);
	Vec c = VecAdd(a, b);
	Vec d = VecMul(b, 2);
	
	
	
	window.display();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	return 0;
}