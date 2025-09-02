#include "../4_Lab/stdfax.h"
#include "../4_Lab/man.h"
using std::setw, std::numeric_limits;

void man::display(vector<int>& max) const
{
    cout << setw(max[0]+5)<<name<<setw(max[1]+5)<<surname;
}

man::man(vector<int>& max)
{
    cout << "name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);    
    if(name.size() > max[0]){max[0] = name.size();}
    
    cout << "surname: ";
    getline(cin, surname);
    if(surname.size() > max[1]){max[1] = surname.size();}
}

man::man(){
    name = "undefinded name";
    surname = "undefinded surname";}