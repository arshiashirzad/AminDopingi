#include "exitbutton.h"


exitButton::exitButton(QGraphicsScene *meinScene)
{
    setPixmap(QPixmap(":/images/assets/exit.png"));


    meinScene->addItem(this);
    setPos(150,450);
}

void exitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    exit(1);

}
