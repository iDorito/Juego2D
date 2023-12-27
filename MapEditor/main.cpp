#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	/*----------------------INITIALIZATION-START---------------------*/
	/*Settings*/
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 1920, windowHeight = 1080;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Map Editor", sf::Style::Default, settings);
	sf::Vector2u windowSize{ window.getSize().x, window.getSize().y };
	window.setFramerateLimit(240);
	/*----------------------INITIALIZATION-END-----------------------*/
	sf::Mouse mouse;

	/*----------------------LOAD-START------------------------------*/

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

		sf::Vector2f mousePos = sf::Vector2f(mouse.getPosition(window));

		sf::Time deltaTimeCounter = clock.restart();
		float deltaTime = deltaTimeCounter.asMicroseconds() / 1000.0f;

		//FPS Counter-----

		//FPS Counter-----



		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(sf::Color::Black);



		window.display();
		/*-----------------------Draw-----------------------*/
	}
	return 0;
}