#ifndef PLAYER_H
#define PLAYER_H

#include "BodyObject.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>

class Player : public BodyObject {
private:
    int speed;
    Position velocity;
    QGraphicsRectItem* rect;

public:
    Player(int width, int height, Position position, int speed, Position velocity);
    ~Player();

    void handleGravity();
    void handleMovement();
    void draw(QGraphicsScene& scene) override;
};

#endif // PLAYER_H
