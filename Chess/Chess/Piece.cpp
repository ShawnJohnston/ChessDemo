#include "Piece.h"

Piece::Piece() {
	_captured = false;
}
Piece::Piece(string type, string color, Sprite* sprite) {
	_type = type;
	_color = color;
	_sprite = *sprite;
	_captured = false;
}

void Piece::setType(string type) {
	_type = type;
}
void Piece::setColor(string color) {
	_color = color;
}
void Piece::setSprite(Sprite& sprite) {
	_sprite = sprite;
}
void Piece::setCurrentTile(int x, int y) {
	_currentTile[0] = &x;
	_currentTile[1] = &y;
}

string& Piece::getType() {
	return _type;
}
string& Piece::getColor() {
	return _color;
}
Sprite& Piece::getSprite() {
	return _sprite;
}
int* Piece::getCurrentTile() {
	return *_currentTile;
}

bool Piece::isCaptured() {
	if (_captured) {
		return true;
	}
	return false;
}