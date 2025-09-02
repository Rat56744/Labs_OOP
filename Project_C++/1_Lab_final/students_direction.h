#pragma once 
#include <iostream>
#include <iomanip>
#include <cstring>

#include "student.h"

#define N 100
using namespace std;

// namespace Test{
void students_direction(student *&students,int &col_students,  string *&direction, int &col_direction, int *&max)
{
    cout << "Выберите студентов какого направления вы хотите увидеть: " << endl;
    cout << "Для этого введите соответствущую цифру из указанных ниже," << endl;
    cout << "каждая из которых соответствует направлению" << endl<< endl;

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

    int k{};
    do
    {
        cin >> k;
    } while (k > col_direction - 1 || k < 0);

    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(max[2]+5)<<left<<"Direction";
    cout <<setw(max[3]+5)<<left<<"Num group" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'-'<<setfill(' ')<<endl;

    for (int i = 0; i < col_students; i++)
    {
        if (students[i].direction == direction[k])
        {
        cout <<setw(max[0]+5)<<left<< students[i].F_n_L_n.first_name;
        cout <<setw(max[1]+5)<<left<< students[i].F_n_L_n.last_name;
        cout <<setw(max[2]+5)<<left<< students[i].direction;
        cout <<setw(max[3]+5)<<left<< students[i].num_group <<endl;
        }
        
    }
    
}
// }