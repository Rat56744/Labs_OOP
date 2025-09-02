#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Student.h"

#define N 100
using namespace std;

void students_grup(student *&students, int& col_students, int *&numbers, int &col_numbers, int *&max)
{
    cout << "Выберите студентов какого направления вы хотите увидеть: " << endl;
    cout << "Для этого введите соответствущую цифру из указанных ниже," << endl;
    cout << "каждая из которых соответствует направлению" << endl<< endl;

    cout <<setw(11*2+2+2)<<left<<"Направление: ";
    for (int i = 0; i < col_numbers; i++)
    {
        cout <<setw(max[2]+5)<<left<< numbers[i];
    }
    cout << endl;

    cout <<setw(5*2+6+2+2)<<left<<"Цифра: ";
    for (int i = 0; i < col_numbers; i++)
    {
        cout <<setw(max[2]+5)<<left<< i;
    }
    cout << endl<< endl;

    int k{};
    do
    {
        cin >> k;
    } while (k > col_numbers - 1 || k < 0);

    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(max[3]+5)<<left<<"Num group" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+15)<<'-'<<setfill(' ')<<endl;

    for (int i = 0; i < col_students; i++)
    {
        if (students[i].grup == numbers[k])
        {
            students[i].cout_student_as_field(max);
        }
        
    }
    
}