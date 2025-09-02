#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include "../3_Lab/student.h"
#include "../3_Lab/man.h"

using namespace std;
vector<string> Split_line(const string& line, char delimeter)
{
    stringstream ss(line);
    vector<string> tokens;
    string token;

    while(getline(ss,token,delimeter)){tokens.push_back(token);}
    return tokens;
}

void read_of_file(unordered_map<string, vector<int>>& grupsMap ,ifstream& file, vector<student>& MStud, vector<int>& numbers_grup, vector<string>& directons, vector<int>& max)
{
    string line;

    while(getline(file,line))
    {
      vector<string> tokens = Split_line(line, ',');
      if (MStud.capacity()==0)
        {
            MStud.reserve(stoi(tokens[0]));
            max[0]=stoi(tokens[1]);
            max[1]=stoi(tokens[2]);
            max[2]=stoi(tokens[3]);
            max[3]=stoi(tokens[4]);
        }
        else{MStud.emplace_back(grupsMap, tokens, numbers_grup, directons, max, man(tokens));}
    }
}