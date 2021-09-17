#pragma once
#include <SFML/Graphics.hpp>
#include "Controls.h"
#include "ImageManager.h"
#include "Render.h"
#include "Board.h"
#include <iostream>

using namespace sf;
using namespace std;

class Game {
private:
	static RenderWindow* window_;
	static VideoMode videoMode_;
	Event event_;

	static Vector2i mousePositionWindow_;
	static Vector2f mousePositionView_;

	static float _xScale;
	static float _yScale;
	
	void initializeVariables();
	void initializeWindow();
	void pollEvents();
	void updateMousePositions();

public:
	Game();
	~Game();

	static void setXScale(float x);
	static void setYScale(float y);

	static RenderWindow& getWindow();
	static VideoMode& getVideoMode();
	static float getXScale();
	static float getYScale();
	static Vector2i& getMousePositionWindow();
	static Vector2f& getMousePositionView();

	void start();
	void update();
	void render();
	const bool isRunning() const;
};

