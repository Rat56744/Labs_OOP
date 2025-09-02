#pragma once
#include "stdfax.h"
#include "man.h"
#include "common.h"

class student:public common
{
    private:
        man Man;
        std::string direction;
        int grup;
        static int count;
    public:

        // Перегруженные операторы
        friend std::ostream& operator<<(std::ostream& stream, const student& stud);
        student& operator=(const student& other);


        // Методы класса
        int get_count() const{return count;}
        std::string get_name() const{return Man.name;}
        std::string get_surname() const{return Man.surname;}
        std::string get_direction() const{return direction;}
        bool is_student() const{return true;}
        int get_grup() const{return grup;}
        void display(std::vector<int>& max_stud) const override;

        // Конструкторы класса
        student(std::unordered_map<std::string, std::vector<int>>& grupsMap, std::vector<std::string>& tokens, std::vector <int>& numbers_grup, std::vector<std::string>& directions);
        student(std::unordered_map<std::string, std::vector<int>>& grupsMap, std::vector<int>& numbers_grup, std::vector<std::string>& directions, std::vector<int>& max_stud);
        student(const student& stud);
        student();
        ~student(){--count;}
};