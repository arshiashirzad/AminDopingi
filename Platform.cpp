#include "Platform.h"
#include <QGraphicsScene>

Platform::Platform(QGraphicsScene *scene, const QPixmap &pixmap, int x, int y)
    : QGraphicsPixmapItem(pixmap)
{
    setPos(x, y);
    scene->addItem(this);
}
