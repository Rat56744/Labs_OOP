#include "stdfax.h"
#include "common.h"
#include "exceptions.h"
#include <iomanip>
#include "teacher.h"
#include "Error.h"

using std::setw, std::vector, std::cout, std::string, std::cin;

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
    while(true){
        string buff;
        try{
            getline(cin, buff);
            input = stoi(buff);
            if (input < 0 || input > 4) {
                throw Error("Число не в диапазоне от 0 до 4");
            }}
        catch (const std::invalid_argument&) {
            cout << "Ошибка: введено не число\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::out_of_range&) {
            cout << "Ошибка: число выходит за пределы int\n";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch(Error& e){
            cout << "Ошибка: "<< e.what()<<'\n';
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
    }
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
    set_param(academical_course,cin);
}

std::ostream& operator<<(std::ostream& stream, const teacher& teach)
{
    stream << teach.prep;
    stream << enum_to_string(teach.department)<< teach.academical_course<<'\n';
    return stream;
}


teacher& teacher::operator=(const teacher& other)
{
    department = other.department;
    academical_course = other.academical_course;
    return *this;
}


teacher::teacher(vector<string>& tokens):prep(tokens), department(static_cast<Department>(stoi(tokens[4])))/*Преобразование считанного числа в enum*/
, academical_course(tokens[5]){
    //cout << "Конструктор преподавателя\n";
    }

int teacher::get_department(){return static_cast<int>(department);}
string teacher::get_department_string(){return enum_to_string(department);}

string teacher::get_academical_course(){return academical_course;}