#pragma once

class Predator : public Character
{
public:
    Predator(int x, int y) : Character(x, y) {}

    void Move(const Point2D& newPosition, Arena& arena) {
        // Проверка границ
        if (newPosition.x >= 0 && newPosition.x < 30 && newPosition.y >= 0 && newPosition.y < 30) {
            arena.clearCharacter(*this);
            move(newPosition);
            arena.placeCharacter(*this, "**"); // Assuming 'P' represents Prey
        }
    }

    void moveTowards(const Point2D& target, Arena& arena) {
        int dx = target.x - position.x;
        int dy = target.y - position.y;

        // Выбираем направление, основываясь на том, по какой оси наибольшее расстояние до жертвы
        int primaryDirectionX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
        int primaryDirectionY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;

        // Выбираем рандомную дистанцию (1-3)
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(1, 3);

        int distanceToMove = dis(gen);
        Point2D newPosition(0, 0);

        // Если по оси Х дистанция больше, двигаемся только по ней
        if (abs(dx) > abs(dy)) {
            newPosition = { position.x + primaryDirectionX * distanceToMove, position.y };
        }

        else {
            // И наоборот
            newPosition = { position.x, position.y + primaryDirectionY * distanceToMove };
        }

        if (newPosition.x >= 0 && newPosition.x < 30) {
            // Проверка границ
            arena.clearCharacter(*this); // Убираем рисунок с пред.места
            move(newPosition); // Меняем координаты
            arena.placeCharacter(*this, "**"); // Рисуем новый рисунок
        }
    }
};