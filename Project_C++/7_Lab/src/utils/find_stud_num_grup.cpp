#include <iostream>
#include <algorithm>
#include "stdfax.h"
#include "exceptions.h"
#include "people.h"
// using std::left, std::right;
using namespace std;

void baze_data(vector<student>& MStud, vector<int>& max);

void find_stud_num_grup(vector<std::shared_ptr<common>>& people, vector<int>& num_grup, vector<int>& max_stud){
    string str = "Номера групп: ";
    cout <<setw(25)<<left<< str;
    for (auto it{begin(num_grup)}; it != end(num_grup); ++it) {
        cout << setw(max_stud[3]+5) << left << *it;
    }
    cout << endl;

    cout <<setw(2+10+7)<<right<<"Цифра: ";
    for (int i = 0; i < num_grup.size(); ++i)
    {
        cout <<setw(max_stud[3]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int i_grup; // index grup
    cin_int(i_grup,1,num_grup.size());
    cout << "\n\n";

    vector<student> stud_with_correct_index;

    std::for_each(begin(people), end(people), [&](auto &a) {
        if(a->get_grup() == num_grup[i_grup-1]) {
            stud_with_correct_index.emplace_back(*static_cast<student*>(a.get()));
        }
    });
    
    cout << "Массив студентов с номером группы "<< num_grup[i_grup-1]<<":\n";
    baze_data(stud_with_correct_index, max_stud);
}