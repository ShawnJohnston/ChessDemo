#pragma once
#include "ImageManager.h"
#include "Game.h"
#include "Board.h"
#include "PieceSet.h"
#include <iostream>
using namespace sf;
using namespace std;

struct Render {
	ImageManager images_;

	Render();
	void RenderBoard();
};