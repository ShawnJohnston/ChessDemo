#include "PieceSet.h"

PieceSet::PieceSet() {
	int _blackPiecesCount = 16;
	int _whitePiecesCount = 16;
}
PieceSet::PieceSet(string color) {
	int _blackPiecesCount = 16;
	int _whitePiecesCount = 16;
	_color = color;
	initializeSet(color);
}

void PieceSet::setColor(string color) {
	_color = color;
	for (Piece* piece : _pieces) {
		piece->setColor(color);
	}
}
string& PieceSet::getColor() {
	return _color;
}
unsigned int PieceSet::getTotalSize() {
	return _TOTAL_SIZE;
}
unsigned int PieceSet::getRowSize() {
	return _ROW_SIZE;
}
unsigned int PieceSet::getPieceCount() {
	return _pieces.size();
}
Piece*& PieceSet::getPiece(int index) {
	return _pieces.at(index);
}
vector<Piece*>& PieceSet::getPieces() {
	return _pieces;
}

void PieceSet::initializePiece(string typeString, int typeEnum, string color) {
	Sprite* sprite = new Sprite;
	sprite->setTexture(ImageManager::getTexture(typeString + color));
	
	Piece* piece = nullptr;
	switch (typeEnum) {
	case 0:
		piece = new King;
		break;
	case 1:
		piece = new Queen;
		break;
	case 2:
		piece = new Rook;
		break;
	case 3:
		piece = new Bishop;
		break;
	case 4:
		piece = new Knight;
		break;
	case 5:
		piece = new Pawn;
		break;
	}
	
	piece->setType(typeString);
	piece->setColor(color);
	piece->setSprite(*sprite);
	_pieces.push_back(piece);
}
void PieceSet::initializeSet(string color) {
	for (unsigned int i = 0; i < _TOTAL_SIZE; i++) {
		enum pieces { king = 0, queen = 1, rook = 2, bishop = 3, knight = 4, pawn = 5 };
		int typeEnum = 0;
		string typeString;
		if (i < _ROW_SIZE) {
			typeEnum = pieces::pawn;
			typeString = "pawn";
		}
		else if (i == 8 || i == 15) {
			typeEnum = pieces::rook;
			typeString = "rook";
		}
		else if (i == 9 || i == 14) {
			typeEnum = pieces::knight;
			typeString = "knight";
		}
		else if (i == 10 || i == 13) {
			typeEnum = pieces::bishop;
			typeString = "bishop";
		}
		else if (i == 11) {
			typeEnum = pieces::queen;
			typeString = "queen";
		}
		else if (i == 12) {
			typeEnum = pieces::king;
			typeString = "king";
		}
		initializePiece(typeString, typeEnum, color);
	}
}
