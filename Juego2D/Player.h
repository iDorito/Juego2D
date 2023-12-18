#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::CircleShape> bullets;
	float bulletSpeed;
	float playerSpeed;
	double gunTimer{0};
	float fireSpeed{ 5 }; //Bullets per second

	sf::RectangleShape boundingBox;
	
	sf::Vector2i size;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float &deltaTime, Enemy& skeleton); // <-- Called once per frame
	void Draw(sf::RenderWindow &window); // <-- Called once once per frame

	sf::Vector2f getPosition();
	sf::Sprite getSprite();

	Player();
	~Player();
};

