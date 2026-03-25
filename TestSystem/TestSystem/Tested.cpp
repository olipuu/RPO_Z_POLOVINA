#include "Tested.h"
#include <iostream>

Tested::Tested(std::vector<Category>& cats) : categories(cats) {}

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

    showCategories();

    int index;
    std::cout << "Choose category: ";
    std::cin >> index;

    if (index < 1 || index > categories.size())
    {
        std::cout << "Error\n";
        return;
    }

    categories[index - 1].startTest();
}