#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#include "../3_Lab/student.h"
#include "../3_Lab/baze_data.h"

using std::cout, std::endl;



void find_stud_to_grup(unordered_map<string, vector<int>>& grupsMap, vector<student>& MStud, vector<student>& RStud, vector<int>& max)
{
    if(RStud.empty()){RStud.clear();}
    // Выбор направления
    string str = "Выберите направление: ";
    cout <<setw(size(str))<<left<< str;
    for (auto it : grupsMap) {
        cout <<setw(max[2]+5)<<left<< it.first;
    }
    cout << "\n";

    string str1 = "Цифра: ";
    cout <<setw(size(str1) + (size(str)- size(str1))/2 + 1)<<right<<"Цифра: ";
    for (int i = 0; i < grupsMap.size(); i++)
    {
        cout <<setw(max[2]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int index_direction;
    do
    {
        cin >> index_direction;
    } while (index_direction > grupsMap.size() || index_direction < 1);
    cout << "\n\n";

    // Выбор группы
    auto it = grupsMap.begin();
    advance(it, index_direction-1);
    str = it->first; // Нужно, чтобы потом красивый вывод оформить
    cout << "Группы соответствующие " << it->first <<": ";
    for(int value : it->second){cout << setw(max[3]+5)<<left<<value;}
    cout << "\n";

    cout <<setw(size(str1) + 18 + size(str))<<right<<"Цифра: ";
    for (int i = 0; i < it->second.size(); i++)
    {
        cout <<setw(max[2]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int index_grup; 
    do
    {
        cin >> index_grup;
    } while (index_grup > it->second.size() || index_grup < 1);

    for(int i=0; i < MStud.size();++i)
    {
        if(MStud[i].get_direction() == it->first && MStud[i].get_grup() == it->second[index_grup-1])
        {
            RStud.emplace_back();
            int j = RStud.size()-1;
            RStud[j] = MStud[i];
        }
    }
    cout << "\n\nRStud:\n";
    baze_data(RStud, max);
    cout << "\n\n";
}