#include "common.h"
#include "coord_system.h"
#include "vectors.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "Vectors");

	sf::Image image; sf::Texture texture; sf::Sprite background;
	create_background(&image, &texture, &background);

	window.draw(background);



	Coord_System cs1(320,  420, 35, sf::Color::Red);
	cs1.draw(&window);

	Coord_System cs2(1000, 350, 12, sf::Color::Green);
	cs2.draw(&window);

	window.display();

	Vec vec1(1,5);
	Vec vec2(5,6);
	Vec vec_sum = vec1 + vec2;


	Vec c = VecSetByMouse(&window, cs1);



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



		cs1.draw(&window);
		cs2.draw(&window);

		VecDraw(vec1,    cs1, &window, sf::Color::Green);
		VecDraw(vec2,    cs1, &window, sf::Color::Green);
		VecDraw(vec_sum, cs1, &window, sf::Color::Yellow);

		VecDraw(vec1,    cs2, &window, sf::Color::Green);
		VecDraw(vec2,    cs2, &window, sf::Color::Green);
		VecDraw(vec_sum, cs2, &window, sf::Color::Yellow);

		VecRotate(&c, 0.001);
		VecDraw(c, cs1, &window, sf::Color::Red);
		VecDraw(c, cs2, &window, sf::Color::Red);



		window.display();
	}

	return 0;
}