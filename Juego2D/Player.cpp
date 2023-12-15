#include "Player.h"
#include <iostream>

void Player::Initialize()
{
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 0;
		std::cout << "Player texture loaded." << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3.0, 3.0));
	}
	else {
		std::cout << "Player texture failed to load..." << std::endl;
	}
}

void Player::Update()
{
	//sf::Vector2f position = getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(getPosition() - sf::Vector2f(0, 0.1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(getPosition() - sf::Vector2f(0.1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(getPosition() + sf::Vector2f(0, 0.1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(getPosition() + sf::Vector2f(0.1, 0));
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(getSprite());
}

sf::Vector2f Player::getPosition()
{
	sf::Vector2f position = sprite.getPosition();
	return position;
}

sf::Sprite Player::getSprite()
{
	return sprite;
}
