#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 2;
		std::cout << "Enemy texture loaded." << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3.0, 3.0));
		sprite.setPosition(sf::Vector2f(850, 50.0));
	}
	else {
		std::cout << "Failed to load enemy." << std::endl;
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

sf::Vector2f Enemy::getPosition()
{
	sf::Vector2f position = sprite.getPosition();
	return position;
}

sf::Sprite Enemy::getSprite()
{
	return sprite;
}
