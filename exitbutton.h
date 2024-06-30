#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class exitButton : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit exitButton(QGraphicsScene *meinScene);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:

};

#endif // EXITBUTTON_H
