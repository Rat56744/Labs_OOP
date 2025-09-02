#pragma once 
#include "student.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#define  N  100

using namespace std;

void students_in(student *&students, int &col_students, string *&direction, int &col_direction, int *&numbers, int &col_numbers, int *&max)
{
    for(int i{}; i < col_students; i++)
    {
        struct student A;

        char call[N]{};

        cout << "Имя: ";
        cin >> call;
        A.F_n_L_n.first_name = new char[N]{};
        strcpy(A.F_n_L_n.first_name, call);
        if(string(A.F_n_L_n.first_name).length() > max[0])
        {
            max[0] = string(A.F_n_L_n.first_name).length(); // Обновляем максимум для имени
        }

        cout << "Фамилия: ";
        cin >> call;
        A.F_n_L_n.last_name = new char[N]{};
        strcpy(A.F_n_L_n.last_name ,call);
        if(string(A.F_n_L_n.last_name).length() > max[1])
        {
            max[1] = string(A.F_n_L_n.last_name).length(); // Обновляем максимум для фамилии
        }
        /////////////////////////////////////////////////////////////////////////

        cout << "Дата рождения: \nВводить через пробел в формате: дд(число) мм(Название месяца) гггг(число)";
        
        int date{};
        cout << "Дата: ";
        cin >> date;
        A.birthday.date = date;

        cout << "Месяц: ";
        cin >> call;
        A.birthday.month = new char[N]{};
        strcpy(A.birthday.month, call);

        int date{};
        cout << "Год: ";
        cin >> date;
        A.birthday.year = date;
        /////////////////////////////////////////////////////////////////////////
        cout << "Направление подготовки: ";
        cin >> call;
        A.direction = new char[N]{};
        strcpy(A.direction ,call);
        if(string(A.direction).length() > max[2])
        {
            max[2] = string(A.direction).length(); // Обновляем максимум для направления
        }
        
        int num{};
        for (int j{}; j < i+1; j++)
        {
            switch (i)
            {
            case 0:
                direction[0] = A.direction;
                ++col_direction;
                break;
            
            default:
            if (direction[j] == A.direction)
            {
                ++num;
            }
                break;
            }
        }
        if (num == 0 && i != 0)
        {
            direction[col_direction] = A.direction;
            ++col_direction;
        }
        

        int group_number{};
        cout << "Номер группы: ";
        cin >> group_number;
        A.num_group = group_number;
        if((to_string(A.num_group)).length() > max[3])
        {
            max[3] = (to_string(A.num_group)).length(); // Обновляем максимум для номера группы
        }
        
        num = 0;
        for (int j{}; j < i+1; j++)
        {
            switch (i)
            {
            case 0:
                numbers[0] = A.num_group;
                ++col_numbers;
                break;
            
            default:
            if (numbers[j] == A.num_group)
            {
                ++num;
            }
                break;
            }
        }
        if (num == 0 && i != 0)
        {
            numbers[col_numbers] = A.num_group;
            ++col_numbers;
        }

        students[i] = A;
    }

    // for (int i = 0; i < col_direction; i++)
    // {
    //     cout << direction[i];
    // }
    // cout << endl;
    
    // for (int i = 0; i < col_numbers; i++)
    // {
    //     cout << numbers[i];
    // }
    // cout << endl;
}