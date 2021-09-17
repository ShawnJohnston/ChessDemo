#include "SpriteMap.h"

map<string, Sprite> SpriteMap::_sprites;
void SpriteMap::initializeSprites() {
	string assetTextures[6] = { "king", "queen", "rook", "bishop", "knight", "pawn" };
	string pieceColor[2] = { "B", "W" };

	for (String piece : assetTextures) {
		for (unsigned int i = 0; i < 1; i++) {
			Sprite sprite(ImageManager::getTexture(piece + pieceColor[i]));
			Sprite sprite2(ImageManager::getTexture(piece + pieceColor[i] + "2"));
			Sprite sprite3(ImageManager::getTexture(piece + pieceColor[i] + "3"));

			_sprites.emplace((piece + pieceColor[i]), sprite);
			_sprites.emplace((piece + pieceColor[i] + "2"), sprite2);
			_sprites.emplace((piece + pieceColor[i] + "3"), sprite3);
		}
	}
	string assetTextures1[4] = { "icon", "board", "squareB", "squareW" };
	for (unsigned int i = 0; i < 4; i++) {
		Sprite sprite(ImageManager::getTexture(assetTextures1[i]));
		_sprites.emplace(assetTextures1[i], sprite);
	}
}