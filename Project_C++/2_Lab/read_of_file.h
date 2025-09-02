#pragma once
#include "../2_Lab/Student.h"
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

void read_of_file(ifstream &file, student *&students, int& col_students, int *&numbers, int &col_numbers, int *max) {
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
            max[2] = stoi(tokens[3]); // Номер группы
            ++i;}
        else{A[i-1].read_of_file_student(A, max, numbers, col_numbers, i, tokens);}
    }
    students = A;
    A = nullptr;

}
