#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>

class Platform : public QGraphicsPixmapItem
{
public:
    Platform(QGraphicsScene *scene, const QPixmap &pixmap, int x, int y);
};

#endif // PLATFORM_H
