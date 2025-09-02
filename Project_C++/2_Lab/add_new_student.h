#pragma once
#include <iostream>
#include <cstring>

#include "../2_Lab/Student.h"

#define N 100
using namespace std;

void add_new_student(student *&students, int& col_students, int *&numbers, int &col_numbers, int *&max)
{
    ++col_students;
    student *clock = new student[col_students]{};
    for(int i{}; i < col_students - 1; ++i)
    {
        //clock[i] = students[i];
        clock[i].set_name(students[i].get_name());
        clock[i].set_fam(students[i].get_fam());
        clock[i].set_grup(students[i].get_grup());
    }
    delete[] students;
    students = clock;
    students[col_students-1].set_student(students, max, numbers, col_numbers);
}