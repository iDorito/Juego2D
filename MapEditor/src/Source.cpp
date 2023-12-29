#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "MouseTile.h"

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

	Grid grid(sf::Vector2i(10, 5),
			  sf::Vector2i(16, 16), 
			  sf::Vector2i(10,10), 
			  sf::Vector2f(0, 0), 
			  sf::Color(255, 255, 255, 128),
			  1); //thickness

	MouseTile mouseTile(grid);

	grid.Initialize(windowSize);
	mouseTile.Initialize();

	sf::Time deltaTimeCounter;
	float deltaTime;

	sf::Mouse mouse;
	sf::Vector2f mousePos;
	/*----------------------LOAD-START------------------------------*/
	grid.Load();
	mouseTile.Load();
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

		deltaTimeCounter = clock.restart();
		deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0f;
		
		mousePos = sf::Vector2f(mouse.getPosition(window));

		grid.Update(deltaTime);
		mouseTile.Update(deltaTime, mousePos);

		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Transparent);

		grid.Draw(window);
		mouseTile.Draw(window);

		window.display();
		/*-----------------------Draw-----------------------*/
	}
	return 0;
}