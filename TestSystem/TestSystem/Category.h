#pragma once
#include <string>
#include <vector>
#include "Question.h"

class Category
{
private:
    std::string name;
    std::vector<Question> questions;

public:
    Category();
    Category(std::string name);

    std::string getName() const;
    void setName(std::string newName);

    std::vector<Question>& getQuestions();
    const std::vector<Question>& getQuestions() const;
    void setQuestions(const std::vector<Question>& newQuestions);

    void addQuestion();
    void removeQuestion();
    void showQuestions() const;
    void startTest() const;
};