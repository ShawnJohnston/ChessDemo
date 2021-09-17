#include "Controls.h"

void Controls::windowClosedCheck(Event& event) {
    if (event.type == Event::Closed) {
        Game::getWindow().close();
    }
}

void Controls::escapeKeyCheck(Event& event) {
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        Game::getWindow().close();
    }
}
void Controls::leftMouseClickCheck(Event& event, Vector2f& position) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        pieceClickCheck(event, position);
    }
}
void Controls::rightMouseClickCheck(Event& event, Vector2f& position) {
    if (event.mouseButton.button == Mouse::Right) {
        
    }
}

void Controls::pieceClickCheck(Event& event, Vector2f& position) {
    Piece* clickedPiece = nullptr;
    for (Piece* piece : Board::getBlackPieces()) {
        if (clickedPiece == nullptr && piece->getSprite().getGlobalBounds().contains(position.x, position.y)) {
            clickedPiece = piece;
            break;
        }
    }
    if (Mouse::isButtonPressed(Mouse::Left) && clickedPiece != nullptr) {
        clickedPiece->getSprite().setPosition(position.x - (clickedPiece->getSprite().getGlobalBounds().width / 2), position.y - (clickedPiece->getSprite().getGlobalBounds().height / 2));
    }
}