#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Gmath.h"
#include "Ginfo.h"
#include "Bullet.h"

int main() {
	/*----------------------INITIALIZATION-START---------------------*/
	/*Settings*/
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 1920, windowHeight = 1080;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Juego RPG", sf::Style::Default, settings);
	window.setFramerateLimit(240);
	/*----------------------INITIALIZATION-END-----------------------*/
	sf::Mouse mouse;

	Bullet bullet;
	bullet.Initialize();

	Ginfo frameRate;
	frameRate.Initialize();

	Player player;
	player.Initialize();

	Enemy skeleton;
	skeleton.Initialize();

	/*----------------------LOAD-START------------------------------*/
	frameRate.Load();
	
	player.Load();
	bullet.Load();
	skeleton.Load();
	/*----------------------LOAD-END--------------------------------*/

	//----------------------Main game loop--------------------------
	sf::Clock clock;

	while (window.isOpen()) {

		/*-----------------------Update-----------------------------*/
		sf::Event event;

		while (window.pollEvent(event)) {	
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Vector2f mousePos = sf::Vector2f(mouse.getPosition());

		sf::Time deltaTimeCounter = clock.restart();
		float deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0f;

		//FPS Counter-----
		frameRate.Update(deltaTime);
		//FPS Counter-----

		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton, mousePos);
		bullet.Update(deltaTime, skeleton, mousePos, player);
		
		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);

		player.Draw(window);
		bullet.Draw(window);
		skeleton.Draw(window);
		frameRate.Draw(window);

		window.display();
		/*-----------------------Draw-----------------------*/
	}
	return 0;
}