#include "Platform.h"

Platform::Platform(int width, int height, Position position)
    : BodyObject(width, height, position), rect(new QGraphicsRectItem(0, 0, width, height)) {
    rect->setBrush(Qt::gray); // Set color to gray for visibility
    qDebug() << "Platform created at (" << position.x << "," << position.y << ")";
}

Platform::~Platform() {
    delete rect;
}

void Platform::draw(QGraphicsScene& scene) {
    if (!rect->scene()) {
        scene.addItem(rect);
    }
    rect->setPos(position.x, position.y);
}
