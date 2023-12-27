#include "MapLoader.h"
#include <fstream>
#include <string>


void MapLoader::Load(std::string filename, MapData &data)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			//std::cout << line << std::endl;
			
			if (!isMapValid) {
				if (line == "[Map]") {
					isMapValid = true;
					continue;
				}
				else {
					std::cout << "Map is not valid or has invalid syntax" << std::endl;
					break;
				}
			}
			
			if (isMapValid) {
				size_t index = line.find('=');

				std::string variable = line.substr(0, index);
				std::string value = line.substr(++index, line.length() - index);

				std::cout << variable << std::endl;
				std::cout << value << std::endl;

				if (variable == "version") {
					data.version = std::stoi(value);
				}
				else if (variable == "tileshet") {
					data.tileshet = value;
				}
				else if(variable == "name") {
					data.name = value;
				}
				else if (variable == "mapWidth") {
					data.mapWidth = std::stoi(value);
				}
				else if (variable == "mapHeight") {
					data.mapHeight = std::stoi(value);
				}
				else if (variable == "tileWidth") {
					data.tileWidth = std::stoi(value);
				}
				else if (variable == "tileHeight") {
					data.tileHeight = std::stoi(value);
				}
				else if (variable == "scaleX") {
					data.scaleX = std::stoi(value);
				}
				else if (variable == "scaleY") {
					data.scaleY = std::stoi(value);
				}
				else if (variable == "dataSize") {
					data.dataSize = std::stoi(value);
				}
				else if (variable == "data") {

					size_t count{ 0 };
					int offset{ 3 };
					data.data = new int[data.dataSize];

					for (size_t i = 0; i < data.dataSize; i++)
					{
						if (i == data.dataSize - 1) {
							count = value.find(',', count-offset);
							count += offset+1;
						}
						else {
							count = value.find(',', count);
						}

						std::string v = value.substr(count-offset, offset);
						count += offset;
						data.data[i] = std::stoi(v);
					}
				}
			}
		}
		std::cout << "AQUÍ PA" << std::endl;
		std::cout << "version: " << data.version << std::endl;
		std::cout << data.tileshet << std::endl;
		std::cout << data.name << std::endl;
		std::cout << data.tileWidth << std::endl;
		std::cout << data.tileHeight << std::endl;
		std::cout << data.scaleX << std::endl;
		std::cout << data.scaleY << std::endl;
		std::cout << data.dataSize << std::endl;
		
		for (size_t i = 0; i < data.dataSize; i++)
		{
			std::cout << data.data[i] << std::endl;
		}

		file.close();
		
	}
	else {
		std::cout << "Unable to open the file" << std::endl;
	}	
}

