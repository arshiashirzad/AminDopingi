#include "playbutton.h"


playButton::playButton(QGraphicsScene *mainScene):
    QObject(),QGraphicsPixmapItem(),  playButtonScene{mainScene}, gameStart{true}
{
    setPixmap(QPixmap(":/image/play.png"));
    mainScene->addItem(this);
    setPos(150, 400);
}

void playButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(gameStart){
        gameStart=false;
        oneGame=new oneGameView;
        oneGame->show();
        oneGame->setFocus();
    }
}
