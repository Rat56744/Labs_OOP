#pragma once
#include <iomanip>
#include <vector>
#include <iostream>
#include "../3_Lab/student.h"
using std::cout, std::cin, std::string, std::vector, std::ostream, std::istream;
using std::setw, std::to_string, std::max, std::numeric_limits, std::streamsize;

class student;

class man
{
private:
    string name;
    string fam;
public:
    // Методы класса
    string get_name();
    string get_fam();
    void set_name(string name);
    void set_fam(string fam);
    void man_out(const vector<int>& max);

    // Перегруженные операторы
    man& operator=(const man& other);
    friend istream& operator>>(istream& stream, man& Man);
    friend ostream& operator<<(ostream& stream, const man& Man);

    // Конструкторы (Деструктор излишен)
    man(vector<int>& max);
    man(vector<string>& tokens);
    man();
    friend student;
};

// Оператор ввода для класса man
istream& operator>>(istream& stream, man& Man)
{
    cout << "\n";
    cout << "name: ";
    getline(stream, Man.name);
    cout << "fam: ";
    getline(stream, Man.fam);
    return stream;
}

ostream& operator<<(ostream& stream, const man& Man)
{
    stream << Man.name;
    stream << Man.fam;
    return stream;
}

// Оператор присваивания
man& man::operator=(const man& other)
{
    name = other.name;
    fam = other.fam;
    return *this;
}

string man::get_name(){return name;}

void man::set_name(string name){this->name = name;}

string man::get_fam(){return fam;}

void man::set_fam(string fam){this->fam = fam;}

man::man(vector<int>& max)
{
    cout << "name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);    
    if(name.size() > max[0]){max[0] = name.size();}
    
    cout << "fam: ";
    getline(cin, fam);
    if(fam.size() > max[1]){max[1] = fam.size();}
}

man::man(vector<string>& tokens): name(tokens[0]), fam(tokens[1]){}

void man::man_out(const vector<int>& max){cout << setw(max[0]+5)<<name<<setw(max[1]+5)<<fam;}

man::man(){
            name = "undefinded name";
            fam = "undefinded fam";}