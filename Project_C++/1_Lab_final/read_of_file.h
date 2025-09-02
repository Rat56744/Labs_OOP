#include "../1_Lab_final/student.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

#define N 100
using namespace std;

vector<string> splitLine(const string &line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void read_of_file(ifstream &file, student *&students, int &col_students, string *&direction, int &col_direction, int *&numbers, int &col_numbers, int *max) {
    string line;
    student *A = nullptr;

    int i = 0; // Счетчик, который помогает считать первую строку особенным образом

    while (getline(file, line)) { // Читаем документ построчно
        vector<string> tokens = splitLine(line, ','); // Поля считанные из i-1 строки
        if(i == 0){
            col_students = stoi(tokens[0]);
            A = new student[col_students]{};
            max[0] = stoi(tokens[1]); // Имя
            max[1] = stoi(tokens[2]); // Фамилия
            max[2] = stoi(tokens[3]); // Группа
            max[3] = stoi(tokens[4]); // Номер группы
            cout<<"Количество студентов: "<<col_students<<endl;
            ++i;}
        else{
            A[i-1].F_n_L_n.first_name = new char[N]{};
            strcpy(A[i-1].F_n_L_n.first_name,tokens[0].c_str());// Имя(копируем посимвольно)
            if(string(A[i-1].F_n_L_n.first_name).length() > max[0])
            {
                max[0] = string(A[i-1].F_n_L_n.first_name).length(); // Обновляем максимум для имени
            }
    

            A[i-1].F_n_L_n.last_name = new char[N]{};
            strcpy(A[i-1].F_n_L_n.last_name,tokens[1].c_str()); // Фамилия (копируем посимвольно)
            if(string(A[i-1].F_n_L_n.last_name).length() > max[1])
            {
                max[1] = string(A[i-1].F_n_L_n.last_name).length(); // Обновляем максимум для фамилии
            }
    

            A[i-1].birthday.date = stoi(tokens[2]);             // День рождения

            A[i-1].birthday.month = new char[N]{};
            strcpy(A[i-1].birthday.month,tokens[3].c_str());    // Месяц рождения

            A[i-1].birthday.year = stoi(tokens[4]);             // Год рождения

            A[i-1].direction = new char[N]{};
            strcpy(A[i-1].direction,tokens[5].c_str());         // Группа
            if(string(A[i-1].direction).length() > max[2])
            {
                max[2] = string(A[i-1].direction).length(); // Обновляем максимум для направления
            }
            
            int num{};
            for (int j{}; j < i+1; j++)
            {
                switch (i)
                {
                case 0:
                    direction[0] = A[i-1].direction;
                    ++col_direction;
                    break;
                
                default:
                if (direction[j] == A[i-1].direction)
                {
                    ++num;
                }
                    break;
                }
            }
            if (num == 0 && i != 0)
            {
                direction[col_direction] = A[i-1].direction;
                ++col_direction;
            }
           

            A[i-1].num_group = stoi(tokens[6]);                 // Номер группы
            if((to_string(A[i-1].num_group)).length() > max[3])
            {
                max[3] = (to_string(A[i-1].num_group)).length(); // Обновляем максимум для номера группы
            }
                    
            num = 0;
            for (int j{}; j < i+1; j++)
            {
                switch (i)
                {
                case 0:
                    numbers[0] = A[i-1].num_group;
                    ++col_numbers;
                    break;
                
                default:
                if (numbers[j] == A[i-1].num_group)
                {
                    ++num;
                }
                    break;
                }
            }
            if (num == 0 && i != 0)
            {
                numbers[col_numbers] = A[i-1].num_group;
                ++col_numbers;
            }
            ++i;
        }
    }
    students = A;
    A = nullptr;
}
