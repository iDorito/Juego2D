#include "Enemy.h"
#include <iostream>

void Enemy::Initialize()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Blue);
	boundingBox.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);

	health = 100;
	v_health.setString(std::to_string(health));
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


	boundingBox.setSize(sf::Vector2f((size.x - 34.0f ) * sprite.getScale().x , (size.y - 18)  * sprite.getScale().y));

	if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Arial.ttf - Font loaded!" << std::endl;
		v_health.setFont(font);
	}
	else {
		std::cout << "Font couldn't load..." << std::endl;
	}
}

void Enemy::Update(float& deltaTime)
{
	if (health > 0) {
		v_health.setPosition(getPosition() + sf::Vector2f(64.0f, 0.0f));
		boundingBox.setPosition(getPosition() + sf::Vector2f(50.0f, 46.0f));
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	if (health > 0) {
		window.draw(sprite);
		window.draw(boundingBox);
		window.draw(v_health);
	}
	
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

sf::RectangleShape Enemy::getBoundingBox()
{
	return boundingBox;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::reduceHealth(int dmg)
{
	if (health >= dmg) {
		health -= dmg;
		v_health.setString(std::to_string(health));
	}
	else {
		v_health.setString("Muerto");
	}

	std::cout << std::to_string(health) << std::endl;
}
