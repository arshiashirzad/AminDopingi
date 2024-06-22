#ifndef PLAYER_H
#define PLAYER_H
#include "bodyobject.h"
#include "position.h"
#include <QGraphicsView>
#include "QGraphicsRectItem"
class Player:public BodyObject
{
protected:
    Position * position ;
    Position * velocity;
    int height;
    int width;
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
    virtual void Draw(QGraphicsScene &scene);
    void handleGravity(QGraphicsScene &);
};
#endif // PLAYER_H
