#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include "AminDopingi.h"
#include "Platform.h"

class gameView : public QGraphicsView {
    Q_OBJECT

public:
    gameView(int whichNum=0);
    QGraphicsScene* sendScene();

private:
    void createPlatforms();
    void controlStage();
    void checkCollisionWithPlatform();

    QGraphicsScene *gameScene;
    AminDopingi *gameAmin;
    QTimer *stageControlTimer;
};

#endif // GAMEVIEW_H
