#ifndef _COMMON_H
#define _COMMON_H

//---------------------------------------------------------------------------------------------------------------------

#include <SFML\Graphics.hpp>

//---------------------------------------------------------------------------------------------------------------------

const unsigned int  WIDTH_OF_WINDOW = 192*7;
const unsigned int HEIGHT_OF_WINDOW = 108*7;
const double                 RADIUS = 2.0;
const sf::Color    BACKGROUND_COLOR = sf::Color::Blue;
const double             MULTIPLIER = 10.0;

//---------------------------------------------------------------------------------------------------------------------

void create_background(sf::Image* image, sf::Texture* texture, sf::Sprite* sprite);

//---------------------------------------------------------------------------------------------------------------------

#endif // _COMMON_H