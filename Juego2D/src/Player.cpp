#include "Player.h"
#include <iostream>
#include "Gmath.h"

Player::Player() :
	playerSpeed{ 2.0f } {}

Player::~Player() {}

void Player::Initialize()
{
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1);

	size = sf::Vector2i(32, 32);
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/ranger.png")) {
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

	boundingBox.setSize(sf::Vector2f((size.x) * sprite.getScale().x, (size.y) * sprite.getScale().y));

}

void Player::Update(const float &deltaTime, Enemy &skeleton, sf::Vector2f &mousePos, sf::Vector2u windowSize)
{
	
	sf::FloatRect bbSize = boundingBox.getGlobalBounds();
	sf::Vector2f movement(0.f, 0.f);
	const sf::Vector2f directions[] = { sf::Vector2f(0, -1), sf::Vector2f(-1, 0), sf::Vector2f(0, 1), sf::Vector2f(1, 0) };

	//--------------------------------------MOVEMENT--------------------------------------//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && bbSize.top >= 0) {
		movement.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && bbSize.left >= 0) {
		movement.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (bbSize.top + bbSize.height) <= windowSize.y) 
	{
		movement.y += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (bbSize.left + bbSize.width) <= windowSize.x) 
	{
		movement.x += 1.f;
	}
	if (movement != sf::Vector2f(0.f, 0.f)) {
		movement = playerSpeed * deltaTime / 2.0f * Gmath::NormalizeVector(movement);
		sprite.setPosition(getPosition() + movement);
	}
	//--------------------------------------MOVEMENT--------------------------------------//

	//-----------------------------------AABB--------------------------------------
	boundingBox.setPosition(getPosition());// + sf::Vector2f(50.0f, 46.0f));
	if (Gmath::CheckBoxCollition(boundingBox.getGlobalBounds(), skeleton.getBoundingBox().getGlobalBounds()))
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

sf::Vector2f Player::getPosition() { return sf::Vector2f(sprite.getPosition());}

sf::Sprite Player::getSprite(){	return sprite; }

sf::RectangleShape Player::getBoundingBox(){ return boundingBox;}