#include "Map.h"
#include <iostream>

Map::Map() :
	tileWidth{ 16 }, tileHeight{ 16 }, totalTilesX{ 0 }, totalTilesY{ 0 }, tileScale{ 5.0 }, totalTiles{ 0 }
{
}

Map::~Map()
{
}

void Map::Initialize()
{

}

void Map::Load()
{
	if (tilesheetTexture.loadFromFile("Assets/World/Dungeon/tilesheet.png")) {
		totalTilesX = tilesheetTexture.getSize().x / tileWidth;
		totalTilesY = tilesheetTexture.getSize().y / tileWidth;

		totalTiles = totalTilesX * totalTilesY;

		tilesheetSprites = new Tile[totalTiles];
				

		for (size_t i{ 0 }; i < totalTilesY; i++) {
			for (size_t b{ 0 }; b < totalTilesX; b++) {

				int a = b + (i * totalTilesX);

				tilesheetSprites[a].id = a;
				tilesheetSprites[a].position = sf::Vector2i(b * tileWidth, i * tileHeight);

				//tilesheetSprites[a].sprite.setTexture(tilesheetTexture);
				//tilesheetSprites[a].sprite.scale(sf::Vector2f(tileScale, tileScale));
				//tilesheetSprites[a].sprite.setPosition(sf::Vector2f(b * tileWidth * tileScale, i * tileHeight * tileScale));
			}
		}
		std::cout << "Map texture loaded." << std::endl;
	}
	else {
		std::cout << "Map texture failed to load..." << std::endl;
	}

	for (size_t y = 0; y < 2; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			int i = x + y * 3;

			int index = mapPositions[i];

			newSprites[i].setTexture(tilesheetTexture);
			newSprites[i].setTextureRect(sf::IntRect(tilesheetSprites[index].position.x, tilesheetSprites[index].position.y, tileWidth, tileHeight));
			newSprites[i].setScale(sf::Vector2f(5.0, 5.0));
			newSprites[i].setPosition(sf::Vector2f(x * tileWidth * 5, y * tileHeight * 5));
		}
	}
}

void Map::Update(const float& deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 6; i++)
	{
		window.draw(newSprites[i]);
	}
	
}

