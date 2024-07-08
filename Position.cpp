#include "Position.h"

Position::Position() : x(0), y(0) {}

Position::Position(double _x, double _y) : x(_x), y(_y) {}

Position::Position(const QPointF &point) : x(point.x()), y(point.y()) {}

Position::operator QPointF() const {
    return QPointF(x, y);
}

Position& Position::operator=(const Position& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}
