using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace Lab3
{
    delegate KeyValuePair<TKey, TValue> GenerateElement<TKey, TValue>(int j);
    internal class TestCollection<TKey, TValue>
    {
        private List<TKey> list_keys; // Список ключей
        private List<string> list_str; // Список строковых ключей
        private Dictionary<TKey, TValue> dictionary_keys; // Словарь по ключу
        private Dictionary<string, TValue> dictionary_str; // Словарь по строковому ключу
        private GenerateElement<TKey, TValue> generateElement; // Делегат для генерации элементов

        public TestCollection(int count, GenerateElement<TKey, TValue> j) // Конструктор. Заполняем все коллекции тестовыми данными
        {
            list_keys = new List<TKey>();
            list_str = new List<string>();
            dictionary_keys = new Dictionary<TKey, TValue>();
            dictionary_str = new Dictionary<string, TValue>();
            generateElement = j; // Теперь делегат генерирует элементы через GenerateElement. Это удобно потому что мы всегда можем поменять метод генерации элемента
            for (int i = 0; i < count; i++)
            {
                var elem = generateElement(i);
                Console.Write(elem.ToString());
                dictionary_keys.Add(elem.Key, elem.Value);
                dictionary_str.Add(elem.Key.ToString(), elem.Value);
                list_keys.Add(elem.Key);
                list_str.Add(elem.Key.ToString());
            }
        }
        public static KeyValuePair<Team, ResearchTeam> GenerateElement(int j) // Генератор ключа
        {
            Team key = new Team("Team" + j.ToString(), j);
            ResearchTeam value = new ResearchTeam("ResearchTeam" + j, (TimeFrame)(j%3), j);
            return  new KeyValuePair<Team, ResearchTeam>(key, value);
        }

        // Далее идут методы тестирования. Выбираем ( первый, средний, последний, отсутствующий )
        // Замеряем время с помощью Stopwatch
        // List<> имеют линейное время поиска O(n)
        // Dictionary<> имеют константное время поиска O(1)
        public void search_LIST_KEYS()
        {
            Console.WriteLine("\nIn list_keys \nTime of searching:\n");

            TKey first = list_keys[0];
            TKey middle = list_keys[list_keys.Count / 2];
            TKey last = list_keys[list_keys.Count - 1];
            TKey none = generateElement(list_keys.Count + 1).Key;

            Stopwatch sw = new Stopwatch();
            sw.Start();
            list_keys.Contains(first);
            sw.Stop();
            Console.WriteLine("For the first element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_keys.Contains(middle);
            sw.Stop();
            Console.WriteLine("For the middle element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_keys.Contains(last);
            sw.Stop();
            Console.WriteLine("For the last element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_keys.Contains(none);
            sw.Stop();
            Console.WriteLine("For the element that there is no in list: " + sw.Elapsed);
        }

        public void search_LIST_STR()
        {
            Console.WriteLine("\nIn list_str\nTime of the search:\n");

            var first = list_str[0];
            var middle = list_str[list_str.Count / 2];
            var last = list_str[list_str.Count - 1];
            var none = generateElement(list_str.Count + 1).Key.ToString();

            Stopwatch sw = new Stopwatch();
            sw.Start();
            list_str.Contains(first);
            sw.Stop();
            Console.WriteLine("For the first element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_str.Contains(middle);
            sw.Stop();
            Console.WriteLine("For the middle element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_str.Contains(last);
            sw.Stop();
            Console.WriteLine("For the last element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            list_str.Contains(none);
            sw.Stop();
            Console.WriteLine("For the element that there is no in list: " + sw.Elapsed);
        }
        public void search_DICTIONARY_KEYS_ByKey()
        {
            Console.WriteLine("\ndictionary_keys by key\nTime of the search:\n");

            TKey first = dictionary_keys.ElementAt(0).Key;
            TKey middle = dictionary_keys.ElementAt(dictionary_keys.Count / 2).Key;
            TKey last = dictionary_keys.ElementAt(dictionary_keys.Count - 1).Key;
            TKey none = generateElement(dictionary_keys.Count + 1).Key;

            Stopwatch sw = new Stopwatch();
            sw.Start();
            dictionary_keys.ContainsKey(first);
            sw.Stop();
            Console.WriteLine("For the first element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            dictionary_keys.ContainsKey(middle);
            sw.Stop();
            Console.WriteLine("For the middle element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            dictionary_keys.ContainsKey(last);
            sw.Stop();
            Console.WriteLine("For the last element: " + sw.Elapsed);

            sw.Reset();
            sw.Start();
            dictionary_keys.ContainsKey(none);
            sw.Stop();
            Console.WriteLine("For the element that there is no in list: " + sw.Elapsed);
        }
        public void search_DICTIONARY_STR_ByKey()
        {
            Console.WriteLine("\ndictionary_str by Key\nTime of the search:\n");

            var first = dictionary_str.ElementAt(0).Key;
            var middle = dictionary_str.ElementAt(dictionary_str.Count / 2).Key;
            var last = dictionary_str.ElementAt(dictionary_str.Count - 1).Key;
            var none = generateElement(dictionary_str.Count + 1).Key.ToString();

            Stopwatch sw = new Stopwatch();
            sw.Start();
            dictionary_str.ContainsKey(first);
            sw.Stop();
            Console.WriteLine("For the first element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_str.ContainsKey(middle);
            sw.Stop();
            Console.WriteLine("For the middle element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_str.ContainsKey(last);
            sw.Stop();
            Console.WriteLine("For the last element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_str.ContainsKey(none);
            sw.Stop();
            Console.WriteLine("For the element that there is no in list: " + sw.Elapsed);
        }

        public void search_DICTIONARY_KEYS_ByValue()
        {
            Console.WriteLine("\ndictionary_keys by Value\nTime of the search:\n");

            var first = dictionary_keys.ElementAt(0).Value;
            var middle = dictionary_keys.ElementAt(dictionary_keys.Count / 2).Value;
            var last = dictionary_keys.ElementAt(dictionary_keys.Count - 1).Value;
            var none = generateElement(dictionary_keys.Count + 1).Value;

            Stopwatch sw = new Stopwatch();
            sw.Start();
            dictionary_keys.ContainsValue(first);
            sw.Stop();
            Console.WriteLine("For the first element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_keys.ContainsValue(middle);
            sw.Stop();
            Console.WriteLine("For the middle element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_keys.ContainsValue(last);
            sw.Stop();
            Console.WriteLine("For the last element: " + sw.Elapsed);

            sw.Reset(); sw.Start();
            dictionary_keys.ContainsValue(none);
            sw.Stop();
            Console.WriteLine("For the element that there is no in list: " + sw.Elapsed);
        }
    }
}
