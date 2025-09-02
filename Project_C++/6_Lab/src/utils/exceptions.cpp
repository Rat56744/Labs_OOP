#include "stdfax.h"
#include "people.h"
#include "Error.h"
#include <limits>
#include <cctype>

void cin_int(int& a,const int& min,const int& max){
    while (true) {
        try {
            string input;
            getline(cin, input);

            size_t pos;
            long long tmp = std::stoll(input, &pos); // pos - показывает сколько символов считалось
            
            /* Если количество считанных символов не равно размеру введенной строки,
                то там был мусор такую ситуацию надо обработать */
            if (pos != input.length()) { 
                throw Error("Некорректный ввод (лишние символы)");
            }
            if ( tmp < min || tmp >max) {
                throw Error("Введена неправильная цифра!");
            }
            if (tmp > std::numeric_limits<int>::max()) {
                throw Error("Переполнение: число слишком большое для int");
            }

            a = tmp; // Неявное преобразование. Мы точно знаем, что тут не будет UB
            break;
        }
        // Первые два исключения выбрасывает stoll
        catch (const std::invalid_argument&) {
            cout << "Ошибка: введено не число\n";
            cout << "Повторите ввод: ";}
        catch (const std::out_of_range&) {
            cout << "Ошибка: число выходит за пределы int\n";
            cout << "Повторите ввод: ";}
        catch (Error& e) {
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
        catch (std::exception& e){
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
    }
}

bool is_alphanumeric_string(const string& str) {
  for (size_t i=0; i<str.size();++i) {
        int a = static_cast<int>(static_cast<unsigned char>(str[i]));
        // Для utf-8 только у русских символов и только в бервом байте встречается число 208 либо с 209.
        // Из этого факта напрямую следует, что если нам в строке встретилось одно из этих чисел, то
        // это обязательно начало русского символа, а мы такое осуждаем. Сразу после обнаружения мы 
        // обрабатывем некорректный ввод
        if(a == 208 || a == 209){   
            throw Error("Вы ввели кирилицу! Непозволительная роскошь!");
            return false;
        }
        if (!std::isalnum(str[i])) {
        return false;
        }
    }
  return true;
}

void set_param(string& field, istream& stream)
{
    while(true){
        try{
            getline(stream, field);
            if(!is_alphanumeric_string(field))
            {throw Error("В ведённой строке присутствуют символы кроме цифр и букв!\n");}
            break;
        }
        catch(std::length_error&){cout << "Вы ввели слишком много символов! Поле переполнено!\n";
            cout << "Повторите ввод: ";}
        catch(Error& e){cout << "Ошибка: "<< e.what()<<'\n';
            cout << "Повторите ввод: ";}
    }
}

void read_int(int& a, istream& stream)
{
while (true) {
        try {
            string input;
            getline(cin, input);

            size_t pos;
            long long tmp = std::stoll(input, &pos); // pos - показывает сколько символов считалось
            
            /* Если количество считанных символов не равно размеру введенной строки,
               то там был мусор такую ситуацию надо обработать */
            if (pos != input.length()) { 
                throw Error("Некорректный ввод (лишние символы)");
            }
            if (tmp < 0) {
                throw Error("Номер группы не может быть меньше нуля");
            }
            if (tmp > std::numeric_limits<int>::max()) {
                throw Error("Переполнение: число слишком большое для int");
            }

            a = tmp; // Неявное преобразование. Мы точно знаем, что тут не будет UB
            break;
        }
        // Первые два исключения выбрасывает stoll
        catch (const std::invalid_argument&) {
            cout << "Ошибка: введено не число\n";
            cout << "Повторите ввод: ";}
        catch (const std::out_of_range&) {
            cout << "Ошибка: число выходит за пределы int\n";
            cout << "Повторите ввод: ";}
        catch (Error& e) {
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
        catch (std::exception& e){
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
    }
}

void open_file(ifstream& file, const string& student_file){
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit); // Включаем автоматические исключения
    file.open(student_file, std::ios::in);
}

void cin_col_people(int& col_people)
{
    while (true) {
        try {
            string str;
            getline(cin, str);

            size_t pos;
            long long tmp = std::stoll(str, &pos); // pos - показывает сколько символов считалось
            
            /* Если количество считанных символов не равно размеру введенной строки,
               то там был мусор такую ситуацию надо обработать */
            if (pos != str.length()) { 
                throw Error("Некорректный ввод (лишние символы)");
            }
            if (tmp < 0) {
                throw Error("Число людей не может быть меньше нуля");
            }
            if (tmp > std::numeric_limits<int>::max()) {
                throw Error("Переполнение: число слишком большое для int");
            }

            col_people = tmp; // Неявное преобразование. Мы точно знаем, что тут не будет UB
            break;
        }
        // Первые два исключения выбрасывает stoll
        catch (const std::invalid_argument&) {
            cout << "Ошибка: введено не число\n";
            cout << "Повторите ввод: ";}
        catch (const std::out_of_range&) {
            cout << "Ошибка: число выходит за пределы int\n";
            cout << "Повторите ввод: ";}
        catch (Error& e) {
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
        catch (std::exception& e){
            cout << "Ошибка: " << e.what() << '\n';
            cout << "Повторите ввод: ";}
    }
}

// Выбираем кого добавляем в people и используем нужный конструктор
void add_people(vector<shared_ptr<common>>& people, unordered_map<string, vector<int>>& grupsMap, vector<int>& numbers_grup , vector<string>& directions, vector<int>& max_stud, vector<int>& max_prep)
{   cout << "Выберите кого вы хотите добавить: " << "\n1 - Студент, 2 - Преподаватель\n";
    int student_or_prep = 0;
    cin_int(student_or_prep, 1,2);
    switch (student_or_prep)
    {
        case 1:
        /*  С помощью make_shared выделяем память под студента и возвращаем shared_ptr 
            указывающий на наш объект. Можно использовать если нет пользовательского деструктора  */
        people.emplace_back(/*make_shared<student>*/new student(grupsMap,numbers_grup, directions, max_stud)); 
        break;
    
    case 2:
        people.emplace_back(make_shared<teacher>(max_prep));
        break;

    default:
        break;
    }
}