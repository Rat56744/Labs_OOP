#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include <unordered_map>
#include "../3_Lab/man.h"

using std::cout, std::unordered_map, std::left, std::right, std::numeric_limits;
using std::streamsize, std::fstream;

class student
{
private:
    man Man;
    string direction;
    int grup;
    static int count;
public:
    // Перегруженные операторы
    friend istream& operator>>(istream& stream, student& stud);
    friend ostream& operator<<(ostream& stream, const student& stud);
    student& operator=(const student& other);

    // Методы класса 
    void student_out(const vector<int>& max);
    string get_direction() const;
    int get_grup() const;
    int get_count() const;
    string get_name() const;
    string get_fam() const;

    // Дружественные функции
    friend void write_file(fstream &file, vector<student> MStud, vector<int> max);

    // Конструкторы (Деструктор излишен)
    student(unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup, vector<string>& direction, vector<int>& max, const man& man);
    student(unordered_map<string, vector<int>>& grupsMap, vector<string>& tokens, vector<int>& numbers_grup, vector<string>& directions, vector<int>& max, const man& man);
    student();
};
void read_int(int& a, istream& stream);
int student::count = 0;

int student::get_grup() const{return grup;}

int student::get_count() const{return count;}

string student::get_name() const{return Man.name;}

string student::get_fam() const{return Man.fam;}

string student::get_direction() const{return direction;}

student& student::operator=(const student& other)
{
    Man = other.Man;
    direction = other.direction;
    grup = other.grup;
    return *this;
}

istream& operator>>(istream& stream, student& stud)
{
    stream >> stud.Man;
    cout << "direction: ";
    stream.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(stream, stud.direction);
    cout << "grup: ";
    read_int(stud.grup, stream);
    return stream;
}

ostream& operator<<(ostream& stream, const student& stud){
    stream << stud.Man;
    stream << stud.direction;
    stream << stud.grup;
    return stream;
}

void student::student_out(const vector<int>& max)
{   
    Man.man_out(max);
    cout <<setw(max[2]+5)<<direction<<setw(max[3]+5)<<grup<< "\n";
}

student::student(unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup, vector<string>& directions, vector<int>& max, const man& man): Man(man)
{
    // Direction
    cout << "direction: ";
    getline(cin, direction); // Считываем с помощью getline заранее очистив входной поток

    if(direction.size() > max[2]){max[2] = direction.size();}

    int num = 0;
    if(directions.size() == 0){directions.push_back(direction);}
    else
    {for (int i=0; i < directions.size(); ++i)
        {
            if (directions[i] == direction){++num;}
        }
        if (num == 0){directions.push_back(direction);}}

    // Grup
    cout << "grup(целое число): ";
    read_int(grup, cin);
    if((to_string(grup)).size() > max[3]){max[3] = (to_string(grup)).size();}
    num = 0;
    if(numbers_grup.size() == 0){numbers_grup.push_back(grup);}
    else{
        for(int i = 0; i < numbers_grup.size();++i)
        {if(numbers_grup[i] == grup){++num;}}
        if(num == 0){numbers_grup.push_back(grup);}}
    ++count;

    // Unordered_map
    num = 0;
    auto it = grupsMap.find(direction);
    if (it != grupsMap.end()) {
        for (int grup_in_map : it->second) {
            if(grup_in_map == grup)
            {++num;}
        }
        if(num == 0){grupsMap[direction].push_back(grup);}
    } else {grupsMap[direction].push_back(grup);}
}

student::student(unordered_map<string, vector<int>>& grupsMap, vector<string>& tokens, vector <int>& numbers_grup, vector<string>& directions, vector<int>& max, const man& men): Man(men), direction(tokens[2]), grup(std::stoi(tokens[3]))
{   
    // Direction
    int num = 0;
    if(directions.size() == 0){directions.push_back(direction);}
    else
    {
        for (int i=0; i < directions.size(); ++i)
        {
            if (directions[i] == direction){++num;}
        }
        if (num == 0){directions.push_back(direction);}
    }

    // Grup
    num = 0;
    if(numbers_grup.size() == 0){numbers_grup.push_back(grup);}
    else{
        for(int i = 0; i < numbers_grup.size();++i)
        {
            if(numbers_grup[i] == grup)
            {++num;}
        }
        if(num == 0){numbers_grup.push_back(grup);}}
    
    // Unordered_map
    ++count;
    num = 0;
    auto it = grupsMap.find(direction);
    if (it != grupsMap.end()) {
        for (int grup_in_map : it->second) {
            if(grup_in_map == grup)
            {++num;}
        }
        if(num == 0){grupsMap[direction].push_back(grup);}
    } else {grupsMap[direction].push_back(grup);}
}

student::student()
{
    direction = "undefinded direction";
    grup =-1;
    ++count;
}

void read_int(int& a, istream& stream)
{
    while (true) {
        stream >> a;
        if (stream.fail()) { // Проверяем удачный ли ввод
            stream.clear(); // Сбрасываем состояние потока
            stream.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            cout << "Ошибка: введите корректное целое число." << std::endl;
        } else {
            break; // Если ввод успешен, выходим из цикла
        }
    }
}