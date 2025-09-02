#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <iomanip>
#include "people.h"
using std::left, std::setfill;

void baze_data(vector<std::shared_ptr<common>>& people, vector<int>& max_stud, vector<int>& max_prep)
{
    cout << "\t\t\t\tБаза данных\n";
    cout <<setfill('*')<<setw(max_prep[0]+max_prep[1]+max_prep[2]+max_prep[3]+max_prep[4]+15)<<'*'<<setfill(' ')<<'\n';
    // Вывод преподавателей
    cout<<"\n\nПреподаватели:\n";
    cout<<setw(max_prep[0]+3)<<left<<"Name";
    cout<<setw(max_prep[1]+3)<<left<<"Surname";
    cout<<setw(max_prep[2]+3)<<left<<"Partonymic";
    cout<<setw(max_prep[3]+3)<<left<<"Department";
    cout<<setw(max_prep[4]+3)<<left<<"Academical course"<<'\n';
    cout<<setfill('-')<<setw(max_prep[0]+max_prep[1]+max_prep[2]+max_prep[3]+max_prep[4]+15)<<'-'<<setfill(' ')<<'\n';
    int col_prep = 0; // Счетчик преподавателей
    for(int i = 0; i < people.size(); ++i)
    {
        if(auto teach = dynamic_cast<teacher*>(people[i].get())){
            ++col_prep;
            teach->display(max_prep);} // Проходимся по массиву и выводим только преподавателей
    }
    cout <<setfill('-')<<setw(max_prep[0]+max_prep[1]+max_prep[2]+max_prep[3]+max_prep[4]+15)<<'-'<<setfill(' ')<<'\n';
    cout << "Количество преподавателей: " << col_prep << "\n\n\n";

    // Вывод студентов
    cout <<setw(max_stud[0]+5)<<left<<"First name";
    cout <<setw(max_stud[1]+5)<<left<<"Last name";
    cout <<setw(max_stud[2]+5)<<left<<"Direction";
    cout <<setw(max_stud[3]+5)<<left<<"Grup" << '\n';
    cout <<setfill('-')<<setw(max_stud[0]+max_stud[1]+max_stud[2]+max_stud[3]+20)<<'-'<<setfill(' ')<<'\n';
    for(int i = 0; i < people.size(); ++i)
    {
        if(auto stud = dynamic_cast<student*>(people[i].get())){
            stud->display(max_stud);} // Проходимся по массиву и выводим только студентов
    }
    int col_obj_stud = 0;
    for(const auto& person: people){
        if(auto stud = dynamic_cast<student*>(person.get())){
            col_obj_stud = stud->get_count();
            break;}
    }
    
    cout <<setfill('-')<<setw(max_stud[0]+max_stud[1]+max_stud[2]+max_stud[3]+20)<<'-'<<setfill(' ')<<'\n';
    cout << "Количество студентов: " << people.size()-col_prep << "\tКоличество объектов: " <<col_obj_stud<< "\n\n\n";
    cout <<setfill('*')<<setw(max_prep[0]+max_prep[1]+max_prep[2]+max_prep[3]+max_prep[4]+15)<<'*'<<setfill(' ')<<'\n';

}

void baze_data(vector<student>& MStud, vector<int>& max)
{
    cout << "\t\t\t\tБаза данных\n";
    cout <<setfill('*')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'*'<<setfill(' ')<<'\n';
    cout <<setw(max[0]+5)<<left<<"First name";
    cout <<setw(max[1]+5)<<left<<"Last name";
    cout <<setw(max[2]+5)<<left<<"Direction";
    cout <<setw(max[3]+5)<<left<<"Grup" << '\n';
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'-'<<setfill(' ')<<'\n';
    for(int i = 0; i < MStud.size(); ++i)
    {
        MStud[i].display(max);
    }
    cout <<setfill('-')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'-'<<setfill(' ')<<'\n';
    cout << "Количество студентов: " << MStud.size() << "\tКоличество объектов: " << MStud[0].get_count() << "\n\n";
    cout <<setfill('*')<<setw(max[0]+max[1]+max[2]+max[3]+20)<<'*'<<setfill(' ')<<'\n';
}