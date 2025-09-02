using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;

namespace Lab3
{
    delegate TKey KeySelector<TKey>(ResearchTeam rt);
    internal class ResearchTeamCollection<TKey>
    {
        private Dictionary<TKey, ResearchTeam> dict;
        private KeySelector<TKey> keySelector;
        public ResearchTeamCollection(KeySelector<TKey> keySelector)
        {
            this.keySelector = keySelector;
            dict = new Dictionary<TKey, ResearchTeam>();
        }
        public static string DifineKey(Team a)
        {
            return a.RegNum.ToString();
        }
        public void AddDefaults()
        {
            ResearchTeam a = new ResearchTeam();
            dict.Add(keySelector(a), a);
        }
        public void AddResearchTeams(params ResearchTeam[] teams)
        {
            foreach (ResearchTeam i in teams)
                dict.Add(keySelector(i), i);
        }
        public override string ToString()
        {
            string output = " ";
            foreach (KeyValuePair<TKey, ResearchTeam> i in dict)
                output += "\n" + i.Value.ToString();
            return output;
        }
        public string ToShortString()
        {
            string output = " ";
            foreach (KeyValuePair<TKey, ResearchTeam> i in dict)
                output += "\n" + i.Value.ToShortString() + "количество людей: " + i.Value.CountOfPersons() + "количество публикаций: " + i.Value.CountOfPublications();
            return output;
        }
        public DateTime LastDate
        {
            get
            {
                Paper x = new ();
                if (dict.Count > 0)
                    return dict.Max(point => point.Value.Get_last_pub.PublicationDate); // Извелекаем дату последней публикации
                return x.PublicationDate; // Дата по умолчанию если коллекция пуста
            }
        }
        public IEnumerable<KeyValuePair<TKey, ResearchTeam>> TimeFrameGroup(TimeFrame value) // Возвращаем элементы, у которых совпадает продолжительность исследований
        {
            return dict.Where(g => g.Value.Time == value);
        }
        public IEnumerable<IGrouping<TimeFrame, KeyValuePair<TKey, ResearchTeam>>> GroupByTimeFrame // Группировка эллементов по TimeFrame
        {
            get
            {
                return dict.GroupBy(g => g.Value.Time);
            }
        }
            
    }
}
