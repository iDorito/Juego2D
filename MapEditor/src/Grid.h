#pragma once
#include <SFML/Graphics.hpp>



class Grid
{
private:
	sf::RectangleShape *m_linesV;
	sf::RectangleShape *m_linesH;

	sf::Vector2i m_cellSize;
	sf::Vector2i m_totalCells;
	sf::Vector2i m_totalLines;
	sf::Vector2i m_scale;
	sf::Vector2f m_position;
	sf::Color m_lineColor;

	int m_lineThickness;

public:
	Grid(const sf::Vector2i& totalCells,
		const sf::Vector2i& CellSize,
		const sf::Vector2i& scale,
		const sf::Vector2f& position,
		const sf::Color& color,
		const int& thickness);
	~Grid();

	void Initialize(sf::Vector2u windowSize); // <-- Called once
	void Load(); // <-- Called once per app start
	void Update(const float& deltaTime); // <-- Called once per frame
	void Draw(sf::RenderWindow& window); // <-- Called once once per frame

	sf::Vector2i get_m_scale();
	sf::Vector2i get_m_cellSize();
};

