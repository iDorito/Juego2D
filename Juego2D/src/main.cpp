#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Gmath.h"
#include "Ginfo.h"
#include "Bullet.h"
#include "Map.h"
#include "MapLoader.h"

int main() {
	/*----------------------INITIALIZATION-START---------------------*/
	/*Settings*/
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 1920, windowHeight = 1080;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Juego RPG", sf::Style::Default, settings);
	sf::Vector2u windowSize{ window.getSize().x, window.getSize().y };
	window.setFramerateLimit(240);
	/*----------------------INITIALIZATION-END-----------------------*/
	sf::Time deltaTimeCounter;
	float deltaTime;

	sf::Mouse mouse;
	sf::Vector2f mousePos;

	Map map;
	map.Initialize();

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
	map.Load();

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

		mousePos = sf::Vector2f(mouse.getPosition(window));

		deltaTimeCounter = clock.restart();
		deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0f;
		
		frameRate.Update(deltaTime);//FPS Counter-----

		map.Update(deltaTime);
		skeleton.Update(deltaTime);
		player.Update(deltaTime, skeleton, mousePos, windowSize);
		bullet.Update(deltaTime, skeleton, mousePos, player, windowSize);

		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Transparent);

		map.Draw(window);
		
		player.Draw(window);
		bullet.Draw(window);
		skeleton.Draw(window);
		frameRate.Draw(window);

		window.display();
		/*-----------------------Draw-----------------------*/
	}
	return 0;
}