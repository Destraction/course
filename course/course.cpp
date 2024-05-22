#include <iostream>
#include <iomanip>
#include <conio.h>
#include <random>
#include <Windows.h>
#include "Character.h"
#include "Arena.h"
#include "Predator.h"
#include "Prey.h"
#include "Console.h"

int main()
{
	unsigned short int player_choice;
	char dir_choice = ' ';
	bool game_over = false;
	Arena arena(30, 30);
	Predator predator(1, 1);
	Prey prey(15, 15);
	// Инициализация всего, что потребуется
	arena.placeCharacter(predator, "**");
	arena.placeCharacter(prey, "()");

	std::cout << "Choose the player:\n1 --- Prey ()\n2 --- Predator **\nYour choice: ";
	std::cin >> player_choice;

	setCursorPosition(0, 0);
	switch (player_choice)
	{
	case 2:
		arena.Draw();
		while (!game_over) {
			// Пока не конец игры
			unsigned int distance = 0; // Инициализируем дистанцию
			dir_choice = _getch(); // Получаем направление движения без нажатия Enter

			// Получаем предыдущие координаты
			int prev_x = predator.getPosition().x;
			int prev_y = predator.getPosition().y;

			//Инициализируем новую точку
			Point2D new_pos(prev_x, prev_y);
			setCursorPosition(0, 0);
			switch (dir_choice) {

			case 'w':
				setCursorPosition(35, 35);
				std::cout << "Distance: "; std::cin >> distance;
				setCursorPosition(0, 0);
				if (distance <= 3) {
					new_pos.Change_coords(prev_x, prev_y - distance);
					predator.Move(new_pos, arena);
					break;
				}

				else
				{
					break;
				}
			case 'a':
				setCursorPosition(35, 35);
				std::cout << "Distance: "; std::cin >> distance;
				setCursorPosition(0, 0);
				if (distance <= 3) {
					new_pos.Change_coords(prev_x - distance, prev_y);
					predator.Move(new_pos, arena);
					break;
				}

				else
				{
					break;
				}
			case 'x':
				setCursorPosition(35, 35);
				std::cout << "Distance: "; std::cin >> distance;
				setCursorPosition(0, 0);
				if (distance <= 3) {
					new_pos.Change_coords(prev_x, prev_y + distance);
					predator.Move(new_pos, arena);
					break;
				}

				else
				{
					break;
				}
			case 'd':
				setCursorPosition(35, 35);
				std::cout << "Distance: "; std::cin >> distance;
				setCursorPosition(0, 0);
				if (distance <= 3) {
					new_pos.Change_coords(prev_x + distance, prev_y);
					predator.Move(new_pos, arena);
					break;
				}

				else
				{
					break;
				}

			case 'l':
				setCursorPosition(40, 40);
				std::cout << "Goodbye... ";
				exit(0);
			default:
				break;
			}
			prey.moveRandomly(arena);

			arena.Draw();
			Point2D pred_pos = predator.getPosition();
			Point2D prey_pos = prey.getPosition();

			// Если расстояние между игроками < 2, игра окончена
			game_over = sqrt(pow((pred_pos.x - prey_pos.x), 2) + pow((pred_pos.y - prey_pos.y), 2)) <= 2.0;
		}
		std::cout << "You win! ";
		break;

	case 1:
		arena.Draw();
		while (!game_over) {
			unsigned int distance = 0;
			dir_choice = _getch();
			int prev_x = prey.getPosition().x;
			int prev_y = prey.getPosition().y;
			Point2D new_pos(prev_x, prev_y);
			setCursorPosition(0, 0);
			switch (dir_choice) {

			case 'q':
				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x - 1, prev_y - 1);
				prey.Move(new_pos, arena);
				break;

			case 'w':
				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x, prev_y - 1);
				prey.Move(new_pos, arena);
				break;

			case 'e':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x + 1, prev_y - 1);
				prey.Move(new_pos, arena);
				break;

			case 'd':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x + 1, prev_y);
				prey.Move(new_pos, arena);
				break;

			case 'c':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x + 1, prev_y + 1);
				prey.Move(new_pos, arena);
				break;

			case 'x':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x, prev_y + 1);
				prey.Move(new_pos, arena);
				break;

			case 'z':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x - 1, prev_y + 1);
				prey.Move(new_pos, arena);
				break;

			case 'a':

				setCursorPosition(0, 0);
				new_pos.Change_coords(prev_x - 1, prev_y);
				prey.Move(new_pos, arena);
				break;

			case 'l':
				setCursorPosition(40, 40);
				std::cout << "Goodbye... ";
				exit(0);
			default:
				break;
			}
			predator.moveTowards(prey.getPosition(), arena);
			setCursorPosition(0, 0);
			arena.Draw();
			Point2D pred_pos = predator.getPosition();
			Point2D prey_pos = prey.getPosition();

			game_over = sqrt(pow((pred_pos.x - prey_pos.x), 2) + pow((pred_pos.y - prey_pos.y), 2)) <= 1.0;
		}
		std::cout << "You lose... ";
		break;

	default:
		std::cout << "No such option... ";
		break;
	}
}
