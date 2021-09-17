#pragma once
#include "Game.h"
#include "PieceSet.h"
#include "ImageManager.h"
#include <vector>

class Board {
	static Sprite _sprite;

	static PieceSet* _whiteSet;
	static PieceSet* _blackSet;
	
	Board();
public:
	static Sprite* _tiles[8][8];

	static void initialize();
	static void initializeBoard();
	static void initializeTiles();
	static void initializePieces();
	static Sprite& getSprite();
	static vector<Piece*>& getWhitePieces();
	static vector<Piece*>& getBlackPieces();
};

