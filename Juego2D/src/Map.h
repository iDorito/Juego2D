#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture tilesheetTexture;

	Tile* tilesheetSprites;

	sf::Vector2f size;

	int totalTilesX;
	int totalTilesY;
	int totalTiles;

	int mdSize;

	sf::Sprite *newSprites;
public:
	Map();
	~Map();

	void Initialize();
	void Load(); 
	void Update(const float& deltaTime); 
	void Draw(sf::RenderWindow& window);	
};

