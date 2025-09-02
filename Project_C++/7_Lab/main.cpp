#include "stdfax.h"
#include "people.h"
#include "Error.h"
#include "exceptions.h"
#include "function.h"

int main()
{
    try{
        const string student_file = "file.txt";

        vector<shared_ptr<common>> people;
        vector<student> RStud; // Массив из прошлой лабараторной работы для студентов заданной группы
        
        // Контейнер для хранения direction и соответствующих им grup
        unordered_map<string, vector<int>> grupsMap;

        // Массив максимумов для студентов где 0 - Имя, 1 - Фамилия, 2 - Группа, 3 - Номер группы
        vector<int> max_stud(4,10);
        // Массив максимумов для преподавателей где 0 - Имя, 1 - Фамилия, 2 - Отчество, 3 - Кафедра, 4 - Учебный курс
        vector<int> max_prep{10, 10, 10, 10, 17};

        //  Массив различных номеров групп
        vector<int> numbers_grup;

        // Массив уникальных групп
        vector<string> directions;

        cout << "\tКатегорически вас приветствую!\nЭтот проект представляет из себя базу данных из студентов и преподавателей\n";
        cout << "В каждое строковое поле(по смыслу из букв), к примеру имя, могут вводиться только буквы(заглавные и строчные) и числа\n";
        cout << "Если попробовать ввести какие-либо другие символы, то будет выведено сообщение об ошибке и поле придется ввести снова\n";
        cout << "В каждое цифровое поле(номер... или academical_course), в которое просят ввести именно число, можно ввести только цифры. В противном случае\n";
        cout << "появится сообщение об ошибке и поле придется ввести снова\n";
        cout << "Данные, которые вводятся в базу данных должны быть введени строго на английском языке.\n\n";

        ifstream file;  // Объект на чтение
        try{
            file.open("file.txt", std::ios::out);
            if(!file.is_open())
            {
                throw Error("Файл не открылся!");
            }}
        catch(const Error& e){
            cout << "Ошибка: "<< e.what()<<'\n';
            return 1;}

        std::streampos fsize = file.tellg();  //  Запоминаем адрес куда указывает курсор
        file.seekg( 0, std::ios::end );  //  Перемещаем курсор в конец файла
        fsize = file.tellg() - fsize;  //  Запоминаем размер файла
        file.seekg(std::ios::beg); // Перемещаем курсор в начало файла, чтобы  в дальнейшем мы могли прочитать данные из него

        if(fsize==0){
            // Вводим с клавиатуры количество объектов
            cout << "Введите количество людей(не менее 8):";
            int col_people;
            cin_col_people(col_people);

            for(int i = 0; i < col_people; ++i)
            {
                add_people(people, grupsMap, numbers_grup, directions, max_stud, max_prep);
            }
        }
        else{
            read_of_file(file,people,grupsMap,numbers_grup,directions,max_stud,max_prep); // Реализовать функцию
        }


        //////////////////////////////////////////////////////////////////////////////

        int a;
        do{
            cout <<"\n\n";
            baze_data(people, max_stud, max_prep);// Вывод всей информации в файле
            dialog_func(); // Диалоговая функция
            cin_int(a,1,6);
            switch (a)
            {
            case 1:
                    cout << "Первая функция\n";
                    add_people(people, grupsMap, numbers_grup, directions, max_stud, max_prep);
                    break;

            case 2:
                    cout << "Вторая функция\n";
                    find_stud_to_grup(people,RStud,grupsMap,numbers_grup,max_stud);
                    break;

            case 3:
                    cout << "Третья функция\n";
                    find_stud_num_grup(people,numbers_grup,max_stud);
                    break;

            case 4:
                    cout << "Четвертая функция\n";
                    sort_fam(people);
                    break;
            
            case 5: 
                    find_people(people,max_stud, max_prep);
                    break;

            case 6: // Выход из программы
                    // Сохранить все изменения на диске
                    break;

            default:
                    cout << "Ой! Что-то пошло не так! Попробуйте еще раз ввести число.\n";
                    break;
            }
        }while( a != 6);

        write_file(people, max_stud, max_prep); // Функция записи в фаил нашей базы данных
        
        cout << "Нажмите Enter для продолжения...\n";
        cin.get();
    }
    catch(std::exception& e)
    {cout << "Что-то пошло не так(\n";
    return 1;}
}