#include "player.h"
#include "QTimer"
#include <QGraphicsRectItem>
#include <thread>
#include <chrono>

const double gravity = 0.5;
Player::Player()
{
    position = new Position(0,0);
    velocity = new Position(0 , 1);
    height = 60;
    width = 60;
}
void Player::Draw(QGraphicsScene &scene){
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(position->x,position->y,height,width);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    QBrush redBrush(Qt::red);
    rect->setBrush(redBrush);
    scene.addItem(rect);
    QGraphicsView * view = new QGraphicsView(&scene);
    view->setFixedHeight(scene.height());
    view->setFixedWidth(scene.width());
    view->showFullScreen();
}


void Player::handleGravity(QGraphicsScene& scene)
{
    while (position->y + height + velocity->y <= scene.height()) {

        this->position->y += this->velocity->y;
        this->velocity->y += gravity;

        // Sleep for 20 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }


}

