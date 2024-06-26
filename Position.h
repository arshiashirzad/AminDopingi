#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x, y;

    Position();
    Position(int x, int y);
    Position(const Position& other);
    Position& operator=(const Position& other);
};

#endif // POSITION_H
