#ifndef BODYOBJECT_H
#define BODYOBJECT_H
#include <QGraphicsScene>
class BodyObject
{
public:
    BodyObject();
    virtual void Draw(QGraphicsScene &scene)=0;
};

#endif
