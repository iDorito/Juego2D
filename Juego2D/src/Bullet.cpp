#include "Bullet.h"
#include "Player.h"
#include <iostream>
#include "Gmath.h"

Bullet::Bullet() :
	bulletSpeed{ 2.0f }, fireSpeed{ 10.0f }, gunTimer{ 0.0 }, bulletDamage{ 5 } {}

Bullet::~Bullet(){}
void Bullet::Initialize() {}
void Bullet::Load(){}

void Bullet::Update(const float& deltaTime, Enemy& skeleton, sf::Vector2f& mousePos, Player &player, sf::Vector2u windowSize)
{
	//-----------------------------------BULLETS--------------------------------------
	gunTimer += deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && gunTimer >= (1000.0f / fireSpeed)) {
		bullets.push_back(sf::CircleShape(15.0f));

		size_t i = bullets.size() - 1;
		bullets[i].setPosition(player.getPosition() + sf::Vector2f(64.0f, 0.0f));
		bullets[i].setOutlineColor(sf::Color::Magenta);
		bullets[i].setOutlineThickness(2);
		bulletDirection.push_back((mousePos - sf::Vector2f(bullets[i].getPosition())));
		//std::cout << "Bullet has been created." << std::endl;
		gunTimer = 0;
	}

	for (int i{ 0 }; i < bullets.size(); i++) {
		bullets[i].setPosition(bullets[i].getPosition() + Gmath::NormalizeVector(bulletDirection[i]) * bulletSpeed * deltaTime);

		sf::Vector2f bulletPos = bullets[i].getPosition();
		sf::FloatRect bulletBounds = bullets[i].getGlobalBounds();

		if (skeleton.getHealth() > 0) {
			if (Gmath::CheckBoxCollition(bullets[i].getGlobalBounds(), skeleton.getBoundingBox().getGlobalBounds()))
			{
				bullets.erase(bullets.begin() + i);
				bulletDirection.erase(bulletDirection.begin() + i);
				i--;
				skeleton.reduceHealth(bulletDamage);
			}
		}	
		if (bulletPos.x < 0 || bulletPos.y < 0 || bulletPos.x + bulletBounds.width > windowSize.x || bulletPos.y + bulletBounds.height > windowSize.y) {
			bullets.erase(bullets.begin() + i);
			bulletDirection.erase(bulletDirection.begin() + i);
			i--;
		}
	}
	
}

void Bullet::Draw(sf::RenderWindow& window)
{
	for (int i{ 0 }; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}