//#include "gtest/gtest.h"
//#include <SFML/Graphics.hpp>
//#include "ImageManager.h"
//#include "SpriteMap.h"
//#include "Piece.h"
//#include "PieceSet.h"
//#include "Game.h"
//#include "Board.h"
//#include "Render.h"
//#include "Controls.h"
//#include <string>
//#include <string.h>
//#include <map>
//#include <iostream>
//#include <vector>
//using namespace sf;
//using namespace std;
//
//TEST(Chess_Piece, pieceIsConstructed) {
//	string assetTextures[6] = { "king", "queen", "rook", "bishop", "knight", "pawn" };
//	string pieceColor[2] = { "B", "W" };
//
//	for (string type : assetTextures) {
//		for (string color : pieceColor) {
//			Texture texture;
//			string fileName = "images/" + type + color + ".png";
//			texture.loadFromFile(fileName);
//			
//			Sprite sprite(texture);
//			Piece piece;
//			piece.setType(type);
//			if (color == "B") {
//				piece.setColor("B");
//			}
//			else if (color == "W") {
//				piece.setColor("W");
//			}
//			piece.setSprite(sprite);
//			EXPECT_EQ(type, piece.getType());
//			EXPECT_EQ(color, piece.getColor());
//		}
//	}
//
//}
//TEST(Piece_Set, constructorsGettersSetters) {
//	PieceSet whiteSet("B");
//	PieceSet blackSet("W");
//	EXPECT_EQ("B", whiteSet.getColor());
//	EXPECT_EQ("W", blackSet.getColor());
//
//	whiteSet.setColor("W");
//	blackSet.setColor("B");
//	EXPECT_EQ("W", whiteSet.getColor());
//	EXPECT_EQ("B", blackSet.getColor());
//
//	vector<PieceSet> sets;
//	sets.push_back(whiteSet);
//	sets.push_back(blackSet);
//
//	for (PieceSet set : sets) {
//		EXPECT_EQ(16, set.getTotalSize());
//		EXPECT_EQ(8, set.getRowSize());
//		EXPECT_EQ(16, set.getPieceCount());
//
//
//		vector<Piece*> pieces = set.getPieces();
//		for (unsigned int j = 0; j < pieces.size(); j++) {
//			string type;
//			if ( j < 8 ) {
//				type = "pawn";
//			}
//			else if (j == 8 || j == 15) {
//				type = "rook";
//			}
//			else if (j == 9 || j == 14) {
//				type = "knight";
//			}
//			else if (j == 10 || j == 13) {
//				type = "bishop";
//			}
//			else if (j == 11) {
//					type = "queen";
//			}
//			else if (j == 12) {
//				type = "king";
//			}
//			EXPECT_EQ(type, pieces.at(j)->getType());
//			EXPECT_EQ(set.getColor(), pieces.at(j)->getColor());
//		}
//	}
//}
//
//
//int main() {
//	testing::InitGoogleTest();
//	return RUN_ALL_TESTS();
//}