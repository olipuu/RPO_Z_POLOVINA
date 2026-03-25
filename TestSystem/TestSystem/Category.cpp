#include "Category.h"
#include <iostream>
#include <string>

Category::Category() {}

Category::Category(std::string name)
{
    this->name = name;
}

std::string Category::getName() const
{
    return name;
}

void Category::setName(std::string newName)
{
    name = newName;
}

std::vector<Question>& Category::getQuestions()
{
    return questions;
}

const std::vector<Question>& Category::getQuestions() const
{
    return questions;
}

void Category::setQuestions(const std::vector<Question>& newQuestions)
{
    questions = newQuestions;
}

void Category::addQuestion()
{
    std::string text;
    std::vector<std::string> answers(4);
    int correct;

    std::cout << "Enter question text: ";
    std::getline(std::cin >> std::ws, text);

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Answer " << i + 1 << ": ";
        std::getline(std::cin, answers[i]);
    }

    std::cout << "Enter correct answer number (1-4): ";
    std::cin >> correct;

    if (correct < 1 || correct > 4)
    {
        std::cout << "Error\n";
        return;
    }

    Question q(text, answers, correct - 1);
    questions.push_back(q);

    std::cout << "Question added\n";
}

void Category::removeQuestion()
{
    if (questions.empty())
    {
        std::cout << "No questions\n";
        return;
    }

    showQuestions();

    int index;
    std::cout << "Enter question number: ";
    std::cin >> index;

    if (index < 1 || index > questions.size())
    {
        std::cout << "Error\n";
        return;
    }

    questions.erase(questions.begin() + index - 1);
    std::cout << "Question deleted\n";
}

void Category::showQuestions() const
{
    if (questions.empty())
    {
        std::cout << "No questions\n";
        return;
    }

    for (int i = 0; i < questions.size(); i++)
    {
        std::cout << i + 1 << ". " << questions[i].getText() << std::endl;
    }
}

void Category::startTest() const
{
    if (questions.empty())
    {
        std::cout << "There are no questions in this category yet\n";
        return;
    }

    int score = 0;

    for (int i = 0; i < questions.size(); i++)
    {
        if (questions[i].ask())
            score++;
    }

    std::cout << "\nResult: " << score << " / " << questions.size() << std::endl;
}