#include "gameView.h"
#include "Platform.h"
#include <QDebug>

gameView::gameView(int whichNum)
    : QGraphicsView(), gameAmin(nullptr), stageControlTimer(nullptr), gameScene(nullptr)
{
    gameScene = new QGraphicsScene(0,0,800,600,this);
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
    // Update game elements
    gameAmin->handleGravity();
    gameAmin->handleMovement();

    // Check for collisions with platforms
    QList<QGraphicsItem *> collidingItems = gameAmin->collidingItems();
    foreach (QGraphicsItem *item, collidingItems) {
        Platform *platform = dynamic_cast<Platform *>(item);
        if (platform) {
            QRectF platformRect = platform->boundingRect();
            QPointF platformPos = platform->pos();
            QPointF aminPos = gameAmin->pos();

            // Adjust platformRect to its position in the scene
            platformRect.moveTopLeft(platformPos);

            qDebug() << "Amin position:" << aminPos;
            qDebug() << "Platform position:" << platformPos;
            qDebug() << "Adjusted platform rect:" << platformRect;
            qDebug() << "Amin bounding rect:" << gameAmin->boundingRect();

            // Check if Amin is above the platform and falling
            if (gameAmin->velocity.y > 0 &&
                aminPos.y() + gameAmin->boundingRect().height() <= platformRect.top() &&
                aminPos.x() + gameAmin->boundingRect().width() > platformRect.left() &&
                aminPos.x() < platformRect.right()) {

                qDebug() << "Collision detected!";
                gameAmin->velocity.y = 0; // Stop falling
                gameAmin->setY(platformRect.top() - gameAmin->boundingRect().height()); // Adjust position
            }
        }
    }

    qDebug() << "controlStage method called";
}



QGraphicsScene* gameView::sendScene() {
    return gameScene;
}
