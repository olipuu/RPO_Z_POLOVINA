#pragma once
#include <vector>
#include "Category.h"
#include "FileManager.h"

class Tested
{
private:
    std::vector<Category>& categories;
    FileManager& fileManager;

public:
    Tested(std::vector<Category>& cats, FileManager& manager);

    void showCategories();
    void startTest();
};
