#include "Map.h"
#include <iostream>

Map::Map() :
	tileWidth{16}, tileHeight{16}, totalTilesX{0}, totalTilesY{0}, tileScale{5.0}
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

		int count{ 0 };
		for (size_t i{ 0 }; i < 12; i++) {
			for (size_t b{ 0 }; b < 24; b++) {
				tilesheetSprites[count].setTexture(tilesheetTexture);
				tilesheetSprites[count].setTextureRect(sf::IntRect(b * tileWidth, i * tileHeight, tileWidth, tileHeight));
				tilesheetSprites[count].scale(sf::Vector2f(tileScale, tileScale));
				tilesheetSprites[count].setPosition(sf::Vector2f(b * tileWidth * tileScale, i * tileHeight * tileScale));
				count++;
			}
		}
		std::cout << "Map texture loaded." << std::endl;
	}
	else {
		std::cout << "Map texture failed to load..." << std::endl;
	}
}

void Map::Update(const float& deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (auto sprite : tilesheetSprites) {
		window.draw(sprite);
	}
	
}

