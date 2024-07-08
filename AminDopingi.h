#ifndef AMINDOPINGI_H
#define AMINDOPINGI_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Position.h"
#include "KeyPressHandler.h"

class AminDopingi : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit AminDopingi(QGraphicsScene *gameScene);
    ~AminDopingi();
    void applyGravity();
    void move();
    void jump();
    void stopFalling();
    void setVelocity(const QPointF &newVelocity);
    bool onGround;

private:
    QGraphicsScene *scene;
    int speed;
    Position velocity;
    QTimer *timer;
    KeyPressHandler *keyPressHandler;

public:
    int velocityY;
};

#endif // AMINDOPINGI_H
