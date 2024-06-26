#ifndef PLATFORM_H
#define PLATFORM_H

#include "BodyObject.h"
#include <QGraphicsRectItem>
#include <QDebug>

class Platform : public BodyObject {
private:
    QGraphicsRectItem* rect;

public:
    Platform(int width, int height, Position position);
    ~Platform();

    void draw(QGraphicsScene& scene) override;
};

#endif // PLATFORM_H
