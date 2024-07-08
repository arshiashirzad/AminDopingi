#include "gamemenu.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // QGraphicsView view;
    // QGraphicsScene scene;

    // view.setScene(&scene);
    // view.setFixedSize(800, 600);
    // Position playerPosition(50,468);
    // Position playerVelocity(0,0);
    // int platformWidth = 100;
    // int platformHeight = 30;
    // int startY = 500;
    // for (int i = 0; i < 10; ++i) {
    //     QGraphicsRectItem* platform = new QGraphicsRectItem(0, 0, platformWidth, platformHeight);
    //     platform->setPos(i * platformWidth, startY);
    //     platform->setBrush(Qt::yellow);
    //     scene.addItem(platform);
    // }
    auto menuView=new gameMenu();
    menuView->show();
    return a.exec();
}
