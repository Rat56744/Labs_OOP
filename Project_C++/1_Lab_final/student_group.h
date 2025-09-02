#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <cstdio>

#include "student.h"

using namespace std;

// namespace Test{
void student_group(student *&students, int &col_student,string *&direction, int &col_direction, int*& numbers, int &col_numbers, student *&group_students, int &col_group, int *&max)
{
    cout << "Выберите студентов какой группы вы хотите увидеть: " << endl;
    cout << "Для этого введите соответствущую цифру из указанных ниже," << endl;
    cout << "каждая из которых соответствует направлению и номеру группы" << endl;
    cout <<endl<< "Выберите направление: " << endl;


    // Выбираем направление
    cout <<setw(11*2+2+2)<<left<<"Направление: ";
    for (int i = 0; i < col_direction; i++)
    {
        cout <<setw(max[2]+5)<<left<< direction[i];
    }
    cout << endl;

    cout <<setw(5*2+6+2+2)<<left<<"Цифра: ";
    for (int i = 0; i < col_direction; i++)
    {
        cout <<setw(max[2]+5)<<left<< i;
    }
    cout << endl<< endl;

    /* Ввод нужного направления и проверка корректности
       введенных данных*/
    int k{};
    do
    {
        cin >> k;
    } while (k > col_direction - 1 || k < 0);

    // Выбираем номер группы
    cout <<endl<< "Выберите номер группы: " << endl;
    for (int i = 0; i < col_numbers; i++)
    {
        cout <<setw(max[3]+5)<<left<< numbers[i];
    }
    cout << endl;
    for (int i = 0; i < col_numbers; i++)
    {
        cout <<setw(max[3]+5)<<left<< i;
    }
    cout << endl;

    int g{};
    int schet{};
    do
    {
        cin >> g;
        for(int i{}; i < col_student; i++)
        {
            if(students[i].direction == direction[k] && students[i].num_group == numbers[g])// Условие проверки существования направления с указанным номером группы
            {
                ++schet;
                if (g > col_numbers - 1 || g < 0) // Проверка выхода за пределы значений массива numbers
                {
                    schet = 0;
                }
            }
        }
    } while (schet == 0);
    
    for (int i = 0, j{}; i < col_direction; i++)
    {
        if (students[i].direction == direction[k] && students[i].num_group  == numbers[g])
        {
            group_students[j] = students[i];
            ++col_group;
            ++j;
        }
    }
    int col_transp{};
    do
    {
        col_transp = 0;
        for (int i = 0; i < col_group - 1; i++)
        {
            if(group_students[i].direction < group_students[i + 1].direction)
            {
            student A;
            A = group_students[i + 1];
            group_students[i + 1] = group_students[i];
            group_students[i] = A;
            ++col_transp;
            }
        }
        
    } while (col_transp !=0);
}
// }