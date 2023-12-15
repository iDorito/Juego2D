#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#include <math.h>

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
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Juego RPG", sf::Style::Fullscreen, settings);
	/*----------------------INITIALIZATION-END-----------------------*/

	std::vector<sf::CircleShape> bullets;
	bullets.reserve(100);

	float bulletSpeed = 5.0f;

	//Mouse
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	

	/*----------------------LOAD-START-----------------------*/

	/*ENEMY-----------------------*/
	sf::Texture enemyTexture;
	sf::Sprite  enemySprite; 

	if (enemyTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 2;
		std::cout << "Enemy texture loaded." << std::endl;
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		enemySprite.scale(sf::Vector2f(3.0, 3.0));
		enemySprite.setPosition(sf::Vector2f(850, 50.0)); 
	}
	else {
		std::cout << "Failed to load enemy." << std::endl;
	}

	/*PLAYER-----------------------*/
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
		int xIndex = 0;
		int yIndex = 0;
		std::cout << "Player texture loaded." << std::endl;
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		playerSprite.scale(sf::Vector2f(3.0, 3.0));
	}
	else {
		std::cout << "Player texture failed to load..." << std::endl;
	}
	

	/*----------------------LOAD-END-----------------------*/

	/*BULLET DIRECTION-----------------------*/
	

	//Main game loop
	while (window.isOpen()) {
		/*-----------------------Update-----------------------*/
		sf::Event event;

		while (window.pollEvent(event)) {	
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerSprite.setPosition(playerSprite.getPosition() - sf::Vector2f(0, 0.1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerSprite.setPosition(playerSprite.getPosition() - sf::Vector2f(0.1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(0, 0.1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(0.1, 0));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bullets.push_back(sf::CircleShape(15.0f));

			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
		}

		for (int i{ 0 }; i < bullets.size(); i++) {
			sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}

		

		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(enemySprite);

		for (int i{ 0 }; i < bullets.size(); i++) {
			window.draw(bullets[i]);
		}

		window.display();
		/*-----------------------Draw-----------------------*/
	}

	return 0;
}