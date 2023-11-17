#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace sf;

int main() {

	/*----------------------INITIALIZATION-----------------------*/
	/*Settings*/
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 1920;
	int windowHeight = 1080;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Juego RPG", Style::Default, settings);

	/*CircleShape*/
	sf::CircleShape circulo(50.f, 10);
	circulo.setFillColor(Color(255, 0, 255));
	circulo.setPosition(windowWidth / 2 - (circulo.getRadius()), windowHeight / 2 - (circulo.getRadius()));
	circulo.setOutlineThickness(5);
	circulo.setOutlineColor(Color::Cyan);

	/*Rectangle*/
	RectangleShape rectangulo(sf::Vector2f(50, 4));
	rectangulo.setPosition(50, 50);
	rectangulo.setOutlineThickness(5);
	rectangulo.setOutlineColor(Color::Green);

	/*----------------------INITIALIZATION-----------------------*/

	//Main game loop
	while (window.isOpen()) {
		/*-----------------------Update-----------------------*/
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(Color::Black);
		window.draw(circulo);
		window.draw(rectangulo);
		window.display();
		/*-----------------------Draw-----------------------*/
	}

	return 0;
}