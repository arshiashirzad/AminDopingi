#include "gamemenu.h"

gameMenu::gameMenu()

{
    menuScene= new QGraphicsScene;
    menuScene->setSceneRect(0,0,437,700);
    setScene(menuScene);

    setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));

    //    set size of the background
    setFixedSize(437,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pButton= new playButton(menuScene);
    eButton= new exitButton(menuScene);
}
