#pragma once
#include "../4_Lab/stdfax.h"
#include "../4_Lab/man.h"
#include "../4_Lab/common.h"

class student:public common
{
    private:
        man Man;
        string direction;
        int grup;
        static int count;
    public:
        // Методы класса
        int get_count() const{return count;}
        string get_name() const{return Man.name;}
        string get_surname() const{return Man.surname;}
        string get_direction() const{return direction;}
        bool is_student() const{return true;}
        int get_grup() const{return grup;}
        void display(vector<int>& max_stud) const override;

        // Конструкторы
        student(unordered_map<string, vector<int>>& grupsMap, vector<string>& tokens, vector <int>& numbers_grup, vector<string>& directions);
        student(unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup, vector<string>& directions, vector<int>& max_stud);
        student(const student& stud);
        student();
        ~student(){--count;}
};