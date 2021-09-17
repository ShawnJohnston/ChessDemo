#pragma once
#include "Piece.h"
#include "ImageManager.h"
#include "SpriteMap.h"
#include <iostream>

class PieceSet {
	const unsigned int _TOTAL_SIZE = 16;
	const unsigned int _ROW_SIZE = 8;

	int _blackPiecesCount;
	int _whitePiecesCount;
	
	string _color;
	vector<Piece*> _pieces;

	void initializePiece(string typeString, int typeEnum, string color);
	void initializeSet(string color);
	
	PieceSet();

public:
	PieceSet(string color);

	void setColor(string color);
	string& getColor();
	unsigned int getTotalSize();
	unsigned int getRowSize();
	unsigned int getPieceCount();
	Piece*& getPiece(int index);
	vector<Piece*>& getPieces();
};

