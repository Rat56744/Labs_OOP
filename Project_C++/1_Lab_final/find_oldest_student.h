#pragma once 
#include "../1_Lab_final/student.h"
#include <iostream>
#include <cstring>

using namespace std;

bool compare_month(const char* month1, const char* month2, bool younges_or_oldest)
{
    // Массив для хранения названий месяцев
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Определяем индексы обоих месяцев
    int index1 = -1;
    int index2 = -1;

    for (int i = 0; i < 12; ++i) {
        if (strcmp(month1, months[i]) == 0) {
            index1 = i;
        }
        if (strcmp(month2, months[i]) == 0) {
            index2 = i;
        }
    }

    // Сравниваем индексы
    if (index1 < index2) {   // month1 позже month2
        return 1;
    } else if (index1 == index2) {
        return younges_or_oldest;   // Если мы ищем самого старшего, то тут должен быть 0(чтобы не было ошибки сравнения), а если самого молодого, то 1
    } else {
        return 0;  // month1 раньше month2
    }
}

// Старше ли первый студент второго или нет?
bool older_or_not(student &A, student &B)
{
    bool indicator = 0;
    int i = 0;
    do
    {
        cout << endl << "older_or_not" << endl;
        switch(i)
        {
        case 0:
            if(A.birthday.year < B.birthday.year)
            {
                indicator = 1;  // Точно старше
                i = 2;
            }else if(A.birthday.year == B.birthday.year)
            {++i;}
            else{return indicator;}
            break;
        case 1:
            if(compare_month(A.birthday.month, B.birthday.month, 0))
            {
                indicator = 1;  // Точно старше
                i = 2;
            }else{++i;}
            break;
        case 2:
            if(A.birthday.date < B.birthday.date)
            {
                indicator = 1;
            }
            break;
        }
    } while (i!=2);
    return indicator;
}

int find_oldest_student(student *&students, int &col_students)
{
    student youngest_student = students[0];
    int min_index=5;

    int i = 0;
    for(int j = 1; j < col_students; ++j)
    {
        if(older_or_not(youngest_student, students[j])){
            cout << endl << "if" << endl;}
        else
        {
            cout << endl << "else" << endl;
            youngest_student = students[j];
            min_index = j;
        }
        cout << endl << "end for" << endl;
    }
    return min_index;
}