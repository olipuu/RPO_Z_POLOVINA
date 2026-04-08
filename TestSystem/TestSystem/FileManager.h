#pragma once
#include <string>
#include <vector>
#include "Category.h"

class FileManager
{
public:
    void saveCategories(const std::vector<Category>& categories);
    void loadCategories(std::vector<Category>& categories);
    void saveResult(const std::string& categoryName, int score, int totalQuestions);
    void showResults() const;
};
