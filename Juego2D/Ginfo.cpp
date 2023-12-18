#include "Ginfo.h"
#include <iostream>

Ginfo::Ginfo() :
	timer { 0 } 
{
	std::cout << "Ginfo object created." << std::endl;
}

Ginfo::~Ginfo()
{
	std::cout << "Ginfo object destroyed." << std::endl;
}

void Ginfo::Initialize()
{
}

void Ginfo::Load()
{
	if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Arial.ttf - Font loaded!" << std::endl;
		text.setFont(font);
	}
	else {
		std::cout << "Font couldn't load..." << std::endl;
	}
}

void Ginfo::Update(const double &deltaTime)
{
	timer += deltaTime;

	if (timer >= 100.0f) {
		double result = 1000.0f / deltaTime;
		text.setString("fps" + std::to_string((int)result) + " time: " + std::to_string(deltaTime) + "ms");
		timer = 0;
	}
	
}

void Ginfo::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
