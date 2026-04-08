#include "Tested.h"
#include "ConsoleUtils.h"
#include <iostream>

Tested::Tested(std::vector<Category>& cats, FileManager& manager) : categories(cats), fileManager(manager) {}

void Tested::showCategories()
{
    if (categories.empty())
    {
        std::cout << "No categories\n";
        return;
    }

    for (int i = 0; i < categories.size(); i++)
    {
        std::cout << i + 1 << " - " << categories[i].getName() << std::endl;
    }
}

void Tested::startTest()
{
    if (categories.empty())
    {
        std::cout << "No categories\n";
        return;
    }

    clearScreen();
    showCategories();

    int index;
    std::cout << "Choose category: ";
    std::cin >> index;

    if (index < 1 || index > categories.size())
    {
        std::cout << "Error\n";
        pauseScreen();
        return;
    }

    int score = categories[index - 1].startTest();
    fileManager.saveResult(categories[index - 1].getName(), score, static_cast<int>(categories[index - 1].getQuestions().size()));
}
