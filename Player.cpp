#include "player.h"

Player::Player()
{
    position = new Position(0,0);
}
void Player::Draw(QGraphicsScene &scene){
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,60,60);
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

