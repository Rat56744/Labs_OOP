#include "stdfax.h"
#include "exceptions.h"
#include "man.h"
#include <iomanip>
#include "fio.h"
using std::setw, std::vector, std::cout, std::string, std::cin;

void fio::display(vector<int>& max_prep) const
{
    cout <<setw(max_prep[0]+3)<<name<<setw(max_prep[1]+3)<<surname<<setw(max_prep[2]+3)<<patronymic;
}

fio::fio(vector<int>& max_prep): man(max_prep)
{
    cout << "patronomic: ";
    set_param(patronymic,cin);
    if(patronymic.size() > max_prep[2]){max_prep[2] = patronymic.size();}
}

fio& fio::operator=(const fio& other)
{
    patronymic = other.patronymic;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const fio& teach)
{
    stream << teach.patronymic;
    return stream;
}

fio::fio(vector<string>& tokens):man(tokens), patronymic(tokens[3]){}

fio::fio()
{
    patronymic = "undefinded patronymic";
}