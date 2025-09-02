#pragma once
#include <iostream>
#include <cstring>
#include <vector>

class common 
{
    public:
        virtual void display(std::vector<int>&) const = 0; // Виртуальный метод для отображения информации
        virtual std::string get_surname() const = 0;
        virtual common& operator=(const common& other){return *this;}
        virtual bool is_student() const{return false;}
        virtual int get_grup() const{return -1;}
        common(){
            //std::cout << "Конструктор по умолчанию базового класса\n";
        }
        virtual ~common()=default;
};