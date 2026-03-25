#pragma once
#include <vector>
#include "Category.h"

class FileManager
{
public:
    void saveCategories(const std::vector<Category>& categories);
    void loadCategories(std::vector<Category>& categories);
};