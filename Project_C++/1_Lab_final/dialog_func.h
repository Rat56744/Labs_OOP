#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <stdio.h>



using namespace std;

// namespace Test{
void dialog_func()
{
    cout << "\t\t\tДиалоговое окно!\n" << endl;
    
    string string_1 = "Добавить информацию о новом студенте\t";
    string dot_1 = "............................";
    string string_2 = "Распечатать информацию о студенте в табличном виде\t";
    string dot_2 = "............";
    string string_3 = "Определить всех студентов по заданному направлению подготовки\t";
    string dot_3 = "....";
    string string_4 = "Определить всех студентов заданной группы\t";
    string dot_4 = "....................";
    string string_5 = "Найти самого старшего студента\t";
    string dot_5 = "....................................";
    string string_6 = "Найти самого младшего студента\t";
    string dot_6 = "....................................";
    string string_7 = "Выход из программы\t";
    string dot_7 = "............................................";

    cout << string_1 << dot_1 <<" 1" << endl;
    cout << string_2 << dot_2 <<" 2" << endl;
    cout << string_3 << dot_3 <<" 3" << endl;
    cout << string_4 << dot_4 <<" 4" << endl;
    cout << string_5 << dot_5 <<" 5" << endl;
    cout << string_6 << dot_6 <<" 6" << endl;
    cout << string_7 << dot_7 <<" 7" << endl;
    cout <<setfill('.')<<setw(70)<<'.'<<setfill(' ')<<endl;
    cout << "Введите номер функции: " << endl;
}
// }