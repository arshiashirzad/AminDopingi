#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();
};
#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
};


#endif // PLAYER_H
