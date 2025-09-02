#include <iostream>
#include <fstream>
#include <limits>
using std::ifstream, std::numeric_limits, std::cout, std::cin, std::streamsize;

template<class X>
void input_arr_element(std::istream& str, X& x)
{  while(true){
    str >> x;
    if(str.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неккоректный ввод! Попробуйте еще раз)\n";}
    else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;}
    }
}

template<class X>
void initialization_mass(X x[], const int& size)
{
    cout << "\tИнициализация массива типа "<<typeid(X).name()<<" с клавиатуры\n";
    cout << "Всего элементов в массиве: "<<size<<'\n';
    for(int i=0; i<size;++i)
    {
        cout << "Введите "<<i+1<<"-й элемент массива: ";
        input_arr_element(cin, x[i]);
        cout << '\n';
    }
}

template<class X>
void print_mass(X x[], const int& size, const int& n)
{
    cout << "\n\nРазмер строки: "<<n<< " символов\n";
    cout << "Размер массива " << size << '\n';
    for(int i=0;i<size;++i)
    {
        if((i+1)%n != 0){cout<< x[i] << ' ';}
        else{ cout << x[i] << '\n';} // Завершаем строчку
    }
    cout <<"\n";
}

void initialization_mass(char x[], const int& size)
{
    cout << "\tИнициализация массива типа char с клавиатуры\n";
    cout << "Всего элементов в массиве: "<<size<<'\n';
    for(int i=0; i<size;++i)
    {
        while(true){
        cout << "Введите "<<i+1<<"-й элемент массива: ";
        cin.get(x[i]); // Считываем один символ
        if(x[i] == '\n') {
            cout << "Ошибка! Пустой ввод не допускается.\n";
            continue;
        }
        if (cin.fail() || isdigit(x[i])) {
            cin.clear();
            cout << "Ошибка! Введите букву или спецсимвол.\n";}
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            break;}
        cout << '\n';}
    } 
}