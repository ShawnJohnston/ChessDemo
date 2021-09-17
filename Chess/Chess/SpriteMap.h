#pragma once
#include <SFML/Graphics.hpp>
#include "ImageManager.h"
#include <map>
#include <string>
using namespace sf;
using namespace std;

struct SpriteMap {
	static map<string, Sprite> _sprites;
	static void initializeSprites();
};

