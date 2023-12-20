#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	int health;
	sf::Text v_health;

	sf::Font font;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i size;

	sf::RectangleShape boundingBox;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(float&deltaTime); // <-- Called once per frame
	void Draw(sf::RenderWindow& window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	sf::RectangleShape getBoundingBox();
	int getHealth();

	void reduceHealth(int dmg);

};

