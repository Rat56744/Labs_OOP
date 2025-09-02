#pragma once
#include "../4_Lab/stdfax.h"
#include "../4_Lab/fio.h"
#include "../4_Lab/common.h"

/*
Инициализируем значение первого элемента нулем. Нужно для совместимости с индексацией
по массиву value_department(ф-я main)  */
enum Department{VM_1=0, IB, MIUP, TKS, AMF};

class teacher:public common
{
    private:
        fio prep;
        Department department;
        string academical_course;
    public:
        string get_name(){return prep.name;}
        string get_surname()const override{return prep.surname;}
        string get_patronymic(){return prep.patronymic;}
        int get_department();
        string get_academical_course();
        void initialization_enum(vector<int>&max_prep);
        void display(vector<int>& max_prep) const override;
        teacher(vector<string>& tokens);
        teacher(vector<int>& max_prep);
        teacher();
};