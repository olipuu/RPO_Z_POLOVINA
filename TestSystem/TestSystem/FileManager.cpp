#include "FileManager.h"
#include "ConsoleUtils.h"
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

namespace
{
    std::filesystem::path getCategoriesPath()
    {
        char modulePath[MAX_PATH] = {};
        GetModuleFileNameA(nullptr, modulePath, MAX_PATH);

        std::filesystem::path executablePath(modulePath);
        return executablePath.parent_path() / "categories.txt";
    }

    std::filesystem::path getResultsPath()
    {
        char modulePath[MAX_PATH] = {};
        GetModuleFileNameA(nullptr, modulePath, MAX_PATH);

        std::filesystem::path executablePath(modulePath);
        return executablePath.parent_path() / "results.txt";
    }

    Question makeQuestion(const std::string& text, const std::vector<std::string>& answers, int correctAnswer)
    {
        return Question(text, answers, correctAnswer);
    }

    std::vector<Category> createDefaultCategories()
    {
        std::vector<Category> categories;

        Category animals("Animals");
        animals.setQuestions({
            makeQuestion("Which animal says \"meow\"?", {"Dog", "Cat", "Cow", "Duck"}, 1),
            makeQuestion("Which animal is the largest on land?", {"Lion", "Elephant", "Horse", "Monkey"}, 1),
            makeQuestion("Which animal can fly?", {"Fish", "Bird", "Snake", "Rabbit"}, 1),
            makeQuestion("Which animal lives in water?", {"Tiger", "Shark", "Fox", "Giraffe"}, 1),
            makeQuestion("Which animal gives us milk?", {"Cow", "Wolf", "Bear", "Zebra"}, 0)
            });
        categories.push_back(animals);

        Category colors("Colors");
        colors.setQuestions({
            makeQuestion("What color is the sky on a clear day?", {"Green", "Blue", "Brown", "Pink"}, 1),
            makeQuestion("What color are bananas?", {"Yellow", "Black", "Purple", "Gray"}, 0),
            makeQuestion("What color do you get when you mix red and white?", {"Orange", "Pink", "Green", "Blue"}, 1),
            makeQuestion("What color is grass?", {"Red", "Green", "White", "Blue"}, 1),
            makeQuestion("What color is coal?", {"Black", "Yellow", "Orange", "Violet"}, 0)
            });
        categories.push_back(colors);

        Category school("School");
        school.setQuestions({
            makeQuestion("How many days are in a school week?", {"3", "5", "7", "10"}, 1),
            makeQuestion("Which subject includes numbers and counting?", {"History", "Art", "Math", "Music"}, 2),
            makeQuestion("What do students use to write with?", {"Spoon", "Pencil", "Plate", "Cup"}, 1),
            makeQuestion("Where do students usually sit in class?", {"Desk", "Shower", "Garage", "Garden"}, 0),
            makeQuestion("Which item can carry books?", {"Backpack", "Pillow", "Towel", "Lamp"}, 0)
            });
        categories.push_back(school);

        return categories;
    }

    void loadDefaultCategories(std::vector<Category>& categories)
    {
        categories = createDefaultCategories();
    }
}

void FileManager::saveCategories(const std::vector<Category>& categories)
{
    std::ofstream file(getCategoriesPath());

    if (!file.is_open())
        return;

    file << categories.size() << std::endl;

    for (int i = 0; i < categories.size(); i++)
    {
        file << categories[i].getName() << std::endl;

        const std::vector<Question>& questions = categories[i].getQuestions();
        file << questions.size() << std::endl;

        for (int j = 0; j < questions.size(); j++)
        {
            file << questions[j].getText() << std::endl;

            std::vector<std::string> answers = questions[j].getAnswers();
            file << answers.size() << std::endl;

            for (int k = 0; k < answers.size(); k++)
            {
                file << answers[k] << std::endl;
            }

            file << questions[j].getCorrectAnswer() << std::endl;
        }
    }

    file.close();
}

void FileManager::loadCategories(std::vector<Category>& categories)
{
    std::ifstream file(getCategoriesPath());

    if (!file.is_open())
    {
        loadDefaultCategories(categories);
        saveCategories(categories);
        return;
    }

    categories.clear();

    int categoryCount;
    file >> categoryCount;

    if (file.fail() || categoryCount <= 0)
    {
        loadDefaultCategories(categories);
        saveCategories(categories);
        return;
    }

    file.ignore();

    for (int i = 0; i < categoryCount; i++)
    {
        std::string categoryName;
        std::getline(file, categoryName);

        Category category(categoryName);

        int questionCount;
        file >> questionCount;

        if (file.fail() || questionCount < 0)
        {
            loadDefaultCategories(categories);
            saveCategories(categories);
            return;
        }

        file.ignore();

        std::vector<Question> questions;

        for (int j = 0; j < questionCount; j++)
        {
            std::string questionText;
            std::getline(file, questionText);

            int answersCount;
            file >> answersCount;

            if (file.fail() || answersCount <= 0)
            {
                loadDefaultCategories(categories);
                saveCategories(categories);
                return;
            }

            file.ignore();

            std::vector<std::string> answers;

            for (int k = 0; k < answersCount; k++)
            {
                std::string answer;
                std::getline(file, answer);
                answers.push_back(answer);
            }

            int correctAnswer;
            file >> correctAnswer;

            if (file.fail() || correctAnswer < 0 || correctAnswer >= answersCount)
            {
                loadDefaultCategories(categories);
                saveCategories(categories);
                return;
            }

            file.ignore();

            Question question(questionText, answers, correctAnswer);
            questions.push_back(question);
        }

        category.setQuestions(questions);
        categories.push_back(category);
    }

    file.close();
}

void FileManager::saveResult(const std::string& categoryName, int score, int totalQuestions)
{
    std::ofstream file(getResultsPath(), std::ios::app);

    if (!file.is_open())
        return;

    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm localTime = {};
    localtime_s(&localTime, &currentTime);

    std::ostringstream timeStream;
    timeStream << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

    file << timeStream.str() << std::endl;
    file << categoryName << std::endl;
    file << score << std::endl;
    file << totalQuestions << std::endl;
}

void FileManager::showResults() const
{
    std::ifstream file(getResultsPath());

    if (!file.is_open())
    {
        std::cout << "No saved results yet.\n";
        pauseScreen();
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    if (lines.empty())
    {
        std::cout << "No saved results yet.\n";
        pauseScreen();
        return;
    }

    std::cout << "--- SAVED RESULTS ---\n\n";

    int resultNumber = 1;

    for (int i = 0; i + 3 < lines.size(); i += 4)
    {
        std::cout << resultNumber << ". Date: " << lines[i] << std::endl;
        std::cout << "   Category: " << lines[i + 1] << std::endl;
        std::cout << "   Score: " << lines[i + 2] << " / " << lines[i + 3] << std::endl;
        std::cout << std::endl;
        resultNumber++;
    }

    pauseScreen();
}
