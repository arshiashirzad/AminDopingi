#include "Game.h"

Game::Game(QGraphicsView& view, QGraphicsScene& scene, std::vector<Platform> platforms, Player player, int amountDistance)
    : view(view), scene(scene), platforms(platforms), player(player), amountDistance(amountDistance) {
}

void Game::handleGameOver() {
}

void Game::handleVictory() {
}

void Game::draw() {
    scene.clear();
    for (auto& platform : platforms) {
        platform.draw(scene);
    }
    player.draw(scene);
    view.setScene(&scene);
}

void Game::update() {
    player.handleGravity();
    player.handleMovement();
}
