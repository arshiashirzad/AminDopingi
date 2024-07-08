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
    QTimer *timer;
    QGraphicsScene *scene;
    KeyPressHandler *keyPressHandler;
public:
    Position velocity;
    explicit AminDopingi(QGraphicsScene *gameScene);
    ~AminDopingi();
    void handleGravity();
    void handleMovement();
    void setVelocity(const QPointF &newVelocity);
};

#endif // AMINDOPINGI_H
