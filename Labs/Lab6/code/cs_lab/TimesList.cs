using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;

namespace cs_app
{
    [Serializable]
    public struct TimeItem
    {
        public int matrix_size { get; set; }
        public int cicle_num { get; set; }
        public double time_cs { get; set; }
        public double time_cpp { get; set; }
        public double relationship { get; set; }

        public TimeItem(int matrix_size, int cicle_num, double time_cs, double time_cpp)
        {
            this.matrix_size = matrix_size;
            this.cicle_num = cicle_num;
            this.time_cs = time_cs;
            this.time_cpp = time_cpp;
            relationship = time_cs / time_cpp;
        }
    }

    [Serializable]
    public class TimesList
    {
        private List<TimeItem> timeItems = new List<TimeItem>();

        public List<TimeItem> TIList => timeItems;

        public void Add(int matrix_size, int cicle_num, double time_cs, double time_cpp)
        {
            TimeItem ti = new TimeItem(matrix_size, cicle_num, time_cs, time_cpp);
            timeItems.Add(ti);
        }

        public bool Save(string filename)
        {
            try
            {
                var options = new JsonSerializerOptions { WriteIndented = true };
                string jsonString = JsonSerializer.Serialize(timeItems, options);
                File.WriteAllText(filename, jsonString);
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"*** Ошибка при сохранении файла: {ex.Message}");
                return false;
            }
        }

        public bool Load(string filename)
        {
            try
            {
                if (!File.Exists(filename))
                    return false;

                string jsonString = File.ReadAllText(filename);
                timeItems = JsonSerializer.Deserialize<List<TimeItem>>(jsonString) ?? new List<TimeItem>();
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"*** Ошибка при загрузке файла: {ex.Message}");
                return false;
            }
        }

        public override string ToString()
        {
            string str = "";
            if (timeItems.Count == 0)
                return "Нет записей в журнале";
            
            str += "-----------------------------------------------------------------------------------------\n";
            str += "    | Порядок |  Число   |  Время цикла |  Время цикла  | Отношение времени выполнения  |\n";
            str += "    | матрицы | повторов | в коде на C# | в коде на C++ |   кода на C# к коду на C++    |\n";
            str += "----------------------------------------------------------------------------------------\n";
            
            int i = 1;
            foreach (TimeItem ti in timeItems)
            {
                str += String.Format(" {0,2} | {1,5}   |  {2,7} |   {3,8:F3}   |    {4,8:F3}   |             {5,8:F3}          |\n", 
                    i++, ti.matrix_size, ti.cicle_num, ti.time_cs, ti.time_cpp, ti.relationship);
            }
            return str;
        }

        public bool SaveText(string filename)
        {
            try
            {
                filename = "TLC report " + DateTime.Now.ToShortDateString() + ".txt";
                string directory = Path.Combine(Directory.GetCurrentDirectory(), "Copies");
                
                if (!Directory.Exists(directory))
                    Directory.CreateDirectory(directory);
                
                string fullPath = Path.Combine(directory, filename);
                File.WriteAllText(fullPath, ToString());
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"*** Ошибка при сохранении отчета: {ex.Message}");
                return false;
            }
        }
    }
}