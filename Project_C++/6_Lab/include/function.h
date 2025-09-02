#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <fstream>
#include "people.h" 

void add_people(
    vector<shared_ptr<common>>& people, 
    unordered_map<string, 
    vector<int>>& grupsMap, 
    vector<int>& numbers_grup , 
    vector<string>& directions, 
    vector<int>& max_stud, 
    vector<int>& max_prep);

void read_of_file(
    ifstream& file,
    vector<shared_ptr<common>>& people, 
    unordered_map<string, 
    vector<int>>& grupsMap, 
    vector<int>& numbers_grup , 
    vector<string>& directions, 
    vector<int>& max_stud, 
    vector<int>& max_prep);

void baze_data(
    vector<std::shared_ptr<common>>& people, 
    vector<int>& max_stud, 
    vector<int>& max_prep);

void find_stud_num_grup(
    vector<std::shared_ptr<common>>& people, 
    vector<int>& number_grup, 
    vector<int>& max_stud);
    
void find_stud_to_grup(
    vector<std::shared_ptr<common>>& people, 
    vector<student>& RStud, 
    unordered_map<string,vector<int>>& grupsMap, 
    vector<int>& number_grup, 
    vector<int>& max_stud);

void sort_fam(vector<shared_ptr<common>>& people);

void dialog_func();

void write_file(
    vector<std::shared_ptr<common>>& people, 
    vector<int>& max_stud, 
    vector<int>& max_prep);

void find_people(
    const vector<shared_ptr<common>>& people,
     vector<int>& max_stud,
     vector<int>& max_prep);