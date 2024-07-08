#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include "AminDopingi.h"

class gameView : public QGraphicsView {
    Q_OBJECT
private:
    AminDopingi *gameAmin;
    QTimer *stageControlTimer;
    QGraphicsScene *gameScene;
public:
    explicit gameView(int wichNum = 0);
    QGraphicsScene* sendScene();
signals:
public slots:
    void controlStage();
};

#endif // GAMEVIEW_H
