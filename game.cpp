#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

class Game : public QGraphicsView {
    Q_OBJECT

public:
    Game(QWidget *parent = 0);

private:
    QGraphicsScene *scene;
    Player *player;
};

#endif // GAME_H
