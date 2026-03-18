#pragma once
#include <string>
#include <vector>

class Question
{
private:
    std::string text;
    std::vector<std::string> answers;
    int correctAnswer;

public:
    Question();
    Question(std::string text, std::vector<std::string> answers, int correctAnswer);

    std::string getText() const;
    std::vector<std::string> getAnswers() const;
    int getCorrectAnswer() const;

    bool ask() const;
};