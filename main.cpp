#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
/*
Tutorial Topics:
-events (keyPressEvent() and QKeyEvent)
-event propogation system
-QDebug
*/

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    Player * player = new Player();
    player->Draw(*scene);
    return a.exec();
}
