#include "FileManager.h"
#include <fstream>
#include <string>
#include <vector>

void FileManager::saveCategories(const std::vector<Category>& categories)
{
    std::ofstream file("categories.txt");

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
    std::ifstream file("categories.txt");

    if (!file.is_open())
        return;

    categories.clear();

    int categoryCount;
    file >> categoryCount;
    file.ignore();

    for (int i = 0; i < categoryCount; i++)
    {
        std::string categoryName;
        std::getline(file, categoryName);

        Category category(categoryName);

        int questionCount;
        file >> questionCount;
        file.ignore();

        std::vector<Question> questions;

        for (int j = 0; j < questionCount; j++)
        {
            std::string questionText;
            std::getline(file, questionText);

            int answersCount;
            file >> answersCount;
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
            file.ignore();

            Question question(questionText, answers, correctAnswer);
            questions.push_back(question);
        }

        category.setQuestions(questions);
        categories.push_back(category);
    }

    file.close();
}