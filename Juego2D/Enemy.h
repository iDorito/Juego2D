#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(); // <-- Called once per frame
	void Draw(); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();
};
