#include "ConsoleUtils.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

void clearScreen()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (consoleHandle == INVALID_HANDLE_VALUE)
        return;

    CONSOLE_SCREEN_BUFFER_INFO screenInfo;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &screenInfo))
        return;

    DWORD cellCount = screenInfo.dwSize.X * screenInfo.dwSize.Y;
    DWORD written = 0;
    COORD homeCoordinates = { 0, 0 };

    FillConsoleOutputCharacter(consoleHandle, ' ', cellCount, homeCoordinates, &written);
    FillConsoleOutputAttribute(consoleHandle, screenInfo.wAttributes, cellCount, homeCoordinates, &written);
    SetConsoleCursorPosition(consoleHandle, homeCoordinates);
}

void pauseScreen()
{
    std::cout << "\nPress any key to continue...";
    _getch();
    std::cout << '\n';
}
