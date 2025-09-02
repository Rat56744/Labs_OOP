#include "../4_Lab/stdfax.h"
#include "../4_Lab/common.h"
#include <iomanip>
#include "../4_Lab/teacher.h"

using std::setw;

string enum_to_string(Department dep)
{
    switch (dep) // Хитрейшим способом преобразуем наше поле в строчку для понятного вывода
       {case VM_1: return "VM_1";
        case IB: return "IB";
        case MIUP: return "MIUP";
        case TKS: return "TKS";
        case AMF: return "AMF";
        default: return "Unknown";}}

void teacher::initialization_enum(vector<int>& max_prep)
{
    int input;
    bool cin_complete = false;
    cout << "Вводим Department (0=VM_1, 1=IB, 2=MIUP, 3=TKS, 4=AMF): ";
    do{
        string buff;
        getline(cin, buff);
        input = stoi(buff);
        if (input >= 0 && input <= 4) {
            department = static_cast<Department>(input);
            cin_complete = true;
        } else {
            cout << "Попробуйте еще раз..." << "\n";
        }
    }while(input >= 0 && input <= 4 && cin_complete == false);
}

void teacher::display(vector<int>& max_prep) const
{
    prep.display(max_prep);
    cout<<setw(max_prep[3]+3)<<enum_to_string(department)<<setw(max_prep[4]+3)<<academical_course<<'\n';
}

teacher::teacher(vector<int>& max_prep): prep(max_prep)
{
    cout<< "Department: ";
    initialization_enum(max_prep);
    cout<<"\n"<< "Academical_course: ";
    getline(cin, academical_course);
}

teacher::teacher(vector<string>& tokens):prep(tokens), department(static_cast<Department>(stoi(tokens[4])))/*Преобразование считанного числа в enum*/
, academical_course(tokens[5]){
    //cout << "Конструктор преподавателя\n";
    }

int teacher::get_department(){return static_cast<int>(department);}

string teacher::get_academical_course(){return academical_course;}