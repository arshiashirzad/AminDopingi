#include "player.h"
#include <QKeyEvent>
#include <QTimer>

Player::Player() : speed(5), leftPressed(false), rightPressed(false), upPressed(false), downPressed(false) {
    // Set the player image
    setPixmap(QPixmap(":/images/player.png"));

    // Set up a timer to call the move() method repeatedly
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::move);
    timer->start(16); // roughly 60 fps
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        leftPressed = true;
    } else if (event->key() == Qt::Key_Right) {
        rightPressed = true;
    } else if (event->key() == Qt::Key_Up) {
        upPressed = true;
    } else if (event->key() == Qt::Key_Down) {
        downPressed = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        leftPressed = false;
    } else if (event->key() == Qt::Key_Right) {
        rightPressed = false;
    } else if (event->key() == Qt::Key_Up) {
        upPressed = false;
    } else if (event->key() == Qt::Key_Down) {
        downPressed = false;
    }
}

void Player::move() {
    if (leftPressed) {
        setPos(x() - speed, y());
    }
    if (rightPressed) {
        setPos(x() + speed, y());
    }
    if (upPressed) {
        setPos(x(), y() - speed);
    }
    if (downPressed) {
        setPos(x(), y() + speed);
    }
}
