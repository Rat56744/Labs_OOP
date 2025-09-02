#include <iostream>
#include "stdfax.h"
#include "people.h"

void sort_fam(vector<shared_ptr<common>>& people)
{
    int col = 0;
    shared_ptr<common> a;
    do
    {
        col = 0;
        for(int i=0; i<people.size()-1;++i)
        {
            if(people[i]->get_surname() > people[i+1]->get_surname())
            {a = people[i];
            people[i] = people[i+1]; // Меняем местами больший и меньший элемент
            people[i+1] = a;
            ++col;}
        }
    }
    while(col!=0);
}