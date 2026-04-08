#include "MainMenu.h"
#include "ConsoleUtils.h"
#include <iostream>

void MainMenu::run()
{
    fileManager.loadCategories(categories);

    Administrator admin(categories);
    Tested user(categories, fileManager);

    int choice;

    while (true)
    {
        clearScreen();
        std::cout << "--- MENU ---\n";
        std::cout << "1 - Admin panel\n";
        std::cout << "2 - Take test\n";
        std::cout << "3 - View saved results\n";
        std::cout << "0 - Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            admin.categoryMenu();
            fileManager.saveCategories(categories);
        }
        else if (choice == 2)
        {
            user.startTest();
        }
        else if (choice == 3)
        {
            clearScreen();
            fileManager.showResults();
        }
        else if (choice == 0)
        {
            fileManager.saveCategories(categories);
            break;
        }
        else
        {
            std::cout << "Wrong choice\n";
            pauseScreen();
        }
    }
}
