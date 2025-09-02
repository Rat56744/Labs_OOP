#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

enum Department{VM_1=0, IB, MIUP, TKS, AMF};

void initialization_enum(Department department)
{
    int input;
    bool cin_complete = false;
    cout << "Вводим Department (0=VM_1, 1=IB, 2=MIUP, 3=TKS, 4=AMF): ";
    do{
        cin >> input;
        if (input >= 0 && input <= 4) {
            department = static_cast<Department>(input);
            cin_complete = true;
        } else {
            cout << "Попробуйте еще раз..." << "\n";
        }
    }while(input >= 0 && input <= 4 && cin_complete == false);
}

int main()
{
    string str = "pu pu pu";
    string ass = "dsf";
    Department pop;
    cout<< "Department: \n";
    initialization_enum(pop);
    cout << "Something...\n";
    cout << "getline: ";
    getline(cin,ass);
    getline(cin,str);
    cout << "Наша строка после первого getline: "<< str << '\n';
    cout << "getline: ";
    getline(cin, str);
    cout <<"Наша строка после второго getline: "<< str<< '\n';
}