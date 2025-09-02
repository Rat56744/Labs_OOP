#pragma once
#include <iostream>
#include <cstring>

#include "student.h"

#define N 100
using namespace std;
// namespace Test{
void add_new_student(int &col_students, student *&students, string *&direction, int &col_direction, int *&numbers, int &col_numbers, int *&max)
{
    ++col_students;
    student *clock = new student[col_students]{};
    for(int i{}; i < col_students-1; i++)
    {
        clock[i] = students[i];
    }
    delete[] students;
    students = clock;
    
    char call[N]{};
    
    cout << "Имя: ";
    cin >> call;
    cout << endl<< endl;
    students[col_students-1].F_n_L_n.first_name = new char[N]{};
    strcpy(students[col_students-1].F_n_L_n.first_name, call);
    if(string(students[col_students-1].F_n_L_n.first_name).length() > max[0])
    {
        max[0] = string(students[col_students-1].F_n_L_n.first_name).length(); // Обновляем максимум для имени
    }

    cout << "Фамилия: ";
    cin >> call;
    cout << endl<< endl;
    students[col_students-1].F_n_L_n.last_name = new char[N]{};
    strcpy(students[col_students-1].F_n_L_n.last_name ,call);
    if(string(students[col_students-1].F_n_L_n.last_name).length() > max[1])
    {
        max[1] = string(students[col_students-1].F_n_L_n.last_name).length(); // Обновляем максимум для фамилии
    }


    cout << "Вводить через пробел в формате: дд(число) мм(Название месяца) гггг(число)\nДата рождения:\n";
    cout << endl;
    int date{};
    cout << "Дата: ";
    cin >> date;
    students[col_students-1].birthday.date = date;

    cout << "Месяц: (Выбрать из списка введя соответствущее число)\n";
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; ++i)
    {
        cout <<setw(9+5)<<left<< months[i];
    }
    cout << endl;
    for(int i = 0; i < 12;++i){cout << setw(14) <<left<< i;}
    cout << endl << "Введите номер месяца:";

    do
    {
        cin >> date;
    } while (date > 12 || date < 1);
    
    students[col_students-1].birthday.month = new char[N]{};
    strcpy(students[col_students-1].birthday.month, months[date]);

    cout << "Год: ";
    cin >> date;
    cout << endl<< endl;
    students[col_students-1].birthday.year = date;

    
    cout << "Направление подготовки: ";
    cin >> call;
    cout << endl<< endl;
    students[col_students-1].direction = new char[N]{};
    strcpy(students[col_students-1].direction ,call);
    if(string(students[col_students-1].direction).length() > max[2])
    {
        max[2] = string(students[col_students-1].direction).length(); // Обновляем максимум для направления
    }

    int number{};
    for (int j{}; j < col_direction; j++)
        {
            if (direction[j] == students[col_students-1].direction)
            {
                ++number;
            }
        }
    if (number == 0)
    {
        direction[col_direction] = students[col_students-1].direction;
        ++col_direction;
    }

    int num{};
    cout << "Номер группы: ";
    cin >> num;
    cout << endl<< endl;
    students[col_students-1].num_group = num;
    if((to_string(students[col_students-1].num_group)).length() > max[3])
    {
        max[3] = (to_string(students[col_students-1].num_group)).length(); // Обновляем максимум для номера группы
    }

    number = 0;
    for (int j{}; j < col_numbers; j++)
        {
            if (numbers[j] == students[col_students-1].num_group)
            {
                ++number;
            }
        }
    if (number == 0)
    {
        numbers[col_numbers] = students[col_students-1].num_group;
        ++col_numbers;
    }

    // for (int i = 0; i < col_numbers; i++)
    // {
    //     cout << numbers[i];
    // }
    // cout << endl;

    // for (int i = 0; i < col_direction; i++)
    // {
    //     cout << direction[i];
    // }
    // cout << endl;
}
// }