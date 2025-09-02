#include "../3_Lab/student.h"
#include <fstream>
using std::fstream;

void write_file(fstream &file, vector<student> MStud, vector<int> max)
{
    int write_enable = 0;
    cout << "Запсисать данные в фаил?\n\n";
    cout << setw(6)<<left << "Yes"<<setw(6)<<left <<"No"<<"\n";
    cout <<setw(6)<<left<<"1"<<setw(6)<<left<<"0"<<"\n\n";
    read_int(write_enable, cin);
    if(write_enable == 1)
        {file << MStud.size() << ",";
        for(int i = 0; i < max.size(); ++i)
        {
            file << max[i] << ",";
        }
        file << "\n";  // Мы записали первую строчку. В ней хранятся данные о количестве студентов и ширине столбцов
        for(int i = 0; i < MStud.size(); ++i)
        {
            file << MStud[i].get_name() << "," << MStud[i].get_fam() << "," << MStud[i].get_direction() << "," << MStud[i].get_grup() << endl;
        }}
    file.close();
}