#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Blue);
	boundingBox.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 2;
		std::cout << "Enemy texture loaded." << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.y, size.y));
		sprite.scale(sf::Vector2f(3.0, 3.0));
		sprite.setPosition(sf::Vector2f(850, 50.0));
	}
	else {
		std::cout << "Failed to load enemy." << std::endl;
	}
	boundingBox.setSize(
		sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Enemy::Update(float deltaTime)
{
	boundingBox.setPosition(getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingBox);
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
