﻿#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Point2D {
public:
    int x, y;
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
};

class Character {
public:
    Point2D position;
};

class Prey : public Character {
public:
    Prey(int x, int y) {
        position.x = x;
        position.y = y;
    }
    void move() {
        int dx, dy;
        cout << "Prey's move (input dx and dy, dx and dy in [-1, 1]): ";
        cin >> dx >> dy;
        if (dx > 1) dx = 1; else if (dx < -1) dx = -1;
        if (dy > 1) dy = 1; else if (dy < -1) dy = -1;
        position.x += dx;
        position.y += dy;
    }
};

class Predator : public Character {
public:
    Predator(int x, int y) {
        position.x = x;
        position.y = y;
    }
    void move() {
        int dx, dy;
        cout << "Predator's move (input dx and dy, dx and dy in [-3, 3]): ";
        cin >> dx >> dy;
        if (dx > 3) dx = 3; else if (dx < -3) dx = -3;
        if (dy > 3) dy = 3; else if (dy < -3) dy = -3;
        position.x += dx;
        position.y += dy;
    }
};

class Arena {
public:
    Prey* prey;
    Predator* predator;
    Arena(Prey* p, Predator* pr) : prey(p), predator(pr) {}

    bool isGameOver() {
        int distance = abs(predator->position.x - prey->position.x) +
            abs(predator->position.y - prey->position.y);
        return distance < 1;
    }

    void updatePositions(int userRole) {
        if (userRole == 1) {
            prey->move();
            predator->move();
        }
        else {
            predator->move();
            prey->move();
        }
    }

    void showPositions() {
        cout << "Prey: (" << prey->position.x << ", " << prey->position.y << ")\n";
        cout << "Predator: (" << predator->position.x << ", " << predator->position.y << ")\n";
    }
};

int main() {
    int userRole, userMove;
    cout << "Choose your role: 1 for Prey, 2 for Predator: ";
    cin >> userRole;
    Prey* prey = new Prey(5, 5);
    Predator* predator = new Predator(0, 0);
    Arena* arena = new Arena(prey, predator);

    arena->showPositions();
    while (!arena->isGameOver()) {
        arena->updatePositions(userRole);
        arena->showPositions();
    }

    cout << "Game over!\n";

    delete arena;
    delete prey;
    delete predator;

    return 0;
}