#pragma once
#include "stdfax.h"
#include "man.h"

class teacher;

class fio:public man
{
    private:
        std::string patronymic;
    public: 
        friend std::ostream& operator<<(std::ostream& stream, const fio& teach);
        fio& operator=(const fio& other);
        std::string get_name(){return name;}
        void display(std::vector<int>& max_prep) const;
        fio(std::vector<int>& max_prep);
        fio(std::vector<std::string>& tokens);
        fio();
        ~fio()override{}
    friend teacher;
};