#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity)
    : BodyObject(width, height, position), speed(speed), velocity(velocity), rect(new QGraphicsRectItem(0, 0, width, height)) {
    rect->setBrush(Qt::blue);
    rect->setPos(50, 468);
}

Player::~Player() {
    delete rect;
}

void Player::handleGravity() {
    velocity.y += 1;
    position.y += velocity.y;
    if (rect) rect->setY(position.y);
}

void Player::handleMovement() {
    position.x += velocity.x * speed;
    if (rect) rect->setX(position.x);
}

void Player::draw(QGraphicsScene& scene) {
    if (!rect->scene()) {
        scene.addItem(rect);
    }
    rect->setPos(position.x, position.y);
}
