#include "common.h"
#include "coord_system.h"
#include "vectors.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "Vectors");

	sf::Image image; sf::Texture texture; sf::Sprite background;
	create_background(&image, &texture, &background);

	window.draw(background);



	Coord_System coord_system(500, 500, 35, sf::Color::Red);
	coord_system.draw(&window);

	//Vec c = VecSetByMouse(&window, coord_system);



	while (window.isOpen())
	{
		window.clear();
		window.draw(background);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		coord_system.draw(&window);

		//Vec a(-5,0);
		//a = 2 * a;
		//VecDraw(a, coord_system, &window, sf::Color::Green);

		//VecRotate(&c, 0.001);
		//VecDraw(c, coord_system, &window, sf::Color::Green);

		Vec a(3,3);
		VecDraw(a, coord_system, &window, sf::Color::Green);

		Vec b = -a;
		VecDraw(b, coord_system, &window, sf::Color::Green);

		Vec c(7,1);
		VecDraw(c, coord_system, &window, sf::Color::Green);

		Vec d = c + a;
		VecDraw(d, coord_system, &window, sf::Color::Black);

		Vec e = (-1) * d;
		VecDraw(e, coord_system, &window, sf::Color::Red);

		Vec f = e - b;
		VecDraw(f, coord_system, &window, sf::Color::Red);



		window.display();
	}

	return 0;
}