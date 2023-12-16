#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main() {
	/*----------------------INITIALIZATION-START---------------------*/
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

	//Mouse------------------------------------------------------------
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	/*----------------------LOAD-START------------------------------*/
	player.Load();
	skeleton.Load();
	
	/*----------------------LOAD-END--------------------------------*/

	//Main game loop
	while (window.isOpen()) {
		/*-----------------------Update-----------------------------*/
		sf::Event event;

		while (window.pollEvent(event)) {	
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		skeleton.Update();
		player.Update(skeleton);
		
		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);

		player.Draw(window);
		skeleton.Draw(window);

		window.display();
		/*-----------------------Draw-----------------------*/
	}

	return 0;
}