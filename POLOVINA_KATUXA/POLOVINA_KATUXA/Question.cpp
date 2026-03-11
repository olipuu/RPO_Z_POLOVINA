#include "Question.h"
#include <iostream>

Question::Question() {}

Question::Question(std::string text, std::vector<std::string> answers, int correctAnswer)
{
    this->text = text;
    this->answers = answers;
    this->correctAnswer = correctAnswer;
}

std::string Question::getText()
{
    return text;
}

bool Question::ask()
{
    std::cout << text << std::endl;

    for(int i = 0; i < answers.size(); i++)
        std::cout << i + 1 << " - " << answers[i] << std::endl;

    int choice;
    std::cout << "Введите ответ: ";    
    std::cin >> choice;    

return (choice - 1 == correctAnswer);
}