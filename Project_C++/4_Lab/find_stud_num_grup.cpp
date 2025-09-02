#include <iostream>
#include "../4_Lab/stdfax.h"
#include "../4_Lab/people.h"
using std::setw, std::left, std::right;

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
    do
    {
        cin >> i_grup;
    } while (i_grup > number_grup.size() || i_grup < 1);
    cout << "\n\n";

    vector<student> stud_with_correct_index;

    for(int i=0; i < people.size();++i)
    {if (auto stud = dynamic_cast<student*>(people[i].get())) {  // stud != nullptr → приведение успешно
        if(stud->get_grup() == number_grup[i_grup-1]){stud_with_correct_index.emplace_back(*stud);}
    }}
    cout << "Массив студентов с номером группы "<< number_grup[i_grup-1]<<":\n";
    baze_data(stud_with_correct_index, max_stud);
}