#include "consoleColor.h"
void colorFondo(int tono)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    DWORD color = (info.wAttributes & 0xFF0F) | tono;
    SetConsoleTextAttribute(hConsole, color);
}
void colorLetras(int tono)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    DWORD color1 = (info.wAttributes & 0xFFF0) | tono;
    SetConsoleTextAttribute(hConsole, color1);
}

void color(int fondo, int letras)
{
    colorFondo(fondo);
    colorLetras(letras);
}
