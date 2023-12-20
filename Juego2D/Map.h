#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture tilesheetTexture;
	sf::Sprite tilesheetSprites[288];

	sf::Vector2f size;

	int tileWidth;
	int tileHeight;
	float tileScale;
	int totalTilesX;
	int totalTilesY;
public:
	Map();
	~Map();

	void Initialize();
	void Load(); 
	void Update(const float& deltaTime); 
	void Draw(sf::RenderWindow& window);

	
};

