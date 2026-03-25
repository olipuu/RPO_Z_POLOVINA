#pragma once
#include <vector>
#include "Category.h"

class Tested
{
private:
    std::vector<Category>& categories;

public:
    Tested(std::vector<Category>& cats);

    void showCategories();
    void startTest();
};