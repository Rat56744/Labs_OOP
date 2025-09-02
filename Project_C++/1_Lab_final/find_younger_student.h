#pragma once 
#include "../1_Lab_final/student.h"
#include "../1_Lab_final/find_oldest_student.h"
#include <iostream>

using namespace std;

// Старше ли первый студент второго или нет?
bool younger_or_not(student &A, student &B)
{
    bool indicator = 0;
    int i = 0;
    do
    {
        switch(i)
        {
        case 0:
            if(A.birthday.year > B.birthday.year)
            {
                indicator = 1;
                i = 2;
            }else if(A.birthday.year == B.birthday.year)
            {++i;}
            else{return indicator;}
            break;
        case 1:
            if(!compare_month(A.birthday.month, B.birthday.month, 1))
            {
                indicator =1;
                i = 2;
            }else{++i;}
            break;
        case 2:
            if(A.birthday.date > B.birthday.date)
            {
                indicator = 1;
            }
            break;
        }
    } while (i!=2);
    return indicator;
}

int find_youngest_student(student *&students, int &col_students)
{
    student youngest_student = students[0];
    int index = 0;
    for(int j = 1; j < col_students; ++j)
    {
        if(younger_or_not(youngest_student, students[j])){}
        else
        {
            youngest_student = students[j];
            index = j;
        }
    }
    return index;
}