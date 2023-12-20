#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"

class Bullet
{
private:
	std::vector<sf::CircleShape> bullets;
	std::vector<sf::Vector2f> bulletDirection;

	float bulletSpeed;
	int bulletDamage;
	double gunTimer;
	float fireSpeed; //Bullets per second
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float& deltaTime, Enemy& skeleton, sf::Vector2f& mousePos, Player& player, sf::Vector2u windowSize); // <-- Called once per frame
	void Draw(sf::RenderWindow& window); // <-- Called once once per frame

	Bullet();
	~Bullet();
};

