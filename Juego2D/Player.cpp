#include "Player.h"
#include <iostream>
#include "Gmath.h"

Player::Player() :
	playerSpeed{ 1.0f } {}

Player::~Player() {}

void Player::Initialize()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 0;
		std::cout << "Player texture loaded." << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.y, size.y));
		sprite.scale(sf::Vector2f(3.0, 3.0));
		sprite.setPosition(sf::Vector2f(850, 700.0));
	}
	else {
		std::cout << "Player texture failed to load..." << std::endl;
	}

	boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Player::Update(const float &deltaTime, Enemy &skeleton, sf::Vector2f &mousePos)
{
	//sf::Vector2f position = getPosition();

	//--------------------------------------MOVEMENT--------------------------------------//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(getPosition() - sf::Vector2f(0, 1) * playerSpeed * deltaTime / 2.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(getPosition() - sf::Vector2f(1, 0) * playerSpeed * deltaTime / 2.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(getPosition() + sf::Vector2f(0, 1) * playerSpeed * deltaTime / 2.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(getPosition() + sf::Vector2f(1, 0) * playerSpeed * deltaTime / 2.0f);
	}
	//--------------------------------------MOVEMENT--------------------------------------//

	//-----------------------------------AABB--------------------------------------
	boundingBox.setPosition(getPosition());
	if (Gmath::CheckBoxCollition(sprite.getGlobalBounds(), skeleton.getSprite().getGlobalBounds()))
	{
		std::cout << "Collition" << std::endl;
	}
	//-----------------------------------AABB--------------------------------------
}

void Player::Draw(sf::RenderWindow &window)
{

	window.draw(getSprite());
	window.draw(boundingBox);
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
