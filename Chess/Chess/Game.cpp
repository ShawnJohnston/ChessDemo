#include "Game.h"

RenderWindow* Game::window_;
VideoMode Game::videoMode_;
float Game::_xScale;
float Game::_yScale; 
Vector2i Game::mousePositionWindow_;
Vector2f Game::mousePositionView_;
Game::Game() {
    _xScale = 1.5;
    _yScale = 1.5;
    initializeVariables();
    initializeWindow();
}
Game::~Game() {
	delete window_;
}
const bool Game::isRunning() const {
    return window_->isOpen();
}

void Game::setXScale(float x) {
    _xScale = x;
}
void Game::setYScale(float y) {
    _yScale = y;
}

RenderWindow& Game::getWindow() {
    return *window_;
}
VideoMode& Game::getVideoMode() {
    return videoMode_;
}
float Game::getXScale() {
    return _xScale;
}
float Game::getYScale() {
    return _yScale;
}
Vector2i& Game::getMousePositionWindow() {
    return mousePositionWindow_;
}
Vector2f& Game::getMousePositionView() {
    return mousePositionView_;
}


void Game::pollEvents() {
    Controls controls;
    while (window_->pollEvent(event_)) {
        controls.windowClosedCheck(event_);
        controls.escapeKeyCheck(event_);
        controls.leftMouseClickCheck(event_, mousePositionView_);
        controls.rightMouseClickCheck(event_, mousePositionView_);
    }
}
void Game::initializeVariables() {
    window_ = nullptr;
}
void Game::initializeWindow() {
    Sprite boardSprite(ImageManager::getTexture("board"));
    videoMode_.width = boardSprite.getTexture()->getSize().x * 2;
    videoMode_.height = boardSprite.getTexture()->getSize().y * 1.5;

    window_ = new RenderWindow(videoMode_, "Game", sf::Style::Titlebar | sf::Style::Close);
    window_->setFramerateLimit(120);
}

void Game::start() {
    while (isRunning()) {

        update();

        render();
    }
}
void Game::update() {
    pollEvents();
    updateMousePositions();
}
void Game::render() {
    Render render;
    render.RenderBoard();
}

void Game::updateMousePositions() {
    mousePositionWindow_ = sf::Mouse::getPosition(*window_);
    mousePositionView_ = window_->mapPixelToCoords(mousePositionWindow_);
}