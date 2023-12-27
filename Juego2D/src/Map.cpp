#include "Map.h"
#include <iostream>
#include "MapLoader.h"
#include "MapData.h"

Map::Map() :
	tilesheetSprites{ nullptr }, totalTilesX{ 0 }, totalTilesY{ 0 }, totalTiles{ 0 }, mdSize {0} {}

Map::~Map(){}

void Map::Initialize(){}

void Map::Load()
{
	MapLoader mapLoader;
	MapData md;
	mapLoader.Load("assets/maps/Level1.rmap", md);
	newSprites = new sf::Sprite[md.dataSize];
	mdSize = md.dataSize;

	if (tilesheetTexture.loadFromFile(md.tileshet)) {
		totalTilesX = tilesheetTexture.getSize().x / md.tileWidth;
		totalTilesY = tilesheetTexture.getSize().y / md.tileWidth;

		totalTiles = totalTilesX * totalTilesY;

		tilesheetSprites = new Tile[totalTiles];

		for (int i{ 0 }; i < totalTilesY; i++) {
			for (int b{ 0 }; b < totalTilesX; b++) {

				int a = b + (i * totalTilesX);

				tilesheetSprites[a].id = a;
				tilesheetSprites[a].position = sf::Vector2i(b * md.tileWidth, i * md.tileHeight);
			}
		}
		std::cout << "Map texture loaded." << std::endl;
	}
	else {
		std::cout << "Map texture failed to load..." << std::endl;
	}

	for (unsigned y = 0; y < md.mapHeight; y++)
	{
		for (unsigned x = 0; x < md.mapWidth; x++)
		{
			unsigned i = x + y * md.mapWidth;

			unsigned index = md.data[i];
			

			newSprites[i].setTexture(tilesheetTexture);
			newSprites[i].setTextureRect(sf::IntRect(tilesheetSprites[index].position.x, tilesheetSprites[index].position.y, md.tileWidth, md.tileHeight));
			newSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
			newSprites[i].setPosition(sf::Vector2f(x * md.tileWidth * newSprites[i].getScale().x, y * md.tileHeight * newSprites[i].getScale().y));
		}
	}
}

void Map::Update(const float& deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mdSize; i++)
	{
		window.draw(newSprites[i]);
	}
	
}

