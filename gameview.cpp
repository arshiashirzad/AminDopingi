#include "gameView.h"
#include "Platform.h"
#include <QDebug>

gameView::gameView(int whichNum)
    : QGraphicsView(), gameAmin(nullptr), stageControlTimer(nullptr), gameScene(nullptr)
{
    gameScene = new QGraphicsScene(this);
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

    QList<QGraphicsItem *> collidingItems = gameAmin->collidingItems();
    foreach (QGraphicsItem *item, collidingItems) {
        Platform *platform = dynamic_cast<Platform *>(item);
        if (platform) {
            QRectF platformRect = platform->boundingRect();
            QPointF aminPos = gameAmin->pos();

            if (gameAmin->velocity.y > 0 && aminPos.y() < platformRect.top()) {
                gameAmin->velocity.y = 0;
                gameAmin->setY(platformRect.top() - gameAmin->boundingRect().height());
            }
        }
    }

    qDebug() << "controlStage method called";
}


QGraphicsScene* gameView::sendScene() {
    return gameScene;
}
