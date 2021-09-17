#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Controls.h"
#include "ImageManager.h"
#include "Render.h"
#include "Board.h"
#include "SpriteMap.h"


int main() {
    Game game;
    Board::initialize();

    game.start();

    ImageManager::clear();
    return 0;
}