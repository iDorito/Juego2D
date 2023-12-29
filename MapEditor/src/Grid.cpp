#include "Grid.h"

Grid::Grid(
	const sf::Vector2i& totalCells,
	const sf::Vector2i& CellSize,
	const sf::Vector2i& scale,
	const sf::Vector2f& position,
	const sf::Color &color,
	const int& thickness) 
	:
	m_totalCells{totalCells}, m_cellSize{ CellSize },
	m_scale{ scale }, m_position{ position }, m_lineColor{color}, m_lineThickness {thickness}
{
	m_totalLines = sf::Vector2i(totalCells.x + 1, totalCells.y + 1);
	m_linesH = new sf::RectangleShape[m_totalLines.y];
	m_linesV = new sf::RectangleShape[m_totalLines.x];
}

Grid::~Grid()
{
	delete[] m_linesH;
	delete[] m_linesV;
}

void Grid::Initialize(sf::Vector2u windowSize)
{
	int lengthV = m_totalCells.y * m_cellSize.y * m_scale.y + m_lineThickness;
	int lengthH = m_totalCells.x * m_cellSize.x * m_scale.x;

	for (size_t v = 0; v < m_totalLines.x; v++)
	{
		m_linesV[v].setSize(sf::Vector2f(m_lineThickness, lengthV));
		m_linesV[v].setPosition(m_position + sf::Vector2f(v * m_cellSize.x * m_scale.x, 0));
		m_linesV[v].setFillColor(m_lineColor);
	}
	for (size_t h = 0; h < m_totalLines.y; h++)
	{
		m_linesH[h].setSize(sf::Vector2f(lengthH, m_lineThickness));
		m_linesH[h].setPosition(m_position + sf::Vector2f(0, h * m_cellSize.y * m_scale.y));
		m_linesH[h].setFillColor(m_lineColor);
	}
}

void Grid::Load()
{
}

void Grid::Update(const float& deltaTime)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_totalLines.x; i++)
	{
		window.draw(m_linesV[i]);
	}
	for (size_t i = 0; i < m_totalLines.y; i++)
	{
		window.draw(m_linesH[i]);
	}
}

sf::Vector2i Grid::get_m_scale()
{
	return m_scale;
}

sf::Vector2i Grid::get_m_cellSize() {
	return m_cellSize;
}