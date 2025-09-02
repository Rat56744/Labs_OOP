#include "stdfax.h"
#include "exceptions.h"
#include "man.h"
using std::setw, std::vector, std::cout,std::cin, std::string, std::numeric_limits;
using std::streamsize;

void man::display(vector<int>& max) const
{
    cout << setw(max[0]+5)<<name<<setw(max[1]+5)<<surname;
}

man::man(vector<int>& max)
{
    cout << "name: ";
    set_param(name,cin);
    if(name.size() > max[0]){max[0] = name.size();}
    
    cout << "surname: ";
    set_param(surname,cin);
    if(surname.size() > max[1]){max[1] = surname.size();}
}

std::ostream& operator<<(std::ostream& stream, const man& Man)
{
    stream << Man.name;
    stream << Man.surname;
    return stream;
}

man& man::operator=(const man& other)
{
    name = other.name;
    surname = other.surname;
    return *this;
}


man::man(){
    name = "undefinded name";
    surname = "undefinded surname";}