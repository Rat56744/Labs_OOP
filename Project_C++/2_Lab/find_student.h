#pragma once 
#include <iostream>
#include <cstring>
#include <iomanip>
#include "../2_Lab/Student.h"

using namespace std;

void find_student(student *&students, int& col_students,int *&max)
{
    char First_name[100]{};
    char Last_name[100]{};
    cout << "Введите имя и фамилию студента:\n";
    cout << "Имя: ";
    cin >> First_name;
    cout << "Фамилия: ";
    cin >> Last_name;

    for(int i = 0; i < col_students;++i)
    {
        if(First_name == students[i].get_name() && Last_name == students[i].get_fam())
        {
            students[i].cout_student_as_field(max);
        }
    }
} 