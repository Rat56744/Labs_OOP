#include "stdafx.h"
#include <iostream>
#include <cstring> // Используйте <cstring> вместо <string.h> в C++
using namespace std;

class FIO {
    char *familia;     // указатель на строку с фамилией
    char *imya;        // указатель на строку с именем
    char *otchestvo;   // указатель на строку с отчеством

    friend class sotrudnik; // Доступ к закрытым полям класса sotrudnik

public:
    // ИНТЕРФЕЙС КЛАССА FIO
    FIO();              // Конструктор по умолчанию
    ~FIO();             // Деструктор

    // Ввод данных в FIO-объект с клавиатуры
    void define_fio();
};  // -------------------- end FIO

class sotrudnik {
    FIO name;          // ФИО сотрудника (три указателя)
    char *dol;         // Должность (указатель на строку)
    float okl;        // Оклад (сумма оклада)
    static int count; // Число объектов класса sotrudnik

public:
    // ИНТЕРФЕЙС КЛАССА sotrudnik
    sotrudnik();      // Конструктор по умолчанию
    ~sotrudnik();     // Деструктор

    // Методы
    void define(FIO& fnam, char *pd, float ok);
    void display();

    // Доступ к закрытым полям класса
    int get_okl() { return okl; }
    int get_count() { return count; }
};  // ---------------- end sotrudnik

//===================== определения класса FIO
FIO::FIO() {
    cout << "FIO::Конструктор по-умолчанию" << endl;
    familia = new char[60];
    strcpy(familia, " ");
    imya = new char[60];
    strcpy(imya, " ");
    otchestvo = new char[60];
    strcpy(otchestvo, " ");
}

FIO::~FIO() {
    cout << endl << "FIO::Destructor!" << endl;
    delete[] familia;
    delete[] imya;
    delete[] otchestvo;
}

// Ввод данных в FIO-объект с клавиатуры
void FIO::define_fio() {
    char str[40];
    cout << endl << "FIO_object:";
    cout << "Фамилия: ";
    cin >> str;
    familia = new char[strlen(str) + 1];
    strcpy(familia, str);
    
    cout << "Имя: ";
    cin >> str;
    imya = new char[strlen(str) + 1];
    strcpy(imya, str);
    
    cout << "Отчество: ";
    cin >> str;
    otchestvo = new char[strlen(str) + 1];
    strcpy(otchestvo, str);
}

//======================= определения класса sotrudnik
sotrudnik::sotrudnik() {
    cout << "sotrudnik::Конструктор по-умолчанию" << endl;
    name.familia = new char[60]; // Выделение динамической памяти под строку
    strcpy(name.familia, " ");    // Инициализация
    name.imya = new char[60];
    strcpy(name.imya, " ");
    name.otchestvo = new char[60];
    strcpy(name.otchestvo, " ");
    
    dol = new char[60];
    strcpy(dol, " ");
    okl = 0;
    count++; // Счётчик объектов класса
}

sotrudnik::~sotrudnik() {
    cout << endl << "sotrudnik::Destructor!" << endl;
    delete[] name.familia;
    delete[] name.imya;
    delete[] name.otchestvo;
    delete[] dol; // Освобождение памяти для dol
    count--; // Счётчик объектов класса
}

void sotrudnik::define(FIO& fnam, char *pd, float ok) {
    name.familia = fnam.familia;
    name.imya = fnam.imya;
    name.otchestvo = fnam.otchestvo;
    dol = pd;
    okl = ok;
}

void sotrudnik::display() {
    cout << endl;
    cout << name.familia << "  ";
    cout << name.imya << "  ";
    cout << name.otchestvo << " , ";
    cout << dol << " , ";
    cout << "оклад: " << okl << endl;
}

// Область глобальных переменных
int sotrudnik::count = 0; // Создание статической переменной