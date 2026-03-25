#pragma once
#include <vector>
#include "Category.h"
#include "Administrator.h"
#include "Tested.h"
#include "FileManager.h"

class MainMenu
{
private:
    std::vector<Category> categories;
    FileManager fileManager;

public:
    void run();
};