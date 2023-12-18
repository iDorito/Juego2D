#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::RectangleShape boundingBox;

	sf::Vector2i size;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(float deltaTime); // <-- Called once per frame
	void Draw(sf::RenderWindow& window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();
};

