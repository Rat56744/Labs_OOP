#include <iostream>
#include "stdfax.h"
#include "exceptions.h"
#include "people.h"
using std::left, std::right;

void baze_data(vector<student>& MStud, vector<int>& max);

void find_stud_num_grup(vector<std::shared_ptr<common>>& people, vector<int>& number_grup, vector<int>& max_stud){
    string str = "Номера групп: ";
    cout <<setw(25)<<left<< str;
    for (int a : number_grup) {
        cout <<setw(max_stud[3]+5)<<left<< a;
    }
    cout << "\n";

    cout <<setw(2+10+7)<<right<<"Цифра: ";
    for (int i = 0; i < number_grup.size(); i++)
    {
        cout <<setw(max_stud[3]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int i_grup; // index grup
    cin_int(i_grup,1,number_grup.size());
    cout << "\n\n";

    vector<student> stud_with_correct_index;

    for(auto p:people)
    // Т.к. преподаватель всегда возвращает -1, а номер группы всегда >0, то преподаватели всегда будут отсекаться
    // и мы спокойно можем привести к типу студент.
    {if(p->get_grup() == number_grup[i_grup-1]){stud_with_correct_index.emplace_back(*static_cast<student*>(p.get()));}
    }
    cout << "Массив студентов с номером группы "<< number_grup[i_grup-1]<<":\n";
    baze_data(stud_with_correct_index, max_stud);
}