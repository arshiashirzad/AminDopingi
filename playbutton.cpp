#include "playbutton.h"


playButton::playButton(QGraphicsScene *mainScene):
    QObject(),QGraphicsPixmapItem(),  playButtonScene{mainScene}, gameStart{true}
{
    setPixmap(QPixmap(":/images/assets/play.png"));
    mainScene->addItem(this);
    setPos(150, 400);
}

void playButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(gameStart){
        gameStart=false;
        Game= new gameView;
        Game->show();
        Game->setFocus();
    }
}
