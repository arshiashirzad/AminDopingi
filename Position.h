#ifndef POSITION_H
#define POSITION_H

#include <QPointF>

class Position {
public:
    double x;
    double y;

    Position();
    Position(double _x, double _y);

    Position(const QPointF &point);

    operator QPointF() const;

    Position& operator=(const Position& other);
};

#endif // POSITION_H
