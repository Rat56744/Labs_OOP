#include "../2_Lab/Student.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

#define N 100
using namespace std;

void write_file(fstream &file, int& col_students, student *&students, int *max)
{
    file << col_students << ",";
    for(int i = 0; i < 3; ++i)
    {
        file << max[i] << ",";
    }
    file << endl;  // Мы записали первую строчку. В ней хранятся данные о количестве студентов и ширине столбцов
    for(int i = 0; i < col_students; ++i)
    {
        file << students[i].get_name() << "," << students[i].get_fam() << "," << students[i].grup << endl;
    }
    file.close();
}