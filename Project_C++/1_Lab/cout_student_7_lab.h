#pragma once 
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

void cout_student(student *&students,int &col_students,  int *&max)
{
    cout <<setw(max[0]+7)<<left<<"Number student";
    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name" << endl;
    cout <<setfill('-')<<setw(max[0]+max[0]+max[1]+12)<<'-'<<setfill(' ')<<endl;
    for(int i{}; i < col_students; i++)
    {   cout <<setw(max[0]+7)<<left<< i+1;
        cout <<setw(max[0]+5)<<left<< students[i].F_n_L_n.first_name;
        cout <<setw(max[1]+5)<<left<< students[i].F_n_L_n.last_name <<endl;}
    
    cout << "Введите номер студента информацию о котором вы хотите вывести:" << endl;
    int a = 0;
    cin >> a;

    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(3+9+3+5)<<left<<"Birthday";
    cout <<setw(max[2]+5)<<left<<"Direction";
    cout <<setw(max[3]+5)<<left<<"Num group" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+16)<<'-'<<setfill(' ')<<endl;

    cout <<setw(max[0]+5)<<left<< students[a-1].F_n_L_n.first_name;
    cout <<setw(max[1]+5)<<left<< students[a-1].F_n_L_n.last_name;
    cout <<setw(3+9+3+5)<<left<< students[a-1].birthday.date,".",students[a-1].birthday.month,".",students[a-1].birthday.year ;
    cout <<setw(max[2]+5)<<left<< students[a-1].direction;
    cout <<setw(max[3]+5)<<left<< students[a-1].num_group <<endl;
}
