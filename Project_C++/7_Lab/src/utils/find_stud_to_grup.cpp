#include <iostream>
#include <algorithm>
#include "exceptions.h"
#include "stdfax.h"
#include "people.h"
using std::right;

void baze_data(vector<student>& MStud, vector<int>& max);

void find_stud_to_grup(vector<std::shared_ptr<common>>& people, vector<student>& RStud, unordered_map<string,vector<int>>& grupsMap, vector<int>& numbers_grup, vector<int>& max_stud)
{
    if(RStud.empty()){RStud.clear();}
    // Выбор направления
    string str = "Выберите направление: ";
    cout <<setw(size(str))<<left<< str; 
    for (auto it{begin(grupsMap)}; it != end(grupsMap); ++it) {
        cout << setw(max_stud[2]+5) << left << (*it).first;
    }
    cout << "\n";

    string str1 = "Цифра: ";
    cout <<setw(size(str1) + (size(str)- size(str1))/2 + 1)<<right<<"Цифра: ";
    for (int i = 0; i < grupsMap.size(); ++i)
    {
        cout <<setw(max_stud[2]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int index_direction;
    cin_int(index_direction,1,grupsMap.size());
    cout << "\n\n";

    // Выбор группы
    auto it = grupsMap.begin();
    advance(it, index_direction-1);
    str = it->first; // Нужно, чтобы потом красивый вывод оформить
    cout << "Группы соответствующие " << it->first << ": ";
    for(auto iter{begin(it->second)}; iter!=it->second.end();++iter) {
        cout << setw(max_stud[3]+5) << left << *iter;
    }
    cout << "\n";

    cout <<setw(size(str1) + 18 + size(str))<<right<<"Цифра: ";
    for (int i = 0; i < it->second.size(); ++i) {
        cout <<setw(max_stud[2]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int index_grup;
    cin_int(index_grup,1,it->second.size());

    std::for_each(begin(people), end(people), [&](auto &a){
        if(a->is_student()) {
            auto stud = std::static_pointer_cast<student>(a);
            if(stud->get_direction() == it->first && stud->get_grup() == it->second[index_grup-1])
            {
                RStud.emplace_back();
                int j = RStud.size()-1;
                RStud[j] = *stud;
            }}
    });

    cout << "\n\nRStud:\n";
    baze_data(RStud, max_stud);
    cout << "\n\n";
}