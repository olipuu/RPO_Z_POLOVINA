#include "Question.h"
#include <iostream>

Question::Question() : correctAnswer(0) {}

Question::Question(std::string text, std::vector<std::string> answers, int correctAnswer)
{
    this->text = text;
    this->answers = answers;
    this->correctAnswer = correctAnswer;
}

std::string Question::getText() const
{
    return text;
}

std::vector<std::string> Question::getAnswers() const
{
    return answers;
}

int Question::getCorrectAnswer() const
{
    return correctAnswer;
}

bool Question::ask() const
{
    std::cout << "\n" << text << std::endl;

    for (int i = 0; i < answers.size(); i++)
    {
        std::cout << i + 1 << " - " << answers[i] << std::endl;
    }

    int choice;
    std::cout << "Enter answer: ";
    std::cin >> choice;

    if (choice - 1 == correctAnswer)
    {
        std::cout << "Correct!\n";
        return true;
    }
    else
    {
        std::cout << "Wrong\n";
        return false;
    }
}