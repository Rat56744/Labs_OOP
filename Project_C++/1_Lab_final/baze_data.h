#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <cstdio>

#include "student.h"

using namespace std;
void baze_data(int &col_students, student *&students, int *&max)
{
    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(2+9+4+9)<<left<<"Date birthday";
    cout <<setw(max[2]+5)<<left<<"Direction";
    cout <<setw(max[3]+5)<<left<<"Num group" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+44)<<'-'<<setfill(' ')<<endl;

    for (int i = 0; i < col_students; ++i)
    {
        cout <<setw(max[0]+5)<<left<< students[i].F_n_L_n.first_name;
        cout <<setw(max[1]+5)<<left<< students[i].F_n_L_n.last_name;
        cout <<setw(2+2)<<left<< students[i].birthday.date;
        cout <<setw(9+2)<<left<< students[i].birthday.month;
        cout <<setw(4+5)<<left<< students[i].birthday.year;
        cout <<setw(max[2]+5)<<left<< students[i].direction;
        cout <<setw(max[3]+5)<<left<< students[i].num_group <<endl;
    }
    cout << endl;
}