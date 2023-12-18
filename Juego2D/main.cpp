#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Gmath.h"
#include "Ginfo.h"

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

	Ginfo frameRate;
	frameRate.Initialize();

	Player player;
	player.Initialize();

	Enemy skeleton;
	skeleton.Initialize();

	/*----------------------LOAD-START------------------------------*/
	frameRate.Load();
	
	player.Load();
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

		sf::Time deltaTimeCounter = clock.restart();
		double deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0f;

		//FPS Counter-----
		frameRate.Update(deltaTime);
		//FPS Counter-----

		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton);
		
		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);

		player.Draw(window);
		skeleton.Draw(window);
		frameRate.Draw(window);

		window.display();
		/*-----------------------Draw-----------------------*/
	}
	return 0;
}