#pragma once
#include "stdfax.h"
#include <limits>
#include <iomanip>

class student;

class man
{
    protected:
        std::string name;
        std::string surname;
    public:
        
        // Перегруженные операторы
        friend std::ostream& operator<<(std::ostream& stream, const man& teach);
        man& operator=(const man& other);
        
        // Методы класса
        virtual void display(std::vector<int>& max) const;

        // Конструкторы класса
        man(std::vector<int>& max);
        man(std::vector<std::string>& tokens): name(tokens[1]), surname(tokens[2]){}
        man();
        virtual ~man()=default;
    friend student;
};