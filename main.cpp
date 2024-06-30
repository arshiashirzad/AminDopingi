#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include "KeyPressHandler.h"
#include "Position.h"
#include "Player.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsView view;
    QGraphicsScene scene;

    view.setScene(&scene);
    view.setFixedSize(800, 600);
    Position playerPosition(50,468);
    Position playerVelocity(0,0);
    Player* player = new Player(50, 50,playerPosition, 32, playerVelocity);
    scene.addItem(player->rect);
    scene.setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));
    int platformWidth = 100;
    int platformHeight = 30;
    int startY = 500;
    for (int i = 0; i < 10; ++i) {
        QGraphicsRectItem* platform = new QGraphicsRectItem(0, 0, platformWidth, platformHeight);
        platform->setPos(i * platformWidth, startY);
        platform->setBrush(Qt::yellow);
        scene.addItem(platform);
    }

    view.show();
    KeyPressHandler *keyPressHandler = new KeyPressHandler(&view);
    view.installEventFilter(keyPressHandler);


    return a.exec();
}
