#include "../4_Lab/stdfax.h"
#include "../4_Lab/man.h"
#include <iomanip>
#include "../4_Lab/fio.h"
using std::setw;

void fio::display(vector<int>& max_prep) const
{
    cout <<setw(max_prep[0]+3)<<name<<setw(max_prep[1]+3)<<surname<<setw(max_prep[2]+3)<<patronymic;
}

fio::fio(vector<int>& max_prep): man(max_prep)
{
    cout << "patronomic: ";
    getline(cin, patronymic);
    if(patronymic.size() > max_prep[2]){max_prep[2] = patronymic.size();}
}

fio::fio(vector<string>& tokens):man(tokens), patronymic(tokens[3]){}

fio::fio()
{
    patronymic = "undefinded patronymic";
}