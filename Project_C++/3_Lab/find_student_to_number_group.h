#include "../3_Lab/student.h"
#include "../3_Lab/baze_data.h"

void find_stud_to_num_grup(vector<student>& MStud, vector<int>& numbers_grup, vector<int>& max)
{
    string str = "Номера групп: ";
    cout <<setw(25)<<left<< str;
    for (int a : numbers_grup) {
        cout <<setw(max[3]+5)<<left<< a;
    }
    cout << "\n";

    cout <<setw(2+10+7)<<right<<"Цифра: ";
    for (int i = 0; i < numbers_grup.size(); i++)
    {
        cout <<setw(max[3]+5)<<left<< i+1;
    }
    cout << "\n\n";

    cout << "Ввод продолжается до того момента пока вы не введете соответствующую цифру, указанную на экране:\n";
    int i_grup; // index grup 
    do
    {
        cin >> i_grup;
    } while (i_grup > numbers_grup.size() || i_grup < 1);
    cout << "\n\n";

    vector<student> stud_with_right_index;

    for(int i=0; i<MStud.size();++i)
    {if(MStud[i].get_grup()==numbers_grup[i_grup-1])
        {stud_with_right_index.push_back(MStud[i]);}}
    cout << "Массив студентов с номером группы "<< numbers_grup[i_grup-1]<<":\n";
    baze_data(stud_with_right_index, max);
}