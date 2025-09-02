#pragma once 
#include <iostream>
#include <cstring>

#include "student.h"

#define N 100
using namespace std;

void students_direction(student *&students,int &col_students,  string *&direction, int &col_direction)
{
    cout << "Выберите студентов какого направления вы хотите увидеть: " << endl;
    cout << "Для этого введите соответствущую цифру из указанных ниже," << endl;
    cout << "каждая из которых соответствует направлению" << endl;
    for (int i = 0; i < col_direction; i++)
    {
        cout << direction[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < col_direction; i++)
    {
        cout << i << "\t";
    }
    cout << endl;

    int k{};
    do
    {
        cin >> k;
    } while (k > col_direction - 1 || k < 0);
    for (int i = 0; i < col_students; i++)
    {
        if (students[i].direction == direction[k])
        {
        cout << students[i].F_n_L_n.first_name <<"\t";
        cout << students[i].F_n_L_n.last_name <<"\t";
        cout << students[i].direction <<"\t";
        cout << students[i].num_group <<endl;
        }
        
    }
    
}
