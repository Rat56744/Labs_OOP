#include<iostream>
#include<fstream>
#include <iomanip>
#include <cstring> 
#include "../2_Lab/Student.h"
#include "../2_Lab/baze_data.h"
#include "../2_Lab/read_of_file.h"
#include "../2_Lab/dialog_func.h"
#include "../2_Lab/add_new_student.h"
#include "../2_Lab/find_student.h"
#include "../2_Lab/student_grup.h"
#include "../2_Lab/write_file.h"


using namespace std;

int main()
{
    const string student_file = "/mnt/WdHard/институт/C++/Проекты C++/2_Lab/Lab_2_file.txt";

    student *students = nullptr;

    int col_students = 0;

    // Массив максимумов где 0 - Имя, 1 - Фамилия, 2 - группа 3 - номер группы
    int *max = new int[3]{10, 10, 10};

    //  Массив различных номеров групп и их счетчик
    int *numbers = new int[N]{};
    int col_numbers{};


    ifstream file;  // Объект на чтение
    file.open(student_file, ios::in);  //  ios::in - только чтение 
    if(!file.is_open())  // Проверяем открылся или нет
    {
        cout << "Файл не открылся" << endl;
        return 1;
    }

    std::streampos fsize = file.tellg();  //  Запоминаем адрес куда указывает курсор
    file.seekg( 0, std::ios::end );  //  Перемещаем курсор в конец файла
    fsize = file.tellg() - fsize;  //  Запоминаем размер файла

    if(fsize == 0)  //  Если размер = 0, то считывание с клавиатуры
    {
        // Вводим с клавиатуры количество объектов
        cout << "Введите количество студентов(не менее 8):";
        cin >> col_students;
        students = new student[col_students];   // Массив студентов

        for(int i = 0; i < col_students; ++i)
        {
            students[i].set_student(students, max, numbers, col_numbers);
        }
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

        read_of_file(file_read,students,col_students,numbers,col_numbers,max);
    }

    //////////////////////////////////////////////////////////////////////////////

    int a;
    do{
    cout << endl << endl;
    baze_data(students, col_students, max); // Вывод всей информации в файле
    dialog_func(); // Диалоговая функция
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "Первая функция" << endl;
        add_new_student(students, col_students, numbers, col_numbers, max);
        break;

    case 2:
        cout << "Вторая функция" << endl;
        find_student(students, col_students, max);
        break;

    case 3:
        cout << "Третья функция" << endl;
        students_grup(students, col_students, numbers, col_numbers, max);
        break;

    case 4:
        cout << "Четвертая функция" << endl;
        cout << "Количество созданных объектов: " << students[0].return_count();
        break;
    
    case 5: // Выход из программы
        // Сохранить все изменения на диске
        break;

    default:
        cout << "Ой! Что-то пошло не так! Попробуйте еще раз ввести число." << endl;
        break;
    }
    }while( a != 5);

    fstream file_write;
    file_write.open(student_file, ios::out);
    if(!file_write.is_open())
    {
        cout << "Файл не открылся" << endl;
        return 1;
    }
    write_file(file_write, col_students, students, max); // Функция записи в фаил нашей базы данных

    delete[] students;
    delete[] max;
    delete[] numbers;
}