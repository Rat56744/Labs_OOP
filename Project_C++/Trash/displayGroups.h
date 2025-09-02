// #pragma once
// #include "../3_Lab/find_student_to_grup.h"

// // Передаём в аргументы словарь и поле direction
// void displayGroups(const unordered_map<string, vector<int>>& groupsMap, const string& direction, vector<int>& max) {
//     auto it = groupsMap.find(direction); // it итератор по элементу с заданным ключом(direction)
//     if (it != groupsMap.end()) { // Если итератор указывает на end(), то это значит, что элемент с нашим ключом отсутствует
//         cout << "Номера групп для направления " << direction << ": ";
//         for (int num : it->second) { // it->second - это вектор номеров групп по которому мы итерируемся
//             cout << num << " ";
//         }
//         cout << endl;
//     } else { // Если элемента с таким ключом нет, то сообщаем об этом
//         cout << "Нет групп для данного направления." << endl;
//     }
// }