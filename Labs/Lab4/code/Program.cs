using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace Lab_4
{
    class Program
    {
        static void Main(string[] args)
        {
            // У нас есть делегат в классе ResearchTeamCollection. На это событие класс TeamsJournal может подписаться (53 строчка)
            
            Person person_1 = new Person("Alexandra", "Konovalenko", new DateTime(2003, 11, 24));
            Person person_2 = new Person("Tatiana", "Kokurina", new DateTime(2003, 10, 29));
            Person person_3 = new Person("Alina", "Kozlova", new DateTime(2003, 10, 25));
            Person person_4 = new Person("Polina", "Gorokhova", new DateTime(2003, 9, 7));
            
            Paper paper_1 = new Paper("ML in CV", person_1, new DateTime(2021, 5, 1));
            Paper paper_2 = new Paper("Lab_Practice", person_2, new DateTime(2022, 12, 2));
            Paper paper_3 = new Paper("Data science today", person_1, new DateTime(2020, 12, 22));
            Paper paper_4 = new Paper("MIET", person_2, new DateTime(2022, 11, 28));
            
            ResearchTeam rt_1 = new ResearchTeam("PM_Journal", "MIET", 31, TimeFrame.Year);
            rt_1.AddMembers(person_1, person_2, person_3, person_4);
            rt_1.AddPapers( paper_1, paper_2, paper_3, paper_4);
            ResearchTeam rt_2 = new ResearchTeam("World of Maths", "MIT", 32, TimeFrame.TwoYears);
            rt_2.AddMembers(person_1, person_2);
            rt_2.AddPapers(paper_1, paper_2);
            ResearchTeam rt_3 = new ResearchTeam("Test_RT_3", "RAS", 33, TimeFrame.Year);
            rt_3.AddMembers(person_3, person_4);
            rt_3.AddPapers(paper_3, paper_4);
            ResearchTeam rt_4 = new ResearchTeam("Test_RT_4", "RAS", 34, TimeFrame.Long);
            rt_4.AddMembers(person_1, person_4);
            rt_4.AddPapers(paper_1, paper_4);
            
            Console.WriteLine("-----------------------------Exercise 1---------------------------------");
            //Создать две коллекции ResearchTeamCollection<string> 
            Console.WriteLine("-----------------Collection 1-----------------");
            KeySelector<string> ex1 = ResearchTeamCollection<string>.GenerateKey;
            ResearchTeamCollection<string> rtc1 = new ResearchTeamCollection<string>(ex1);
            rtc1.AddResearchTeams(rt_1, rt_2);
            rtc1.Namecollect = "Collection 1";
            Console.WriteLine(rtc1.ToString());
            Console.WriteLine("-----------------Collection 2-----------------");
            ResearchTeamCollection<string> rtc2 = new ResearchTeamCollection<string>(ex1);
            rtc2.AddResearchTeams(rt_2, rt_3);
            rtc2.Namecollect = "Collection 2";
            Console.WriteLine(rtc2.ToString());
            
            Console.WriteLine("-----------------------------Exercise 2/3/4---------------------------------");
            TeamsJournal teamsJournal = new TeamsJournal();
            rtc1.ResearchTeamsChanged += teamsJournal.OnPropertyChange;
            rtc2.ResearchTeamsChanged += teamsJournal.OnPropertyChange;
            //Добавить элементы в коллекции
            rtc1.AddResearchTeams(rt_4);
            rtc2.AddResearchTeams(rt_1);
            //Изменить значения разных свойств элементов, входящих в коллекции
            rt_2.RegNum = 8211392;
            rt_2.Theme = "Lab4";
            rt_3.RegNum = 31;
            //Удалить элемент из коллекции
            rtc1.Remove(rt_1);
            rtc2.Remove(rt_2);
            //Изменить данные в удаленном элементе
            rt_2.Theme = "[Delete]";
            //Заменить один из элементов коллекци
            rtc1.Replace(rt_2, rt_4);
            //Изменить данные в элементе, который был удален из коллекции при замене элемента
            rt_2.Theme = "Lab4";
            Console.WriteLine(teamsJournal.ToString());
            Console.ReadKey();
        }
    }
}