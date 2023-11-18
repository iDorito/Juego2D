#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace sf;

int main() {

	/*----------------------INITIALIZATION-START-----------------------*/
	/*Settings*/
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	/*Window*/
	int windowWidth = 800;
	int windowHeight = 600;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Juego RPG", Style::Default, settings);

	/*----------------------LOAD-START-----------------------*/
	Texture playerTexture;
	Sprite playerSprite;
	int xIndex = 0;
	int yIndex = 0;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
		cout << "Player texture loaded.";
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(IntRect(xIndex * 64, yIndex * 64, 64, 64));
	}
	else {
		cout << "Player texture failed to load...";
	}
	

	/*----------------------LOAD-END-----------------------*/

	//Main game loop
	while (window.isOpen()) {
		/*-----------------------Update-----------------------*/
		Event event;

		while (window.pollEvent(event)) {	
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		Vector2f position = playerSprite.getPosition();

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			playerSprite.setPosition(position - Vector2f(0, 0.2));
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			playerSprite.setPosition(position - Vector2f(0.2, 0));
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			playerSprite.setPosition(position + Vector2f(0, 0.2));
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			playerSprite.setPosition(position + Vector2f(0.2, 0));
		}

		/*-----------------------Update-----------------------*/

		/*-----------------------Draw-----------------------*/
		window.clear(Color::Black);
		window.draw(playerSprite);
		window.display();
		/*-----------------------Draw-----------------------*/
	}

	return 0;
}