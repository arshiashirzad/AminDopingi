#include "gameView.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

gameView::gameView(int whichNum)
    : QGraphicsView(), gameAmin(nullptr), stageControlTimer(nullptr), gameScene(nullptr) {
    gameScene = new QGraphicsScene(0, 0, 800, 600, this);
    setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));

    gameAmin = new AminDopingi(gameScene);

    setScene(gameScene);
    setRenderHint(QPainter::Antialiasing);

    createPlatforms();

    stageControlTimer = new QTimer(this);
    connect(stageControlTimer, &QTimer::timeout, this, &gameView::controlStage);
    stageControlTimer->start(1000 / 60);

    qDebug() << "gameView constructor called with parameter:" << whichNum;
}

void gameView::createPlatforms() {
    new Platform(gameScene, QPixmap(":/images/assets/platform.png"), 100, 500);
}

void gameView::controlStage() {
    gameAmin->handleGravity();
    gameAmin->handleMovement();

    if (checkCollisionWithPlatform()) {
        gameAmin->velocity.y=0; // Stop falling
        gameAmin->setPos(gameAmin->x(), gameAmin->y() - 1); // Ensure the player stays on the platform
    }

    qDebug() << "controlStage method called";
}

bool gameView::checkCollisionWithPlatform() {
    QList<QGraphicsItem *> collidingItems = gameAmin->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        Platform *platform = dynamic_cast<Platform *>(item);
        if (platform) {
            return true;
        }
    }
    return false;
}

QGraphicsScene* gameView::sendScene() {
    return gameScene;
}
