#pragma once
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(); // <-- Called once per frame
	void Draw(sf::RenderWindow &window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();
};

