#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"

sf::Vector2f NormalizeVector(sf::Vector2f vector) {

	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	
	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main() {
	/*----------------------INITIALIZATION-START-----------------------*/
	/*Settings*/
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 1920, windowHeight = 1080;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Juego RPG", sf::Style::Default, settings);
	/*----------------------INITIALIZATION-END-----------------------*/

	Player player;
	player.Initialize();

	Enemy skeleton;
	skeleton.Initialize();

	std::vector<sf::CircleShape> bullets;
	bullets.reserve(100);

	float bulletSpeed = 5.0f;

	//Mouse
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	/*----------------------LOAD-START-----------------------*/
	player.Load();
	skeleton.Load();
	
	/*----------------------LOAD-END-----------------------*/

	//Main game loop
	while (window.isOpen()) {
		/*-----------------------Update-----------------------*/
		sf::Event event;

		while (window.pollEvent(event)) {	
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		player.Update();
		skeleton.Update();
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bullets.push_back(sf::CircleShape(15.0f));

			int i = bullets.size() - 1;
			bullets[i].setPosition(player.getPosition());
			std::cout << "Bullet number: " << i << " has been created." << std::endl;
		}

		for (int i{ 0 }; i < bullets.size(); i++) {
			sf::Vector2f bulletDirection = skeleton.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);

		player.Draw(window);

		window.draw(skeleton.getSprite());

		for (int i{ 0 }; i < bullets.size(); i++) {
			window.draw(bullets[i]);
		}

		window.display();
		/*-----------------------Draw-----------------------*/
	}

	return 0;
}