using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    delegate TKey KeySelector<TKey>(ResearchTeam rt); // Объявили делегат 
    //Класс содержащий коллекцию объектов типа ResearchTeam
    class ResearchTeamCollection<TKey>
    {
        private Dictionary<TKey, ResearchTeam> teamsDictionary;
        private KeySelector<TKey> KeyFunctionValue; //Для хранения экземпляра делегата 
        
        //Конструктор с одним параметром KeySelector
        public ResearchTeamCollection(KeySelector<TKey> functionValue)
        {
            KeyFunctionValue = functionValue;
            teamsDictionary = new Dictionary<TKey, ResearchTeam>();
        }
        
        #region AddDefaults/AddResearchTeams
        //Добавить несколько элементов по умолчанию  Dictionary<TKey, ResearchTeam>
        public void AddDefaults()
        {
            ResearchTeam rt_1 = new ResearchTeam();
            ResearchTeam rt_2 = new ResearchTeam();
            rt_1.OrgName = "Research_Team_1";
            rt_2.OrgName = "Research_Team_2";
            rt_1.Listpub = TimeFrame.Long;
            rt_2.Listpub = TimeFrame.TwoYears;
            
            Person person_1 = new Person("Default_Name_1", "Default_Surname_1", new DateTime(1999, 1, 1));
            Person person_2 = new Person("Default_Name_2", "Default_Surname_2", new DateTime(1999, 1, 1));
            Person person_3 = new Person("Default_Name_3", "Default_Surname_3", new DateTime(1999, 1, 1));
            Paper paper_1 = new Paper("Default_Name_Pub_1", person_1, new DateTime(2010, 1, 1));
            Paper paper_2 = new Paper("Default_Name_Pub_2", person_2, new DateTime(2010, 2, 2));
            Paper paper_3 = new Paper("Default_Name_Pub_3", person_3, new DateTime(2009, 1, 1));

            rt_1.AddPapers(paper_1, paper_2);
            rt_1.AddMembers(person_1, person_2);
            rt_2.AddPapers(paper_3);
            rt_2.AddMembers(person_2, person_3);

            teamsDictionary.Add(KeyFunctionValue(rt_1), rt_1);
            teamsDictionary.Add(KeyFunctionValue(rt_2), rt_2);
        }
        
        //Метод для добавлени элементов в коллекцию 
        public void AddResearchTeams(params ResearchTeam[] teams)
        {
            for(int i = 0; i < teams.Length; i++)
            {
                TKey key = KeyFunctionValue(teams[i]);
                if(!teamsDictionary.ContainsKey(key))
                {
                    teamsDictionary.Add(key, teams[i]);
                    teams[i].PropertyChanged += OnPropertyChange;
                }
            }
        }
        #endregion
        #region IEnumerable
        //Метод возвращающий элементы коллекции Dictionary<TKey, ResearchTeam> со значениями времени исследований
        public IEnumerable<KeyValuePair<TKey, ResearchTeam>> TimeFrameGroup(TimeFrame value)
        {
            var result = from test in teamsDictionary
                //Для формирования подмножества исользовать where
                where test.Value.Listpub.Equals(value)
                select test;

            return result;
        }
        
        #endregion
        
        public string Namecollect { get; set; } //открытое автореализуемое свойство
        public event ResearchTeamsChangedHandler<TKey> ResearchTeamsChanged;
        public void OnPropertyChange(object rt, System.ComponentModel.PropertyChangedEventArgs args)
        {
            ResearchTeam rt1 = rt as ResearchTeam;
            ResearchTeamsChanged(rt, new ResearchTeamsChangedEventArgs<TKey>(Namecollect, Revision.Property, args.PropertyName, rt1.RegNum));
        }

        public bool Remove(ResearchTeam rt)
        {
            if (teamsDictionary.ContainsValue(rt))
            {
                foreach (KeyValuePair<TKey, ResearchTeam> i in teamsDictionary)
                {
                    if (i.Value == rt)
                    {
                        ResearchTeamsChanged(teamsDictionary, new ResearchTeamsChangedEventArgs<TKey>(Namecollect, Revision.Remove, "None", rt.RegNum));
                        teamsDictionary.Remove(i.Key);
                        break;
                    }
                }
                return true;
            }
            else
                return false;
        }
        
        public bool Replace(ResearchTeam rt_1, ResearchTeam rt2)
        {
            if (teamsDictionary.ContainsValue(rt_1))
            {
                foreach (KeyValuePair<TKey, ResearchTeam> i in teamsDictionary)
                {
                    if (i.Value == rt_1)
                    {
                        teamsDictionary.Remove(i.Key);
                        AddResearchTeams(rt2);
                        ResearchTeamsChanged(teamsDictionary, new ResearchTeamsChangedEventArgs<TKey>(Namecollect, Revision.Replace, "None", rt_1.RegNum));
                        break;

                    }
                }
                return true;
            }
            else
                return false;
        }
        
        public IEnumerable<IGrouping<TimeFrame, KeyValuePair<TKey, ResearchTeam>>> Group
        {
            get
            {
                return teamsDictionary.GroupBy(p=> p.Value.Listpub);
            }
        }
        public static string GenerateKey(ResearchTeam rt)
        {
            return rt.Base.ToString();
        }
        #region OverrideToString

        public override string ToString()
        {
            string result = "";
            foreach(var key in teamsDictionary.Keys)
            {
                result += teamsDictionary[key].ToString() + "\n";
                result += "================================================\n";
            }

            return result;
        }

        #endregion

    }
}