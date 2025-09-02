#include "../4_Lab/stdfax.h"
#include "../4_Lab/people.h"
#include "../4_Lab/function.h"
using std::setw, std::left;
void read_int(int& a, istream& stream);

int main()
{
    const string student_file = "file.txt";
    // Значения enum. Нужны для того, чтобы 
    string value_department[5]{"VM_1", "IB", "MIUP", "TKS", "AMF"};

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

    ifstream file;  // Объект на чтение
    file.open(student_file, std::ios::in);  //  ios::in - только чтение 
    if(!file.is_open())  // Проверяем открылся или нет
    {
        cout << "Файл не открылся\n";
        return 1;
    }

    std::streampos fsize = file.tellg();  //  Запоминаем адрес куда указывает курсор
    file.seekg( 0, std::ios::end );  //  Перемещаем курсор в конец файла
    fsize = file.tellg() - fsize;  //  Запоминаем размер файла
    file.seekg(std::ios::beg);

    if(fsize==0){
        // Вводим с клавиатуры количество объектов
        cout << "Введите количество людей(не менее 8):";
        int col_people;
        do{cin>>col_people;}while(col_people < 0);

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
    cin >> a;
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
    
    case 5: // Выход из программы
            // Сохранить все изменения на диске
            break;

    default:
            cout << "Ой! Что-то пошло не так! Попробуйте еще раз ввести число.\n";
            break;
    }
    }while( a != 5);

    write_file(people, max_stud, max_prep); // Функция записи в фаил нашей базы данных
    
    cout << "Нажмите Enter для продолжения...\n";
    cin.get();
}

// Выбираем кого добавляем в people и используем нужный конструктор
void add_people(vector<shared_ptr<common>>& people, unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup , vector<string>& directions, vector<int>& max_stud, vector<int>& max_prep)
{   cout << "Выберите кого вы хотите добавить: " << "\n1 - Студент, 2 - Преподаватель\n";
    int student_or_prep = 0;
    do{cin>>student_or_prep;}while(student_or_prep < 1 || student_or_prep > 2);
    switch (student_or_prep)
    {
        case 1:
        /*  С помощью make_shared выделяем память под студента и возвращаем shared_ptr 
            указывающий на наш объект. Можно использовать если нет пользовательского деструктора  */
        people.emplace_back(make_shared<student>(grupsMap,numbers_grup, directions, max_stud)); // С помощью make_shared указываем 
        break;
    
    case 2:
        people.emplace_back(make_shared<teacher>(max_prep));
        break;

    default:
        break;
    }}