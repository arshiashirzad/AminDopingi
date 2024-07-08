#include "AminDopingi.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "Position.h"

AminDopingi::AminDopingi(QGraphicsScene *gameScene)
    : QObject(), QGraphicsPixmapItem(), scene{gameScene}, speed(5), velocity(0, 0),
    timer(new QTimer(this)), keyPressHandler(new KeyPressHandler(this)), onGround(false), velocityY(0) {
    QPixmap playerPixmap(":/images/assets/spriteStandRight.png");
    playerPixmap = playerPixmap.scaled(QSize(50, 90));
    setPixmap(playerPixmap);
    gameScene->addItem(this);
    scene->installEventFilter(keyPressHandler);

    setPos(50, 200);

    QObject::connect(timer, &QTimer::timeout, this, [this]() {
        move();
        applyGravity();
    });
    timer->start(16);

    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

AminDopingi::~AminDopingi() {
    delete timer;
    delete keyPressHandler;
}

void AminDopingi::applyGravity() {
    if (!onGround) {
        velocityY += 1;
        setY(y() + velocityY);
    }
}

void AminDopingi::move() {
    if (keyPressHandler->leftPressed) {
        setX(x() - speed);
    }
    if (keyPressHandler->rightPressed) {
        setX(x() + speed);
    }
}

void AminDopingi::jump() {
    if (onGround) {
        velocityY = -20;
        onGround = false;
    }
}

void AminDopingi::stopFalling() {
    velocityY = 0;
    onGround = true;
}

void AminDopingi::setVelocity(const QPointF &newVelocity) {
    velocity = newVelocity;
}
void AminDopingi::gameOver(QGraphicsScene *gameScene) {
    if (!itsOver) {
        timer->stop();
        gameOverText = new QGraphicsTextItem("Game Over!");
        QFont titleFont("Decorative", 32, QFont::Bold);
        gameOverText->setFont(titleFont);
        gameOverText->setDefaultTextColor(QColor(255, 165, 0));
        int xPos = (gameScene->width() - gameOverText->boundingRect().width()) / 2;
        gameOverText->setPos(xPos, 100);
        gameScene->addItem(gameOverText);
        itsOver = true;
    }
}
