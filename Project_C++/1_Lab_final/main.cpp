#include "../1_Lab_final/baze_data.h"
#include "../1_Lab_final/dialog_func.h"
#include "../1_Lab_final/students_in.h"
#include "../1_Lab_final/add_new_student.h"
#include "../1_Lab_final/students_direction.h"
#include "../1_Lab_final/student_group.h"
#include "../1_Lab_final/find_oldest_student.h"
#include "../1_Lab_final/find_younger_student.h"
#include "../1_Lab_final/cout_student.h"
#include "../1_Lab_final/student.h"
#include "../1_Lab_final/write_file.h"
#include "../1_Lab_final/read_of_file.h"
#include <iostream>
#include <string>
#include <fstream>

#define  N  100

using namespace std;


int main()
{
    const int min_col_student = 0; 
    const string student_file = "dfjk.txt";

    student *students = nullptr;
    int col_students{};  // Количество студентов

    // Массив максимумов где 0 - Имя, 1 - Фамилия, 2 - группа 3 - номер группы
    int *max = new int[4]{10, 10, 10, 10};

    //  Массив различных номеров групп и их счетчик
    int *numbers = new int[N];
    int col_numbers{};

    string *direction = new string[N]{};  // Массив групп которые мы введем
    int col_direction{};  // Счетчик различных групп

    //  Массив уникальных групп и их счетчик
    int col_group{};
    student *group_students = new student[N]{};

    ifstream file;  // Объект на чтение
    file.open(student_file, ios::in);  //  ios::in - только чтение 
    if(!file.is_open())  // Проверяем открылся или нет
    {
        cout << "Фаил не открылся" << endl;
        return 1;
    }

    std::streampos fsize = file.tellg();  //  Запоминаем адрес куда указывает курсор
    file.seekg( 0, std::ios::end );  //  Перемещаем курсор в конец файла
    fsize = file.tellg() - fsize;  //  Запоминаем размер файла

    if(fsize == 0)  //  Если размер = 0, то считывание с клавиатуры
    {
        // Вводим с клавиатуры количество объектов
        cout << "Введите количество студентов(не менее 8):";
        do
        {cin >> col_students;}
        while (col_students < min_col_student);
        students = new student[col_students]{};   // Массив студентов

        // Переписать функцию
        students_in(students, col_students, direction, col_direction, numbers, col_numbers, max);
    }
    else  //  Если размер != 0, то считываем все поля из файла
    {
        // Считать из файла
        ifstream file_read;
        file_read.open(student_file, ios::in);
        if(!file_read.is_open())
        {
            cout << "Файл не открылся" << endl;
            return 1;
        }

        read_of_file(file_read,students,col_students,direction,col_direction,numbers,col_numbers,max);
    }
    //////////////////////////////////////////////////////////////////////////////
    
    int a;
    do{
    cout << endl << endl;
    baze_data(col_students, students, max); // Вывод всей информации в файле
    dialog_func(); // Диалоговая функция
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "Первая функция" << endl;
        add_new_student(col_students, students, direction, col_direction, numbers, col_numbers, max);
        break;

    case 2:
        cout << "Вторая функция" << endl;
        cout_student(students,col_students,max);
        break;

    case 3:
        cout << "Третья функция" << endl;
        students_direction(students, col_students, direction, col_direction, max);
        break;

    case 4:
        cout << "Четвертая функция" << endl;
        student_group(students, col_students, direction, col_direction, numbers, col_numbers, group_students, col_group, max);
        break;
     
    case 5:
        // Функция поиска самого молодого студента
        cout << "Номер самого молодого студента: " << find_youngest_student(students, col_students)+1 << endl;
        cout_student(students,col_students,max);
        break;
    
    case 6:
        // Функция поиска самого старшего студента
        cout << "Номер самого старшего студента: " << find_oldest_student(students, col_students)+1 << endl;
        cout_student(students,col_students,max);
        break;
    
    case 7: // Выход из программы
        // Сохранить все изменения на диске
        break;

    default:
        cout << "Ой! Что-то пошло не так! Попробуйте еще раз ввести число." << endl;
        break;
    }
    }while( a != 7);

    fstream file_write;
    file_write.open(student_file, ios::out);
    if(!file_write.is_open())
    {
        cout << "Файл не открылся" << endl;
        return 1;
    }
    write_file(file_write, students, col_students, max); // Функция записи в фаил нашей базы данных

    file.close();
    delete [] max;
    delete [] numbers;
    delete [] direction;
    delete [] group_students;
    for(int i = 0; i < col_students;++i)
    {
        delete [] students[i].F_n_L_n.first_name;
        delete [] students[i].F_n_L_n.last_name;
        delete [] students[i].birthday.month;
        delete [] students[i].direction;
    }
}