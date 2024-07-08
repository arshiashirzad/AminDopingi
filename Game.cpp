#include "Game.h"


void Game::handleGameOver() {
}
void Game::handleVictory() {
}

void Game::draw() {
    scene.clear();
    for (auto& platform : platforms) {
        platform.draw(scene);
    }
    view.setScene(&scene);
}
void Game::update() {
    player.handleGravity();
    player.handleMovement();
}
