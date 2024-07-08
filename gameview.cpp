#include "gameView.h"
#include <QDebug>

// Constructor implementation
gameView::gameView(int wichNum) {
    // Initialize gameScene
    gameScene = new QGraphicsScene(this);
    setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));
    // Initialize gameAmin
    gameAmin = new AminDopingi(gameScene);

    // Set up the view
    setScene(gameScene);
    setRenderHint(QPainter::Antialiasing);

    // Set up the stage control timer
    stageControlTimer = new QTimer(this);
    connect(stageControlTimer, &QTimer::timeout, this, &gameView::controlStage);
    stageControlTimer->start(1000 / 60); // Call controlStage() at ~60 FPS

    qDebug() << "gameView constructor called with parameter:" << wichNum;
}

// Method implementation
void gameView::controlStage() {
    // Logic to control the stage, for example:
    gameAmin->handleGravity();
    gameAmin->handleMovement();

    // Add any additional stage control logic here
    qDebug() << "controlStage method called";
}

// sendScene method implementation
QGraphicsScene* gameView::sendScene() {
    return gameScene; // Return a pointer to the scene
}
