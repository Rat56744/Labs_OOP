#pragma once
#include "../4_Lab/stdfax.h"
#include <limits>
#include <iomanip>

class student;

class man
{
    protected:
        string name;
        string surname;
    public:
        virtual void display(vector<int>& max) const;
        man(vector<int>& max);
        man(vector<string>& tokens): name(tokens[1]), surname(tokens[2]){}
        man();
        virtual ~man()=default;
    friend student;
};