#include "Game.h"

Game::Game(QGraphicsView& view, QGraphicsScene& scene, std::vector<Platform> platforms, Player player, int amountDistance)
    : view(view), scene(scene), platforms(platforms), player(player), amountDistance(amountDistance) {
    qDebug() << "Game initialized";
}

void Game::handleGameOver() {
    qDebug() << "Game Over!";
    // Handle game over logic
}

void Game::handleVictory() {
    qDebug() << "Victory!";
    // Handle victory logic
}

void Game::draw() {
    qDebug() << "Drawing scene...";
    scene.clear();
    for (auto& platform : platforms) {
        platform.draw(scene);
    }
    player.draw(scene);
    view.setScene(&scene);
    qDebug() << "Scene drawn";
}

void Game::update() {
    qDebug() << "Updating game state...";
    player.handleGravity();
    player.handleMovement();
    // More game logic here
    qDebug() << "Game state updated";
}
