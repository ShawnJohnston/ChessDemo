#include "Board.h"

Sprite Board::_sprite;
PieceSet* Board::_whiteSet;
PieceSet* Board::_blackSet;
Sprite* Board::_tiles[8][8];

Board::Board() {
	initializeBoard();
	initializeTiles();
	initializePieces();
}
void Board::initialize() {
	initializeBoard();
	initializeTiles();
	initializePieces();
}
void Board::initializeBoard() {
	Game::setXScale(1.5);
	Game::setYScale(1.5);

	_sprite.setTexture(ImageManager::getTexture("board"));
	_sprite.scale(Game::getXScale(), Game::getYScale());
	_sprite.setPosition(Game::getWindow().getSize().x / 8, 0);
}
void Board::initializeTiles() {
	const float constant = 21;
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			_tiles[i][j] = new Sprite;
			if (i % 2 == 0 && j % 2 == 0) {
				_tiles[i][j]->setTexture(ImageManager::getTexture("squareW"));
			}
			else if (i % 2 == 0 && j % 2 != 0) {
				_tiles[i][j]->setTexture(ImageManager::getTexture("squareB"));
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				_tiles[i][j]->setTexture(ImageManager::getTexture("squareB"));
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				_tiles[i][j]->setTexture(ImageManager::getTexture("squareW"));
			}
			_tiles[i][j]->setScale(Game::getXScale() + .025, Game::getYScale() + .025);
			_tiles[i][j]->setPosition(
				_sprite.getPosition().x + (constant + (_tiles[0][0]->getGlobalBounds().width * i)),
				_sprite.getPosition().y + constant + (_tiles[0][0]->getGlobalBounds().height * j));
		}
	}
}
void Board::initializePieces() {
	_whiteSet = new PieceSet("W");
	_blackSet = new PieceSet("B");
	for (unsigned int i = 0; i < _whiteSet->getTotalSize(); i++) {
		_blackSet->getPiece(i)->getSprite().scale(Game::getXScale(), Game::getYScale());
		_whiteSet->getPiece(i)->getSprite().scale(Game::getXScale(), Game::getYScale());

		if (_whiteSet->getPiece(i)->getType() == "pawn") {
			_blackSet->getPiece(i)->getSprite().setPosition(_tiles[i][1]->getPosition());
			_whiteSet->getPiece(i)->getSprite().setPosition(_tiles[i][6]->getPosition());

			_blackSet->getPiece(i)->setCurrentTile(i, 1);
			_whiteSet->getPiece(i)->setCurrentTile(i, 6);
		}
		else {
			_blackSet->getPiece(i)->getSprite().setPosition(_tiles[i - _whiteSet->getRowSize()][0]->getPosition());
			_whiteSet->getPiece(i)->getSprite().setPosition(_tiles[i - _whiteSet->getRowSize()][7]->getPosition());
			
			_blackSet->getPiece(i)->setCurrentTile(i - _whiteSet->getRowSize(), 0);
			_whiteSet->getPiece(i)->setCurrentTile(i - _whiteSet->getRowSize(), 7);
		}
	}
}
Sprite& Board::getSprite() {
	return _sprite;
}
vector<Piece*>& Board::getWhitePieces() {
	return _whiteSet->getPieces();
}
vector<Piece*>& Board::getBlackPieces() {
	return _blackSet->getPieces();
}