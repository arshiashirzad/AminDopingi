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

}

void gameView::createPlatforms() {
    new Platform(gameScene, QPixmap(":/images/assets/platform.png"), -140, 500);
    new Platform(gameScene, QPixmap(":/images/assets/platformSmallTall.png"), 600, 400);

}

void gameView::controlStage() {
    checkCollisionWithPlatform();
}

void gameView::checkCollisionWithPlatform() {
    QList<QGraphicsItem *> collidingItems = gameAmin->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        Platform *platform = dynamic_cast<Platform *>(item);
        if (platform) {
            gameAmin->stopFalling();
            gameAmin->setY(platform->y() - gameAmin->boundingRect().height());
            return;
        }
    }
    gameAmin->onGround = false;
}

QGraphicsScene* gameView::sendScene() {
    return gameScene;
}
