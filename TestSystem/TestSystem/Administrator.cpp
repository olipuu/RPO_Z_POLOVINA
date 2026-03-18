#include "Administrator.h"
#include <iostream>
#include <string>

Administrator::Administrator(std::vector<Category>& cats) : categories(cats) {}

void Administrator::showCategories()
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

void Administrator::addCategory()
{
    std::string name;

    std::cout << "Enter category name: ";
    std::getline(std::cin >> std::ws, name);

    Category newCategory(name);
    categories.push_back(newCategory);

    std::cout << "Category added\n";
}

void Administrator::removeCategory()
{
    if (categories.empty())
    {
        std::cout << "No categories\n";
        return;
    }

    showCategories();

    int index;
    std::cout << "Enter category number: ";
    std::cin >> index;

    if (index < 1 || index > categories.size())
    {
        std::cout << "Error\n";
        return;
    }

    categories.erase(categories.begin() + index - 1);
    std::cout << "Category deleted\n";
}

void Administrator::editCategory()
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

    int choice;

    while (true)
    {
        std::cout << "\nCategory: " << categories[index - 1].getName() << std::endl;
        std::cout << "1 - Show questions\n";
        std::cout << "2 - Add question\n";
        std::cout << "3 - Delete question\n";
        std::cout << "0 - Back\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1)
            categories[index - 1].showQuestions();
        else if (choice == 2)
            categories[index - 1].addQuestion();
        else if (choice == 3)
            categories[index - 1].removeQuestion();
        else if (choice == 0)
            break;
        else
            std::cout << "Wrong choice\n";
    }
}

void Administrator::categoryMenu()
{
    int choice;

    while (true)
    {
        std::cout << "\n--- ADMIN PANEL ---\n";
        std::cout << "1 - Show categories\n";
        std::cout << "2 - Add category\n";
        std::cout << "3 - Delete category\n";
        std::cout << "4 - Edit category\n";
        std::cout << "0 - Back\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1)
            showCategories();
        else if (choice == 2)
            addCategory();
        else if (choice == 3)
            removeCategory();
        else if (choice == 4)
            editCategory();
        else if (choice == 0)
            break;
        else
            std::cout << "Wrong choice\n";
    }
}