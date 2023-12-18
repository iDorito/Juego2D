#include "Player.h"
#include <iostream>
#include "Gmath.h"

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
		sprite.scale(sf::Vector2f(1.0, 1.0));
	}
	else {
		std::cout << "Player texture failed to load..." << std::endl;
	}
	boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Player::Update(float deltaTime, Enemy &skeleton)
{
	//sf::Vector2f position = getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.setPosition(getPosition() - sf::Vector2f(0, 0.1) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.setPosition(getPosition() - sf::Vector2f(0.1, 0) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.setPosition(getPosition() + sf::Vector2f(0, 0.1) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.setPosition(getPosition() + sf::Vector2f(0.1, 0) * playerSpeed * deltaTime);
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
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
	}

	boundingBox.setPosition(getPosition());

	if (Gmath::CheckBoxCollition(sprite.getGlobalBounds(), skeleton.getSprite().getGlobalBounds()))
	{
		std::cout << "Collition" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(getSprite());
	window.draw(boundingBox);

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