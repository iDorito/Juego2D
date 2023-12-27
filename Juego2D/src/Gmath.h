#pragma once
#include "SFML/Graphics.hpp"

class Gmath
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool CheckBoxCollition(sf::FloatRect rect1, sf::FloatRect rect2);
};

