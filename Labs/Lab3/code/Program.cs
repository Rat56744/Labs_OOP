using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ex.1");
            Console.WriteLine("Большие города");
            List<Paper> mas_of_papers_1 = new List<Paper>(2);
            mas_of_papers_1.Add(new Paper("Math", new Person("Polina", "Gorokhova", new DateTime(2003, 10, 29)), new DateTime(2022, 11, 15)));
            mas_of_papers_1.Add(new Paper("Phys", new Person("Tatiana", "Kokurina", new DateTime(2003, 10, 25)), new DateTime(2022, 5, 22)));

            List<Paper> mas_of_papers_2 = new List<Paper>(2);
            mas_of_papers_2.Add(new Paper("Eng", new Person("Alexandra", "Konovalenko", new DateTime(2000, 10, 29)), new DateTime(2015, 2, 1)));
            mas_of_papers_2.Add(new Paper("Biology", new Person("Alina", "Kozlova", new DateTime(2005, 05, 14)), new DateTime(2021, 5, 10)));

            List<Paper> mas_of_papers_3 = new List<Paper>(2);
            mas_of_papers_3.Add(new Paper("Program", new Person("Polina", "Gorokhova", new DateTime(2003, 01, 24)), new DateTime(2019, 9, 23)));
            mas_of_papers_3.Add(new Paper("Sport", new Person("Alina", "Kozlova", new DateTime(2003, 04, 16)), new DateTime(2018, 6, 30)));

            ResearchTeam example_for_ex1 = new ResearchTeam("Buya", "FBI", 321, TimeFrame.Long);
            example_for_ex1.AddPapers(mas_of_papers_1);
            example_for_ex1.AddPapers(mas_of_papers_2);
            example_for_ex1.AddPapers(mas_of_papers_3);

            Console.WriteLine(example_for_ex1.ToString());

            example_for_ex1.SortByTitle();
            Console.WriteLine("\n\nSort by title: ");
            Console.WriteLine(example_for_ex1.ToString());

            example_for_ex1.SortBySurname();
            Console.WriteLine("\n\nSort by surname: ");
            Console.WriteLine(example_for_ex1.ToString());

            example_for_ex1.SortData();
            Console.WriteLine("\n\nSort by date: ");
            Console.WriteLine(example_for_ex1.ToString());

            Console.ReadKey();
            Console.WriteLine("-------------------------------------------------");

            Console.WriteLine("Ex.2");
            ResearchTeamCollection<string> test_collection = new ResearchTeamCollection<string>(ResearchTeamCollection<string>.DifineKey);

            ResearchTeam t1 = new ResearchTeam("Alpha", "FBI", 322, TimeFrame.Long);
            t1.AddPapers(mas_of_papers_1);

            ResearchTeam t2 = new ResearchTeam("Beta", "FBI", 323,TimeFrame.Year);
            t2.AddPapers(mas_of_papers_2);

            ResearchTeam t3 = new ResearchTeam("Gamma", "FBI", 324, TimeFrame.TwoYears);
            t3.AddPapers(mas_of_papers_3);

            //test_collection.AddDefaults();
            test_collection.AddResearchTeams(t1);
            test_collection.AddResearchTeams(t2);
            test_collection.AddResearchTeams(t3);
            Console.WriteLine(test_collection.ToString());
            Console.ReadKey();
            Console.WriteLine("-------------------------------------------------");

            Console.WriteLine("Ex.3");
            Console.Write("Last date of publications ");
            Console.WriteLine(test_collection.LastDate.ToShortDateString());
            var items_with_defined_TimeFrame = test_collection.TimeFrameGroup(TimeFrame.Long);
            Console.WriteLine($"Given time ->{TimeFrame.Long}: ");
            foreach (var kvp in items_with_defined_TimeFrame)
            {
                Console.WriteLine(kvp.Value.ToString());
            }
            foreach (var item in test_collection.GroupByTimeFrame)
            {
                Console.WriteLine();
                Console.WriteLine(item.Key);
                foreach (var name in item)
                {
                    Console.WriteLine(name.Value.ToString());
                }
            }
            Console.ReadKey();
            Console.WriteLine("-------------------------------------------------");
            Console.WriteLine("Ex.4");
            int num;
            Console.Write("Enter the length of the collection: ");
            while (!int.TryParse(Console.ReadLine(), out num) || num < 0)
            {
                Console.Write("Enter other the length: ");
            }

            TestCollection<Team, ResearchTeam> searchTest = new (num, TestCollection<Team, ResearchTeam>.GenerateElement);
            searchTest.search_LIST_KEYS();
            searchTest.search_LIST_STR();
            searchTest.search_DICTIONARY_KEYS_ByKey();
            searchTest.search_DICTIONARY_STR_ByKey();
            searchTest.search_DICTIONARY_KEYS_ByValue();
            Console.ReadKey();
        }
    }
}