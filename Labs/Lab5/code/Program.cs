using System;
using System.IO;

namespace Lab_5_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Person person1 = new Person("Polina", "Gorokhova", new DateTime(2003, 11, 24));
            Paper paper1 = new Paper("ML in CV", person1, new DateTime(2021, 5, 1));

            Console.WriteLine("-----------------------------Exercise 1---------------------------------");
            ResearchTeam originalObject = new ResearchTeam("Lab_5", "MIET", 8191500, TimeFrame.Long);
            originalObject.AddMembers(person1);
            originalObject.AddPapers(paper1);
            
            ResearchTeam deepCopyObject = originalObject.DeepCopy();
            Console.WriteLine("-----------------Original Object-----------------");
            Console.WriteLine(originalObject);
            Console.WriteLine("-----------------Copy of object-----------------");
            Console.WriteLine(deepCopyObject);
            
            Console.WriteLine("-----------------------------Exercise 2---------------------------------");
            Console.Write("Введите название файла: ");
            string? fn = Console.ReadLine();
            
            if (string.IsNullOrWhiteSpace(fn))
            {
                Console.WriteLine("Имя файла не может быть пустым");
                return;
            }

            FileInfo fileInfo = new FileInfo(fn);
            ResearchTeam rtInput = new ResearchTeam();
            
            if (fileInfo.Exists)
            {
                if (!ResearchTeam.Load(fn, ref rtInput))
                {
                    Console.WriteLine("Ошибка загрузки файла");
                }
            }
            else
            {
                Console.WriteLine("Создание файла...");
                fileInfo.Create().Close();
            }
            
            rtInput.AddFromConsole();
            Console.WriteLine();
            rtInput.Save(fn);
            Console.WriteLine(rtInput);
            
            rtInput.AddFromConsole();
            Console.WriteLine();
            ResearchTeam.Save(fn, rtInput);
            Console.WriteLine(rtInput);
            
            Console.ReadKey();
        }
    }
}