#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Student {
    string direction;
    int num_group;
};


// Передаём в аргументы словарь и поле direction
void displayGroups(const unordered_map<string, vector<int>>& groupsMap, const string& direction) {
    auto it = groupsMap.find(direction); // it итератор по элементу с заданным ключом(direction)
    if (it != groupsMap.end()) { // Если итератор указывает на end(), то это значит, что элемент с нашим ключом отсутствует
        cout << "Номера групп для направления " << direction << ": ";
        for (int num : it->second) { // it->second - это вектор номеров групп по которому мы итерируемся
            cout << num << " ";
        }
        cout << endl;
    } else { // Если элемента с таким ключом нет, то сообщаем об этом
        cout << "Нет групп для данного направления." << endl;
    }
}

int main() {
    vector<Student> students = {
        {"a", 1},
        {"b", 2},
        {"c", 1},
        {"a", 2}
    };

    // Создаем ассоциативный массив для хранения направлений и их номеров групп
    unordered_map<string, vector<int>> groupsMap;

    // Заполняем ассоциативный массив
    for (const auto& student : students) {
        groupsMap[student.direction].push_back(student.num_group);
    }

    // Выбор направления
    cout << "Выберите направление: " << endl;
    for (const auto& pair : groupsMap) {
        cout << pair.first << " ";
    }
    cout << endl;

    string selectedDirection;
    cin >> selectedDirection;

    // Отображаем доступные номера групп для выбранного направления
    displayGroups(groupsMap, selectedDirection);

    // Выбор номера группы
    int selectedGroup;
    cout << "Введите номер группы: ";
    
    cin >> selectedGroup;

    // Проверка на наличие студентов в выбранной группе
    bool found = false;
    for (const auto& student : students) {
        if (student.direction == selectedDirection && student.num_group == selectedGroup) {
            found = true;
            cout << "Студент найден: направление = " << student.direction 
                 << ", номер группы = " << student.num_group << endl;
        }
    }

    if (!found) {
        cout << "Студенты не найдены." << endl;
    }

    return 0;
}