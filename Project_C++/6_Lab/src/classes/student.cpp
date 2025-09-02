#include "student.h"
#include "stdfax.h"
#include "exceptions.h"

using std::setw, std::vector, std::cout, std::string, std::numeric_limits, std::endl;
using std::unordered_map,std::cin, std::to_string, std::istream, std::streamsize;

int student::count = 0;

void student::display(vector<int>& max_stud) const
{
    Man.display(max_stud);
    cout<<setw(max_stud[2]+5)<<direction<<setw(max_stud[3]+5)<<grup<<'\n';
}



student::student(unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup, vector<string>& directions, vector<int>& max_stud):Man(max_stud)
{
    // Direction
    cout << "Direction: ";
    set_param(direction, cin); // Считываем с помощью getline заранее очистив входной поток

    if(direction.size() > max_stud[2]){max_stud[2] = direction.size();}

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
    if((to_string(grup)).size() > max_stud[3]){max_stud[3] = (to_string(grup)).size();}
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

student::student(unordered_map<string, vector<int>>& grupsMap, vector<string>& tokens, vector <int>& numbers_grup, vector<string>& directions): Man(tokens), direction(tokens[3]), grup(std::stoi(tokens[4]))
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

student::student(const student& stud)
{
    cout << "Конструктор копирования\n";
    Man = stud.Man;
    direction = stud.direction;
    grup = stud.grup;
    ++count;
}

std::ostream& operator<<(std::ostream& stream, const student& stud){
    stream << stud.Man;
    stream << stud.direction;
    stream << stud.grup << '\n';
    return stream;
}

student& student::operator=(const student& other)
{
    // cout << "Перегруженный оператор присваивания.\n";
    Man = other.Man;
    direction = other.direction;
    grup = other.grup;
    return *this;
}

student::student():Man()
{
    direction = "undefinded direction";
    grup =-1;
    ++count;
}