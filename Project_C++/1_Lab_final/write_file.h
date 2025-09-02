#include "../1_Lab_final/student.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

#define N 100
using namespace std;

void write_file(fstream &file, student *&students, int &col_students, int *max)
{
    file << col_students << ",";
    for(int i = 0; i < 4; ++i)
    {
        file << max[i] << ",";
    }
    file << endl;  // Мы записали первую строчку. В ней хранятся данные о количестве студентов и ширине столбцов
    for(int i = 0; i < col_students; ++i)
    {
        cout << "Запись в фаил " << students[i].F_n_L_n.first_name << "," << students[i].F_n_L_n.last_name << "\n";
        file << students[i].F_n_L_n.first_name << "," << students[i].F_n_L_n.last_name << ",";
        file << students[i].birthday.date << "," << students[i].birthday.month << "," << students[i].birthday.year << ",";
        file << students[i].direction << "," << students[i].num_group << endl;
    }
    file.close();
}