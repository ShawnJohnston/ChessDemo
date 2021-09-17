#pragma once
#include <SFML/Graphics.hpp>
#include "ImageManager.h"
//#include "Render.h"
#include "Game.h"
using namespace sf;

struct Controls {
	void windowClosedCheck(Event& event);
	void escapeKeyCheck(Event& event);
	void leftMouseClickCheck(Event& event, Vector2f& position);
	void rightMouseClickCheck(Event& event, Vector2f& position);

	void pieceClickCheck(Event& event, Vector2f& position);
};

