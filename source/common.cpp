#include "common.h"

//---------------------------------------------------------------------------------------------------------------------

void create_background(sf::Image* image, sf::Texture* texture, sf::Sprite* sprite)
{
	image->create(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW, BACKGROUND_COLOR);

	texture->loadFromImage(*image);
	
	sprite->setTexture(*texture);
}

//---------------------------------------------------------------------------------------------------------------------