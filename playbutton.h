#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "gameview.h"
class playButton : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    gameView *Game;
    QGraphicsScene playButtonScene;
    bool gameStart;
public:
    explicit playButton(QGraphicsScene* mainScene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PLAYBUTTON_H
