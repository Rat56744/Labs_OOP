#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <cstdio>

#include "../2_Lab/Student.h"

using namespace std;
void baze_data(student *&students, int& col_students, int *&max)
{
    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(max[2]+5)<<left<<"Num group" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+15)<<'-'<<setfill(' ')<<endl;
    for(int i = 0; i < col_students; ++i)
    {
        students[i].cout_student_as_field(max);
    }
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+15)<<'-'<<setfill(' ')<<endl;
    cout << "Количество студентов: " << col_students << "\n";
    cout << endl;
}