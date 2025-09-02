#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "../3_Lab/student.h"
#include "../3_Lab/man.h"

using namespace std;

void baze_data(vector<student>& MStud, vector<int>& max)
{
    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(max[2]+5)<<left<<"Direction";
    cout <<setw(max[3]+5)<<left<<"Grup" << endl;
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'-'<<setfill(' ')<<endl;
    for(int i = 0; i < MStud.size(); ++i)
    {
        MStud[i].student_out(max);
    }
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'-'<<setfill(' ')<<endl;
    cout << "Количество студентов: " << MStud.size() << "\tКоличество объектов: " << MStud[0].get_count() << "\n";
    cout << endl;
}
