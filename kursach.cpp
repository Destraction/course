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
};

class Predator : public Character {
public:
    Predator(int x, int y) {
        position.x = x;
        position.y = y;
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

    void updatePositions() {
        // the prey moves randomly in all 8 directions
        prey->position.x += rand() % 3 - 1;
        prey->position.y += rand() % 3 - 1;

        // the predator moves towards the prey in 4 directions
        if (predator->position.x < prey->position.x) predator->position.x++;
        else if (predator->position.x > prey->position.x) predator->position.x--;

        if (predator->position.y < prey->position.y) predator->position.y++;
        else if (predator->position.y > prey->position.y) predator->position.y--;
    }

    void showPositions() {
        cout << "Prey: (" << prey->position.x << ", " << prey->position.y << ")\n";
        cout << "Predator: (" << predator->position.x << ", " << predator->position.y << ")\n";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // to generate real random numbers
    Prey* prey = new Prey(rand() % 10, rand() % 10);
    Predator* predator = new Predator(rand() % 10, rand() % 10);
    Arena* arena = new Arena(prey, predator);

    arena->showPositions();
    while (!arena->isGameOver()) {
        arena->updatePositions();
        arena->showPositions();
    }

    cout << "Game over!\n";

    delete arena;
    delete prey;
    delete predator;

    return 0;
}