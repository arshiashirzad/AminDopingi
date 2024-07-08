#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "AminDopingi.h"

class gameView : public QGraphicsView {
    Q_OBJECT
private:
    AminDopingi *gameAmin;
    QTimer *stageControlTimer;
    QGraphicsScene *gameScene;

public:
    explicit gameView(int whichNum = 0);
    QGraphicsScene* sendScene();

private slots:
    void controlStage();

private:
    void createPlatforms();
};

#endif // GAMEVIEW_H
