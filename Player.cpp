#include "Player.h"

Player::Player(int width, int height, Position position, int speed, Position velocity)
    : BodyObject(width, height, position), speed(speed), velocity(velocity), rect(new QGraphicsRectItem(0, 0, width, height)) {
    rect->setBrush(Qt::blue); // Set color to blue for visibility
    qDebug() << "Player created at (" << position.x << "," << position.y << ")";
}

Player::~Player() {
    delete rect;
}

void Player::handleGravity() {
    velocity.y += 1; // Simple gravity effect
    position.y += velocity.y;
    if (rect) rect->setY(position.y);
    qDebug() << "Player position after gravity: (" << position.x << "," << position.y << ")";
}

void Player::handleMovement() {
    position.x += velocity.x * speed;
    if (rect) rect->setX(position.x);
    qDebug() << "Player position after movement: (" << position.x << "," << position.y << ")";
}

void Player::draw(QGraphicsScene& scene) {
    if (!rect->scene()) {
        scene.addItem(rect);
    }
    rect->setPos(position.x, position.y);
    qDebug() << "Player drawn at (" << position.x << "," << position.y << ")";
}
