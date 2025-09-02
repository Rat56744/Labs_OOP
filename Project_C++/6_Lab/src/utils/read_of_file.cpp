#include <sstream>
#include "people.h"
#include "stdfax.h"
using std::stringstream;

vector<string> Split_line(const string& line, char delimeter)
{
    stringstream ss(line);
    vector<string> tokens;
    string token;

    while(getline(ss,token,delimeter)){tokens.push_back(token);}
    return tokens;
}

void read_people(vector<shared_ptr<common>>& people, vector<string>& tokens, unordered_map<string, vector<int>>& grupsMap, vector<int>& num_grup , vector<string>& directions);

void read_of_file(ifstream& file,vector<shared_ptr<common>>& people, unordered_map<string, vector<int>>& grupsMap, vector<int>& num_grup , vector<string>& directions, vector<int>& max_stud, vector<int>& max_prep)
{
    string line;
    int col_stud=0;
    int col_prep=0;

    while(getline(file,line))
    {
      vector<string> tokens = Split_line(line, ',');
      if (people.capacity()==0)
        {
            col_stud = stoi(tokens[0]);
            col_prep = stoi(tokens[1]);
            people.reserve(col_prep+col_stud);
            max_stud[0]=stoi(tokens[2]);
            max_stud[1]=stoi(tokens[3]);
            max_stud[2]=stoi(tokens[4]);
            max_stud[3]=stoi(tokens[5]);
            max_prep[0]=stoi(tokens[6]);
            max_prep[1]=stoi(tokens[7]);
            max_prep[2]=stoi(tokens[8]);
            max_prep[3]=stoi(tokens[9]);
            max_prep[4]=stoi(tokens[10]);
        }
        else{read_people(people,tokens,grupsMap,num_grup,directions);}
    }
}

void read_people(vector<shared_ptr<common>>& people, vector<string>& tokens, unordered_map<string, vector<int>>& grupsMap, vector<int>& num_grup , vector<string>& directions)
{
    switch (stoi(tokens[0]))
    {
    case 1:
        /*  С помощью make_shared выделяем память под студента и возвращаем shared_ptr 
            указывающий на наш объект. Можно использовать если нет пользовательского деструктора  */
        people.emplace_back(make_shared<student>(grupsMap, tokens, num_grup, directions)); 
        break;
    
    case 2:
        people.emplace_back(make_shared<teacher>(tokens));
        break;

    default:
        break;
    }}