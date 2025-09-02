#pragma once
#include "../4_Lab/stdfax.h"
#include "../4_Lab/man.h"

class teacher;

class fio:public man
{
    private:
        string patronymic;
    public: 
        string get_name(){return name;}
        void display(vector<int>& max_prep) const;
        fio(vector<int>& max_prep);
        fio(vector<string>& tokens);
        fio();
        ~fio()override{}
    friend teacher;
};