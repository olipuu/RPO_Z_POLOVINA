#pragma once
#include <vector>
#include "Category.h"

class Administrator
{
private:
    std::vector<Category>& categories;

public:
    Administrator(std::vector<Category>& cats);

    void showCategories();
    void addCategory();
    void removeCategory();
    void editCategory();
    void categoryMenu();
};