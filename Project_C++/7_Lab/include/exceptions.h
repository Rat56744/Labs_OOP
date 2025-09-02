#include "stdfax.h"
#include <limits>
#include <cctype>

/// @brief Определяет присутствует в строчке что-то кроме цифр и букв
/// @param str исследуемая строка
/// @return true - строка только из цифр и букв, false - в противном случае 
bool is_alphanumeric_string(const string& str);

/// @brief Функция ввода поля класса с клавиатуры
/// @param field Поле класса, которое мы собираемся ввести с клавиатуры
/// @param stream Входящий поток ввода cin
void set_param(string& field, istream& stream);

/// @brief Функция ввода параметра номера группы
/// @param a Номер группы (int)
/// @param stream Входной поток ввода cin
void read_int(int& a, istream& stream);

/// @brief Функция открывающая файл
void open_file(ifstream& file, const string& student_file);

/// @brief Функция ввода количества людей в случае когда размер файла равен 0
/// @param col_people 
void cin_col_people(int& col_people);

/// @brief Функция ввода числа
/// @param a Поле, в которое мы ходим ввести число
/// @param min Минимальное допустимое значение для параметра "а"
/// @param max Максимальное допустимое значение для параметра "а"
void cin_int(int& a,const int& min,const int& max);