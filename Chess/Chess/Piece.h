#pragma once
#include <SFML/Graphics.hpp>
#include "ImageManager.h"
#include <string>
using namespace std;

class Piece {
	string _type;
	string _color;
	Sprite _sprite;
	int* _currentTile[2];
	bool _captured;

public:
	Piece();
	Piece(string type, string color, Sprite* sprite);

	void setType(string type);
	void setColor(string color);
	void setSprite(Sprite& sprite);
	void setCurrentTile(int x, int y);

	string& getType();
	string& getColor();
	Sprite& getSprite();
	int* getCurrentTile();


	bool isCaptured();
};

class King : public Piece {
};
class Queen : public Piece {
};
class Rook : public Piece {
};
class Bishop : public Piece {
};
class Knight : public Piece {
};
class Pawn : public Piece {
};