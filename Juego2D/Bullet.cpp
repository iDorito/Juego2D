#include "Bullet.h"
#include "Player.h"
#include <iostream>
#include "Gmath.h"

Bullet::Bullet() :
	bulletSpeed{ 1.0f }, fireSpeed{ 10.0f }, gunTimer{ 0.0 }, bulletDamage{ 5 } {}

Bullet::~Bullet(){}
void Bullet::Initialize() {}
void Bullet::Load(){}

void Bullet::Update(const float& deltaTime, Enemy& skeleton, sf::Vector2f& mousePos, Player &player)
{
	//-----------------------------------BULLETS--------------------------------------
	gunTimer += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gunTimer >= (1000.0f / fireSpeed)) {
		bullets.push_back(sf::CircleShape(15.0f));

		int i = bullets.size() - 1;
		bullets[i].setPosition(player.getPosition() + sf::Vector2f(64.0f, 0.0f));
		bullets[i].setOutlineColor(sf::Color::Magenta);
		bullets[i].setOutlineThickness(2);
		bulletDirection.push_back((mousePos - sf::Vector2f(bullets[i].getPosition())));
		//std::cout << "Bullet has been created." << std::endl;
		gunTimer = 0;
	}

	for (int i{ 0 }; i < bullets.size(); i++) {
		bullets[i].setPosition(bullets[i].getPosition() + Gmath::NormalizeVector(bulletDirection[i]) * bulletSpeed * deltaTime);

		if (skeleton.getHealth() > 0) {
			if (Gmath::CheckBoxCollition(bullets[i].getGlobalBounds(), skeleton.getSprite().getGlobalBounds()))
			{
				std::cout << "Bullet collition, bullet destroyed" << std::endl;
				bullets.erase(bullets.begin() + i);
				bulletDirection.erase(bulletDirection.begin() + i);
				i--;

				skeleton.reduceHealth(bulletDamage);
			}
		}
	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	for (int i{ 0 }; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}