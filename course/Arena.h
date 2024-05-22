#pragma once

class Arena
{
private:

	unsigned int width; // Ширина, высота, и трехмерный массив чаров для поля. 
	//Трехмерный, потому что одна ячейка содержит два чара. "--" или "()" или "**"
	unsigned int height;
	char*** data;

	char predator_sprite[3];
	char prey_sprite[3];
	char empty_sprite[3];

	void DrawHorisontal() {
		for (unsigned int j = 0; j < width * 3 + 2; ++j) {
			if (j == 0) {
				std::cout << "    ";
			}
			std::cout << '~';
		}
	}  // Отрисовка горизонтальных полос сверху и снизу поля

public:

	Arena() : width(30), height(30), predator_sprite("**"), prey_sprite("()"), empty_sprite("--") {

		data = new char** [height];
		for (unsigned int i = 0; i < height; ++i) {
			data[i] = new char* [width];
			for (unsigned int j = 0; j < width; ++j) {
				data[i][j] = new char[3];
			}
		} // Выделение памяти под трехмерный массив

		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				for (unsigned int k = 0; k < 2; ++k) {
					data[i][j][k] = '-';
				}
			}
		} // Заполнение массива пустыми ячейками
	}

	Arena(unsigned int width, unsigned int height) : width(30), height(30), predator_sprite("**"), prey_sprite("()"), empty_sprite("--") {
		// Перегрузка инициализации, чтоб можно было задавать любой размер поля
		data = new char** [height];
		for (unsigned int i = 0; i < height; ++i) {
			data[i] = new char* [width];
			for (unsigned int j = 0; j < width; ++j) {
				data[i][j] = new char[3];
			}
		}

		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				for (unsigned int k = 0; k < 2; ++k) {
					data[i][j][k] = '-';
				}
			}
		}
	}

	~Arena() {
		// Деструктор с освобождением памяти
		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				delete[] data[i][j];
			}
			delete[] data[i];
		}
		delete[] data;
	}

	char**& operator[](unsigned int index) {
		return data[index];
	} // Обращение к элементу вручную


	void Draw() {
		// Рисование поля в консоль
		DrawHorisontal();

		for (unsigned int i = 0; i < height; ++i) {
			std::cout << std::endl;

			for (unsigned int j = 0; j < width; ++j) {
				if (j == 0) {
					std::cout << std::setw(3) << width - i << "| ";
				}
				for (unsigned int k = 0; k < 2; ++k) {
					std::cout << data[i][j][k];
				}
				std::cout << ' ';
				if (j == width - 1) {
					std::cout << '|';
				}
			}

		}
		std::cout << std::endl;
		DrawHorisontal();

		std::cout << std::endl;
		std::cout << "    ";
		for (unsigned int k = 1; k <= width; ++k) {
			std::cout << ' ' << std::setw(2) << k; // setw фиксирует размер поля для вывода. Например, чтоб 100 и 5 оба занимали по три ячейки
		}
		std::cout << std::endl;

	};


	void placeCharacter(const Character& character, const char* symbol) {
		// Рисование рисунка в консоль, передаем рисунок как symbol
		data[character.getPosition().y][character.getPosition().x][0] = symbol[0];
		data[character.getPosition().y][character.getPosition().x][1] = symbol[1];
	}

	void clearCharacter(const Character& character) {
		// Стирание из консоли по координатам 
		data[character.getPosition().y][character.getPosition().x][0] = '-';
		data[character.getPosition().y][character.getPosition().x][1] = '-';

	}

};
