#include "gamemenu.h"
gameMenu::gameMenu()

{
    menuScene= new QGraphicsScene;
    menuScene->setSceneRect(0,0,437,700);
    setScene(menuScene);
    setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));
    setFixedSize(437,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameName = new QGraphicsTextItem("AMIN DOPINGI");
    QFont titleFont("Decorative", 32, QFont::Bold);
    gameName->setFont(titleFont);
    gameName->setDefaultTextColor(QColor(255, 165, 0));
    int xPos = (sceneRect().width() - gameName->boundingRect().width()) / 2;
    gameName->setPos(xPos, 100);
    menuScene->addItem(gameName);
    pButton= new playButton(menuScene);
    eButton= new exitButton(menuScene);
}
