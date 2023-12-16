#include "Player.h"
#include <iostream>
#include "Gmath.h"

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

void Player::Update(Enemy &skeleton)
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bullets.push_back(sf::CircleShape(15.0f));

		int i = bullets.size() - 1;
		bullets[i].setPosition(getPosition());
		std::cout << "Bullet number: " << i << " has been created." << std::endl;
	}

	for (int i{ 0 }; i < bullets.size(); i++) {
		sf::Vector2f bulletDirection = skeleton.getPosition() - bullets[i].getPosition();
		bulletDirection = Gmath::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(getSprite());

	for (int i{ 0 }; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
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
