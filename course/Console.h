#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN


// Функция для очистки консоли, чтоб поле перерисовывалось, 
// а не рисовалось каждый раз заново. Код взят со StackOverflow, хз как он работает
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
