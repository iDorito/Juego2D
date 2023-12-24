#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture tilesheetTexture;
		Tile* tilesheetSprites;

	sf::Vector2f size;

	int tileWidth;
	int tileHeight;
	float tileScale;
	int totalTilesX;
	int totalTilesY;
	int totalTiles;

	int mapPositions[6] = {
		120, 121, 122,
		144, 145, 146
	};

	sf::Sprite newSprites[6];
public:
	Map();
	~Map();

	void Initialize();
	void Load(); 
	void Update(const float& deltaTime); 
	void Draw(sf::RenderWindow& window);

	
};

