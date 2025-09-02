#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include "../3_Lab/student.h"
#include "../3_Lab/man.h"

//Сортируем от большего к меньшему(лексикографический порядок)
void student_sort_fam(vector<student>& MStud)
{
    int col = 0;
    student a;
    do
    {
        col = 0;
        for(int i = 0;i<MStud.size()-1;++i)
        {
            if(MStud[i].get_fam() < MStud[i+1].get_fam())
            {a = MStud[i];
            MStud[i] = MStud[i+1]; // Меняем местами больший и меньший элемент
            MStud[i+1] = a;
            ++col;}
        }
    }
    while(col!=0);
}