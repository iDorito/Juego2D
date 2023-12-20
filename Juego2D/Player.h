#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float playerSpeed;
	sf::RectangleShape boundingBox;
	sf::Vector2i size;

public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float &deltaTime, Enemy &skeleton, sf::Vector2f& mousePos, sf::Vector2u windowSize); // <-- Called once per frame
	void Draw(sf::RenderWindow &window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	inline sf::Sprite getSprite();
	sf::RectangleShape getBoundingBox();

	sf::Vector2f move(sf::Vector2f& coords, const float& deltaTime);

	Player();
	~Player();
};

