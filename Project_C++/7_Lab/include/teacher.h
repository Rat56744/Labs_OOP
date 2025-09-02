#pragma once
#include "stdfax.h"
#include "fio.h"
#include "common.h"

/*
Инициализируем значение первого элемента нулем. Нужно для совместимости с индексацией
по массиву value_department(ф-я main)  */
enum Department{VM_1=0, IB, MIUP, TKS, AMF};

class teacher:public common
{
    private:
        fio prep;
        Department department;
        std::string academical_course;
    public:

        // Перегруженные операторы
        void display(std::vector<int>& max_prep) const override;
        friend std::ostream& operator<<(std::ostream& stream, const teacher& teach);
        teacher& operator=(const teacher& other);

        // Методы класса
        std::string get_name()const override{return prep.name;}
        std::string get_surname()const override{return prep.surname;}
        std::string get_patronymic(){return prep.patronymic;}
        int get_department();
        std::string get_academical_course();
        std::string get_department_string();
        void initialization_enum(std::vector<int>&max_prep);

        // Конструкторы класса
        teacher(std::vector<std::string>& tokens);
        teacher(std::vector<int>& max_prep);
        teacher();
};