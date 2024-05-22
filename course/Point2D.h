#pragma once
class Point2D
{
public:
    int x, y;

    Point2D(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }

    void Change_coords(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
};

