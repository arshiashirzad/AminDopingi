#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include "KeyPressHandler.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsView view;
    QGraphicsScene scene;

    view.setScene(&scene);
    view.setFixedSize(800, 600);

    QGraphicsRectItem* player = new QGraphicsRectItem(0, 0, 32, 32);
    player->setBrush(Qt::red);
    player->setPos(50, 468);
    scene.addItem(player);
    scene.setBackgroundBrush(QBrush(QImage(":/images/assets/background.png")));
    int platformWidth = 100;
    int platformHeight = 20;
    int platformCount = 10;
    int startY = 500;

    for (int i = 0; i < platformCount; ++i) {
        QGraphicsRectItem* platform = new QGraphicsRectItem(0, 0, platformWidth, platformHeight);
        platform->setPos(i * platformWidth, startY);
        platform->setBrush(Qt::yellow);
        scene.addItem(platform);
    }

    view.show();


    KeyPressHandler *keyPressHandler = new KeyPressHandler(&view);
    view.installEventFilter(keyPressHandler);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        static int velocityY = 0;
        static int posX = 50;
        static int posY = 468;
        static bool onGround = false;

        if (keyPressHandler->leftPressed) {
            posX -= 5;
        }
        if (keyPressHandler->rightPressed) {
            posX += 5;
        }

        velocityY += 1;
        posY += velocityY;

        QList<QGraphicsItem*> collidingItems = player->collidingItems();
        onGround = false;
        for (auto& item : collidingItems) {
            if (item->type() == QGraphicsRectItem::Type) {
                onGround = true;
                posY = item->y() - player->rect().height();
                // Stop falling
                velocityY = 0;
                break;
            }
        }

        if (keyPressHandler->upPressed && onGround) {
            velocityY = -20;
            posY += velocityY;
        }

        player->setPos(posX, posY);

    });
    timer.start(16);

    return a.exec();
}
