#include "Render.h"

Render::Render() {}

void Render::RenderBoard() {
	Game::getWindow().draw(Board::getSprite());

	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			Game::getWindow().draw(*Board::_tiles[i][j]);
		}
	}

	for (unsigned int i = 0; i < 16; i++) {
		Game::getWindow().draw(Board::getWhitePieces().at(i)->getSprite());
		Game::getWindow().draw(Board::getBlackPieces().at(i)->getSprite());
	}


	Game::getWindow().display();
} 