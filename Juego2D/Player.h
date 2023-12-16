#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::vector<sf::CircleShape> bullets;
	float bulletSpeed = 5.0f;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(Enemy& skeleton); // <-- Called once per frame
	void Draw(sf::RenderWindow &window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();
};

