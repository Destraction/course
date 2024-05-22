#pragma once

class Prey : public Character
{
public:

    Prey(int x, int y) : Character(x, y) {}

    void Move(const Point2D& newPosition, Arena& arena) {
        if (newPosition.x >= 0 && newPosition.x < 30 && newPosition.y >= 0 && newPosition.y < 30) { // Проверка границ поля
            arena.clearCharacter(*this);
            move(newPosition);
            arena.placeCharacter(*this, "()");
        }
    }



    void moveRandomly(Arena& arena) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 7); // 8 возможных направлений, генерируем одно

        int direction = dis(gen);
        Point2D newPosition = position;

        switch (direction) {
        case 0: newPosition.x++; break; // Вправо
        case 1: newPosition.y++; break; // Вниз
        case 2: newPosition.x--; break; // Влево
        case 3: newPosition.y--; break; // Вверх
        case 4: newPosition.x++; newPosition.y++; break; // Право-вниз
        case 5: newPosition.x--; newPosition.y++; break; // Влево-вниз
        case 6: newPosition.x--; newPosition.y--; break; // Влево-вверх
        case 7: newPosition.x++; newPosition.y--; break; // Вправо-вверх
        }

        // Проверка границ
        if (newPosition.x >= 0 && newPosition.x < 30 && newPosition.y >= 0 && newPosition.y < 30) {

            arena.clearCharacter(*this); // Убираем рисунок с пред.места
            move(newPosition); // Меняем координаты
            arena.placeCharacter(*this, "()"); // Рисуем новый рисунок
        }
    }
};

