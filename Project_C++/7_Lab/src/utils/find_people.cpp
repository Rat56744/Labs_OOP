#include <algorithm>
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
    cout << "* Got surname '" << Surname << "'" << std::endl;

    auto fullname_cmp = [&](auto &a) {
        return (!a->get_name().compare(Name) && !a->get_surname().compare(Surname));
    };

    std::copy_if(begin(people), end(people), std::back_inserter(results), fullname_cmp);

    if(results.size() > 0){
        cout << "результат поиска: \n";
        baze_data(results, max_stud, max_prep);}
    else{cout << "Упс! По введённым параметрам ничего не найдено ;)\n";}
}