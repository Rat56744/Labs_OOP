#include <iostream>
#include <functional>
#include "stdfax.h"
#include "people.h"

void sort_fam(vector<shared_ptr<common>>& people)
{

    std::sort(begin(people), end(people), [](shared_ptr<common>& a, shared_ptr<common>& b){
        return a->get_surname() < b->get_surname(); // Сортировка по возрастанию в алфавитном порядке
    });
}