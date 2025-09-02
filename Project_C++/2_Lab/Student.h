#pragma once
#include <iostream>
#include <cstring>
#include <vector>

#define N 100
using namespace std;

class student
{
    char* fam;
    char* name;
    static int count;
    
public:
    int grup;

    student();
    ~student();

    void set_student(student *&students,int *max, int *&numbers, int &col_numbers);
    void cout_student_as_field(int *max);
    void view_count();
    int return_count();
    char* get_name();
    char* get_fam();
    int get_grup();
    void set_name(char*a);
    void set_fam(char*a);
    void set_grup(int a);
    void read_of_file_student(student *&A, int *max, int *&numbers, int &col_numbers, int &i, vector<string>&tokens);
    void find_student(student *&students, int *&max);
};
int student::count = 0;

class Students : public student
{
private:
    int col_students;
public:   
    student * students;
    using student::student;
    void set_student(Students *&students,int *max, int *&numbers, int &col_numbers);
};

void Students::set_student(Students *&students,int *max, int *&numbers, int &col_numbers)
{
    char call[N]{};

    cout << "Имя: ";
    cin >> call;
    cout << "Произошел ввод\n";
    cout << endl<< endl;
    strcpy(get_name(), call);
    if(string(get_name()).length() > max[0])
    {
        max[0] = string(get_name()).length(); // Обновляем максимум для имени
    }

    cout << "Фамилия: ";
    cin >> call;
    cout << endl<< endl;
    strcpy(get_fam() ,call);
    if(string(get_fam()).length() > max[1])
    {
        max[1] = string(get_fam()).length(); // Обновляем максимум для фамилии
    }

    cout << "Номер группы: ";
    cin >> grup;
    cout << endl<< endl;
    if((to_string(grup)).length() > max[3])
    {
        max[3] = (to_string(grup)).length(); // Обновляем максимум для номера группы
    }
    
    for(int i{}; i < /*Ничего тут нет*/0; ++i)
    {   
        int num = 0;
        for (int j{}; j < col_numbers; j++)
        {
            switch (col_numbers)
            {
            case 0:
                numbers[0] = grup;
                ++col_numbers;
                break;
            
            default:
            if (numbers[j] == students[i].grup || students[i].grup == -1)
            {
                ++num;
            }
                break;
            }
        }   
        if (num == 0 && i != 0)
        {
            numbers[col_numbers] = students[i].grup;
            ++col_numbers;
        }

    }
}

void student::view_count()
{
    cout << count;
}

int student::return_count()
{
    return count;
}

char* student::get_name()
{
    return name;
}

char* student::get_fam()
{
    return fam;
}

int student::get_grup()
{
    return grup;
}

void student::set_fam(char*a)
{
    strcpy(fam, a);
}

void student::set_name(char*a)
{
    strcpy(name, a);
}

void student::set_grup(int a)
{
    grup = a;
}

void student::set_student(student *&students,int *max, int *&numbers, int &col_numbers)
{
    char call[N]{};

    cout << "Имя: ";
    cin >> call;
    cout << "Произошел ввод\n";
    cout << endl<< endl;
    strcpy(name, call);
    if(string(name).length() > max[0])
    {
        max[0] = string(name).length(); // Обновляем максимум для имени
    }

    cout << "Фамилия: ";
    cin >> call;
    cout << endl<< endl;
    strcpy(fam ,call);
    if(string(fam).length() > max[1])
    {
        max[1] = string(fam).length(); // Обновляем максимум для фамилии
    }

    cout << "Номер группы: ";
    cin >> grup;
    cout << endl<< endl;
    if((to_string(grup)).length() > max[3])
    {
        max[3] = (to_string(grup)).length(); // Обновляем максимум для номера группы
    }
    
    for(int i{}; i < count; ++i)
    {   
        int num = 0;
        for (int j{}; j < col_numbers; j++)
        {
            switch (col_numbers)
            {
            case 0:
                numbers[0] = grup;
                ++col_numbers;
                break;
            
            default:
            if (numbers[j] == students[i].grup || students[i].grup == -1)
            {
                ++num;
            }
                break;
            }
        }   
        if (num == 0 && i != 0)
        {
            numbers[col_numbers] = students[i].grup;
            ++col_numbers;
        }

    }
}

void student::cout_student_as_field(int *max)
{
    cout <<setw(max[0]+5)<<left<< name;
    cout <<setw(max[1]+5)<<left<< fam;
    cout <<setw(max[2]+5)<<left<< grup <<endl;
}

void student::read_of_file_student(student *&A, int *max, int *&numbers, int &col_numbers, int &i, vector<string>&tokens)
{
    strcpy(A[i-1].name,tokens[0].c_str());// Имя(копируем посимвольно)
    if(string(A[i-1].name).length() > max[0])
    {
        max[0] = string(A[i-1].name).length(); // Обновляем максимум для имени
    }


    A[i-1].fam = new char[N]{};
    strcpy(A[i-1].fam,tokens[1].c_str()); // Фамилия (копируем посимвольно)
    if(string(A[i-1].fam).length() > max[1])
    {
        max[1] = string(A[i-1].fam).length(); // Обновляем максимум для фамилии
    }

    A[i-1].grup = stoi(tokens[2]);                 // Номер группы
    if((to_string(A[i-1].grup)).length() > max[3])
    {
        max[3] = (to_string(A[i-1].grup)).length(); // Обновляем максимум для номера группы
    }
    
    int num = 0;
    for (int j{}; j < i+1; j++)
    {
        switch (i)
        {
        case 0:
            numbers[0] = A[i-1].grup;
            ++col_numbers;
            break;
        
        default:
        if (numbers[j] == A[i-1].grup)
        {
            ++num;
        }
            break;
        }
    }   
    if (num == 0 && i != 0)
    {
        numbers[col_numbers] = A[i-1].grup;
        ++col_numbers;
    }
    ++i;
}

student::student()
{
    name = new char[N]{"fam"};
    fam = new char[N]{"name"};
    grup = -1;
    ++count;
}

student::~student()
{
    delete[] fam;
    delete[] name;
    fam = nullptr;
    name = nullptr;
    --count;
}