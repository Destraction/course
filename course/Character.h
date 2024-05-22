#pragma once
#include "Point2D.h"
class Character
{
protected:
    Point2D position;

public:
    Character(int x, int y) : position(x, y) {}

    Point2D getPosition() const { return position; }

    virtual void move(const Point2D& newPosition) {
        position = newPosition;
    }
};

