#pragma once
#include <SFML/Graphics.hpp>

class Ginfo
{
private:
	sf::Text text;
	sf::Font font;

	double timer;
public:
	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float &deltaTime); // <-- Called once per frame
	void Draw(sf::RenderWindow& window);

	Ginfo();
	~Ginfo();
};

