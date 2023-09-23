#include "common.h"
#include "coord_system.h"
#include "vectors.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "Vectors");
	
	sf::Image image; sf::Texture texture; sf::Sprite background;
	create_background(&image, &texture, &background);	
	
	Vec b(8,1);

	while (window.isOpen())
	{
		window.clear();
		window.draw(background);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}


		Coord_System coord_system(500, 500, 35, sf::Color::Red);
		coord_system.draw(&window);

		Vec a(5,0);
		VecDraw(a, coord_system, &window, sf::Color::Green);

		VecRotate(&b, 0.001);
		VecDraw(b, coord_system, &window, sf::Color::Green);




		window.display();
	}

	return 0;
}