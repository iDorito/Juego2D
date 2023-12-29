#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class MouseTile
{
private:
	sf::Texture m_tileSheet;
	sf::Sprite  m_tile;

	sf::Vector2i m_cellSize;
	sf::Vector2f m_tileScale;

public:
	MouseTile(Grid &grid);
	~MouseTile();

	void Initialize(); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float &deltatime,const sf::Vector2f &mousePos); // <-- Called once per frame
	void Draw(sf::RenderWindow& window); // <-- Called once once per frame
};

