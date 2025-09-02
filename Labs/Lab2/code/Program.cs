using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

// Вариант 3

namespace Lab2
{
    class Program
    {
        static void Main()
        {

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            Team teamA = new Team("Team", 1);
            Team teamB = new Team("Team", 1);

            // ReferenceEquals сравнивает две ссылки. Если ссылки на объекты идентичны, то возвращает true
            Console.WriteLine("Проверка на то, что ссылки равны: " + ReferenceEquals(teamA, teamB).ToString());
            Console.WriteLine("Проверка на то, что данные одинаковые: " + teamA.Equals(teamB).ToString());
            Console.WriteLine("Хеш-код первой команды: " + teamA.GetHashCode());
            Console.WriteLine("Хеш-код второй команды: " + teamB.GetHashCode());

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            try
            {
                teamA.RegNum = 0; // Присваиваем недопустимое значение
            }
            catch (Exception error)
            {
                Console.WriteLine(error.Message); // Вывод сообщения об ошибке
            }

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            ResearchTeam researchTeam = new ResearchTeam("Lab_2", "MIET", 2, TimeFrame.Long);
            Person person_1 = new Person("Polina", "Gorokhova", new DateTime(2003, 11, 24));
            Person person_2 = new Person("NoData", "NoData", new DateTime(2022, 1, 1));
            Person person_3 = new Person("Tatiana", "Kokurina", new DateTime(2003, 10, 25));
            Person person_temp = new Person("Alexandra", "Konovalenko", new DateTime(2003, 10, 29));
            Paper paper_1 = new Paper("Публикация 1 участника:", person_1, new DateTime(2019, 11, 10));
            Paper paper_2 = new Paper("Публикация 2 участника:", person_2, new DateTime(2022, 6, 6));
            Paper paper_1_2 = new Paper("Вторая публикация 1 участника", person_1, new DateTime(2022, 3, 14));
            researchTeam.AddPapers(paper_1, paper_2, paper_1_2); // Добавление элементов в список публикаций
            researchTeam.AddMembers(person_1, person_2, person_3, person_temp); // ~=~
            Console.WriteLine(researchTeam.ToString());

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            Console.WriteLine("Name of organizatoin: " + researchTeam.Base.NameOrg); // Часть полей в базовом классе Team
            Console.WriteLine("Name: " + researchTeam.Base.Name); // Часть полей в базовом классе Team
            Console.WriteLine("Reg.num: " + researchTeam.Base.RegNum); // Часть полей в базовом классе Team

            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №5 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            ResearchTeam team_copy = (ResearchTeam)researchTeam.DeepCopy(); // Скопировали все из Research Team

            Person person = new Person("Alina", "Kozlova", new DateTime(1995, 10, 12));
            Paper paper = new Paper("New Publication", person, new DateTime(2022, 11, 10));
            researchTeam.AddPapers(paper);
            researchTeam.AddMembers(person);

            researchTeam.NameOrg = "Lab 2 is completed"; // Изменили данные в объекте researchTeam
            Console.WriteLine("********** Текст, хранящийся в researchTeam **********");
            Console.WriteLine(researchTeam.ToString());  // Вывели то, что хранится в researchTeam
            Console.WriteLine("********** Текст, хранящийся в team_copy **********");
            Console.WriteLine(team_copy.ToString()); // Вывели то, что хранится в team_copy


            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Люди без публикаций: ");
            foreach (var item in researchTeam.SearchPersonWithoutPublic()) // var - для того чтобы компилятор мог определить тип переменной
            {
                Console.WriteLine(item.ToString());
            }


            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~ Задание №7 ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("Публикации, выпущенные в ближайшие два года: ");
            foreach (var item in researchTeam.SearchPublications(2))
            {
                Console.WriteLine(item.ToString());
            }
        }
    }
}
