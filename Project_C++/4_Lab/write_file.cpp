#include "../4_Lab/stdfax.h"
#include "../4_Lab/people.h"
using std::setw, std::left;

void read_int(int& a, istream& stream);

void write_file(vector<std::shared_ptr<common>>& people, vector<int>& max_stud, vector<int>& max_prep)
{
    int write_enable = 0;
    cout << "Записать данные в фаил?\n\n";
    cout << setw(6)<<left << "Yes"<<setw(6)<<left <<"No"<<"\n";
    cout <<setw(6)<<left<<"1"<<setw(6)<<left<<"0"<<"\n\n";
    do
    {
        read_int(write_enable, cin);
    } while (write_enable > 1 || write_enable < 0);

    if(write_enable){
        fstream file;
        file.open("file.txt", std::ios::out);
        if(!file.is_open())
        {
            throw "File not open!\n";
        }
        int col_stud=0;
        for(const auto pip: people)
        {
            if(pip->is_student())
            {
                ++col_stud;
            }
        }

        file << col_stud << ','<<people.size()-col_stud<<',';
        for(int i = 0; i < max_stud.size(); ++i) // Максимумы студентов
        {
            file << max_stud[i] << ",";
        }
        for(int i = 0; i < max_prep.size(); ++i) // Максимумы преподавателей
        {
            file << max_prep[i] << ",";
        }
        file << "\n";  // Мы записали первую строчку. В ней хранятся данные о количестве студентов и ширине столбцов
        for(const auto pip: people)
        {
            if(auto stud = dynamic_cast<student*>(pip.get()))
            {file <<'1'<< ","<< stud->get_name() << "," << stud->get_surname() << "," << stud->get_direction() << "," << stud->get_grup() << '\n';}
            else{auto prep = dynamic_cast<teacher*>(pip.get());
            file <<'2'<< ","<< prep->get_name() << "," << prep->get_surname() << "," << prep->get_patronymic() << "," << prep->get_department() << "," << prep->get_academical_course() <<'\n';
            }
        }
        file.close();}
}