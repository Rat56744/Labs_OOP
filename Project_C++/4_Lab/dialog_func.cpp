#include "../4_Lab/stdfax.h"
#include "../4_Lab/people.h"
using std::setw, std::setfill;

void dialog_func()
{

    cout << "\t\t\tДиалоговое окно!\n";
    
    string string_1 = "Добавить информацию о новом студенте\t";
    string dot_1 = "............................";
    string string_3 = "Поиск студентов по номеру группы\t";
    string dot_3 = "............................";
    string string_4 = "Определить всех студентов заданной группы\t";
    string dot_4 = "....................";
    string string_5 = "Сортировка people по фамилии\t";
    string dot_5 = "....................................";
    string string_7 = "Выход из программы\t";
    string dot_7 = "............................................";

    cout << string_1 << dot_1 <<" 1\n";
    cout << string_4 << dot_4 <<" 2\n";
    cout << string_3 << dot_3 <<" 3\n";
    cout << string_5 << dot_5 <<" 4\n";
    cout << string_7 << dot_7 <<" 5\n";
    cout <<setfill('-')<<setw(70)<<'-'<<setfill(' ')<<'\n';
    cout << "Введите номер функции: \n";
}