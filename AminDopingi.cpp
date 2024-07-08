#include "AminDopingi.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include "Position.h"
AminDopingi::AminDopingi(QGraphicsScene *gameScene)
    : QObject(), QGraphicsPixmapItem(), scene{gameScene}, speed(0), velocity(0, 0),
    timer(new QTimer(this)), keyPressHandler(new KeyPressHandler(this))
{
    QPixmap playerPixmap(":/images/assets/spriteStandRight.png");
    playerPixmap = playerPixmap.scaled(QSize(50, 50));
    setPixmap(playerPixmap);
    gameScene->addItem(this);
    setPos(100, 200);
    scene->installEventFilter(keyPressHandler);
    QObject::connect(timer, &QTimer::timeout, this, [this]() {
        static int velocityY = 0;
        static int posX = 50;
        static int posY = 468;
        static bool onGround = false;
        if (keyPressHandler->leftPressed) {
            posX -= 5;
        }
        if (keyPressHandler->rightPressed) {
            posX += 5;
        }
        velocityY += 1;
        posY += velocityY;
        setPos(posX, posY);
    });
    timer->start(16);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

AminDopingi::~AminDopingi() {
    delete timer;
    delete keyPressHandler;
}

void AminDopingi::handleGravity() {
    velocity.y += 1;
    setY(y() + velocity.y);
}

void AminDopingi::handleMovement() {
    setX(x() + velocity.x * speed);
}
void AminDopingi::setVelocity(const QPointF &newVelocity) {
    velocity = newVelocity;
}
