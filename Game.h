#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include <QDebug>
#include "Platform.h"
#include "Player.h"

class Game {
private:
    QGraphicsView& view;
    QGraphicsScene& scene;
    std::vector<Platform> platforms;
    Player player;
    int amountDistance;

public:
    Game(QGraphicsView& view, QGraphicsScene& scene, std::vector<Platform> platforms, Player player, int amountDistance);
    void handleGameOver();
    void handleVictory();
    void draw();
    void update();
};

#endif // GAME_H
