#ifndef AMINDOPINGI_H
#define AMINDOPINGI_H

#include "BodyObject.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "KeyPressHandler.h"
#include "Position.h"
class AminDopingi : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    friend class oneGameView;
private:
    int speed;
    Position velocity;
    QTimer *timer;
    QGraphicsScene *scene;
    KeyPressHandler *keyPressHandler;
public:
    explicit AminDopingi(QGraphicsScene *gameScene);
    ~AminDopingi();
    void handleGravity();
    void handleMovement();
};

#endif // AMINDOPINGI_H
