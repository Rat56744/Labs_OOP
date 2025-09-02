#include <fstream>
#include <iomanip>
#include <cstring> 
#include <unordered_map>
#include <iostream>
#include <vector>

#include "../3_Lab/student.h"
#include "../3_Lab/baze_data.h"
#include "../3_Lab/read_of_file.h"
#include "../3_Lab/find_student_to_grup.h"
#include "../3_Lab/find_student_to_number_group.h"
#include "../3_Lab/student_sort_fam.h"
#include "../3_Lab/write_file.h"
#include "../3_Lab/dilog_func.h"
#define N 100

using namespace std;

int main()
{   
    const string student_file = "baze_students_3_lab.txt";

    vector<student> MStud;
    vector<student> RStud;

    unordered_map<string, vector<int>> grupsMap; // 

    // Массив максимумов где 0 - Имя, 1 - Фамилия, 2 - группа, 3 - номер группы
    vector<int> max(4,10);

    //  Массив различных номеров групп
    vector<int> numbers_grup;

    // Массив уникальных групп
    vector<string> directions;

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
        int col_students;
        do{cin>>col_students;}while(col_students < 0);

        for(int i = 0; i < col_students; ++i)
        {
            MStud.emplace_back(grupsMap ,numbers_grup, directions, max, man(max)); // С помощью конструктора с параметрами добавляем нового студента инициализируя студентов внутри конструктора
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

        read_of_file(grupsMap ,file_read,MStud,numbers_grup,directions,max); // Реализовать функцию
    }

  //////////////////////////////////////////////////////////////////////////////

  int a;
  do{
  cout << endl << endl;
  baze_data(MStud, max);// Вывод всей информации в файле
  dialog_func(); // Диалоговая функция
  cin >> a;
  switch (a)
  {
  case 1:
        cout << "Первая функция" << endl;
        MStud.emplace_back(grupsMap, numbers_grup, directions, max, man(max));
        break;

  case 2:
        cout << "Вторая функция" << endl;
        find_stud_to_grup(grupsMap, MStud, RStud, max);
        break;

  case 3:
        cout << "Третья функция" << endl;
        find_stud_to_num_grup(MStud, numbers_grup, max);
        break;

  case 4:
        cout << "Четвертая функция" << endl;
        student_sort_fam(MStud);
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
  write_file(file_write, MStud, max); // Функция записи в фаил нашей базы данных
}