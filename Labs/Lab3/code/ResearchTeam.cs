using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace Lab3
{
    class ResearchTeam: Team, INameAndCopy
    {
        private string theme;
        TimeFrame time;
        private List<Person> persons;
        private List<Paper> publications;

        public ResearchTeam(string Name_Of_Org_value, TimeFrame time_value, int Reg_num_value)
        {
            Name_Of_Org = Name_Of_Org_value;
            time = time_value;
            Reg_num = Reg_num_value;
            persons = new List<Person>(0);
            publications = new List<Paper>(0);
        }
        public ResearchTeam(string theme_value, string Name_Of_Org_value, int Reg_num_value, TimeFrame time_value)
        {
            theme = theme_value;
            Name_Of_Org = Name_Of_Org_value;
            Reg_num = Reg_num_value;
            time = time_value;
            persons = new List<Person>(0);
            publications = new List<Paper>(0);
        }
        public ResearchTeam()
        {
            theme = "Theme";
            Name_Of_Org = "MIET";
            Reg_num = 5;
            time = TimeFrame.Year;
            persons = new List<Person>(0);
            publications = new List<Paper>(0);
        }
        public string Theme
        {
            get
            {
                return theme;
            }
            set
            {
                theme = value;
            }
        }
        public TimeFrame Time
        {
            get
            {
                return time;
            }
            set
            {
                time = value;
            }
        }
        public List<Person> Persons
        {
            get
            {
                return persons;
            }
            set
            {
                persons = value;
            }
        }
        public List<Paper> Publications
        {
            get
            {
                return publications;
            }
            set
            {
                publications = value;
            }
        }
        public string CountOfPersons() { return persons.Count.ToString(); }
        public string CountOfPublications() { return publications.Count.ToString(); }
        public bool this[TimeFrame _time]
        {
            get
            {
                return _time == time;
            }

        }
        public Paper Get_last_pub
        {
            get
            {
                Paper y = new Paper();
                if (publications.Count == 0)
                {
                    return y;
                }
                int ind = 0;
                System.DateTime time = System.DateTime.MinValue; 
                foreach(Paper x in publications)
                    if (x.PublicationDate > time)
                    {
                        time = x.PublicationDate;
                        y = x;
                    }
                return y;
            }
        }
        public void AddPapers(List<Paper> items)
        {
            foreach (Paper p in items)
                publications.Add(p);
        }
        public override string ToString() 
        {
            string result = "Theme:" + theme + " Name of organization:" + Name_Of_Org + " Regist_num:" + Reg_num.ToString() + " Duration:" + time.ToString();
            result += "\nPersons:\n";
            foreach(Paper a in publications)
                result += a.Person.ToString() + "\n";
            result += "\nPublications:\n";
            foreach(Paper b in publications)
                result += b.ToString() + "\n";
            return result;
        }
        public virtual string ToShortString() //Задаем наш вывод
        {
            return "Theme:" + theme + " Name of organization:" + Name_Of_Org + " Regist_num:" + Reg_num.ToString() + " Duration:" + time.ToString();
        }
        public new object DeepCopy()
        {
            ResearchTeam Copy = new ResearchTeam(theme, Name_Of_Org, Reg_num, time);
            Copy.persons = persons;
            Copy.publications = publications;
            return Copy;
        }
        public void AddMembers(List<Person> items)
        {
            foreach (Person p in items)
                persons.Add(p);
        }
        public Team getTeamType
        {
            get
            {
                return new Team(Name_Of_Org, Reg_num);
            }
            set
            {
                Name_Of_Org = value.NameOrg;
                Reg_num = value.RegNum;
            }
        }
        public IEnumerable<Person> MembersWithoutpublications()
        {
            List<Person> PersonsWithoutP = new List<Person>();
            bool a;
            foreach (Person pers in persons)
            {
                a = true;
                foreach (Paper pap in publications)
                {
                    if (pap.Person == pers)
                    {
                        a = false;
                        break;
                    }
                }
                if (a)
                {
                    PersonsWithoutP.Add(pers);
                }

            }
            for (int i = 0; i < PersonsWithoutP.Count; i++)
            {
                yield return (Person)PersonsWithoutP[i];
            }
        }
        public IEnumerable<Paper> LastPapers(int N_years)
        {
            for (int i = 0; i < Publications.Count; i++)
            {
                if (((Paper)Publications[i]).PublicationDate.Year >= DateTime.Now.Year - N_years && ((Paper)Publications[i]).PublicationDate.Year <= DateTime.Now.Year)
                {
                    yield return (Paper)Publications[i];
                }
            }
        }
        public void SortData()
        {
            publications.Sort();
        }
        public void SortByTitle()
        {
            publications.Sort(new Paper());
        }
        public void SortBySurname()
        {
            publications.Sort(new PaperComparer());
        }
    }
}
