#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(Grid& grid)
	:	
	m_cellSize{grid.get_m_cellSize()},
	m_tileScale{grid.get_m_scale()}
{}

MouseTile::~MouseTile(){}


void MouseTile::Initialize(){}

void MouseTile::Load()
{
	int tileNumber{ 11 };

	if (m_tileSheet.loadFromFile("assets/world/dungeon/tilesheet.png")) {
		m_tile.setTexture(m_tileSheet);
		m_tile.setTextureRect(sf::IntRect(tileNumber * m_cellSize.x, 0, m_cellSize.x, m_cellSize.y));
		m_tile.setScale(sf::Vector2f(m_tileScale.x, m_tileScale.y));
	}
	else {
		std::cout << "Failed to load" << std::endl;
	}
}

void MouseTile::Update(const float& deltatime, const sf::Vector2f &mousePos)
{
	int x = (int)(mousePos.x / (m_cellSize.x * m_tile.getScale().x));
	int xToTile = x * (m_cellSize.x * m_tile.getScale().x);

	int y = mousePos.y / (m_cellSize.y * m_tile.getScale().y);
	int yToTile = y * (m_cellSize.y * m_tile.getScale().y);

	sf::Vector2f mouseInGrid = sf::Vector2f(xToTile, yToTile);

	m_tile.setPosition(mouseInGrid);
}

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}
