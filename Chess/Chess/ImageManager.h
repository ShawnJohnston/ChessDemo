#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using namespace sf;
using namespace std;

struct ImageManager {
	static map<string, Texture> images_;

	static Texture& getTexture(string ImageName);
	static void loadImage(string fileName);
	static void clear();
};