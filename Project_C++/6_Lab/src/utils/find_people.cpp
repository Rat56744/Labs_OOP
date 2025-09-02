#include "stdfax.h"
#include "people.h"
#include "exceptions.h"
#include "function.h"

using std::vector, std::shared_ptr;

string enum_to_string(Department dep);

/// @brief Функция поиска человека по базе данных. Для поиска человека нужно ввести с клавиатуры необходимые параметры
///        - имя и фамилию искомого индивида
/// @param people Массив по которому производится поиск
/// @param max_stud Параметр для табличного вывода результатов(максимальная длинна поля у студента)
/// @param max_prep Параметр для табличного вывода результатов(максимальная длинна поля у преподавателя)
void find_people(const vector<shared_ptr<common>>& people, vector<int>& max_stud, vector<int>& max_prep) {
    vector<shared_ptr<common>> results; // Вектор динамическая структура данных

    // Ввод параметров поиска
    string Name;
    string Surname;
    cout << "Введите имя: ";
    set_param(Name, cin);
    cout << '\n';
    cout << "Введите фамилию: ";
    set_param(Surname, cin);
    // Поиск
    for (const auto& person : people) {
        // Для студентов
        if (person->is_student()) {
            // Т.к. метод is_student точно разделяет студентов и преподавателей(пока наследника 2)
            // то можно не беспокоиться по поводу опасного приведения
            auto* stud = static_cast<student*>(person.get());
            if (!stud->get_name().compare(Name) && !stud->get_surname().compare(Surname)) {
                student a = *stud; // Попросили через перегруженный оператор присваивания
                results.push_back(make_shared<student>(a));
            }
        }
        // Для преподавателей
        else{
            // Т.к. метод is_student точно разделяет студентов и преподавателей(пока наследника 2)
            // то можно не беспокоиться по поводу опасного приведения
            auto* teach = static_cast<teacher*>(person.get());
            if (!teach->get_name().compare(Name) && !teach->get_surname().compare(Surname)) {
                teacher a = *teach;
                results.push_back(make_shared<teacher>(a));
            }
        }
    }
    if(results.size() > 0){
        cout << "результат поиска: \n";
        baze_data(results, max_stud, max_prep);}
    else{cout << "Упс! По введённым параметрам ничего не найдено ;)\n";}
}