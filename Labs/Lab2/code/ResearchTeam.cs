using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    class ResearchTeam : Team // Определяю как производный от класса Team, реализовываю интерфейс INameAndCopy.
    {
        string theme;
        TimeFrame listPubValue;
        ArrayList participants;
        ArrayList publications;

        public ResearchTeam(string theme_value, string name_of_org_value, int reg_num_value, TimeFrame listPub_value) : base(theme_value, reg_num_value) // Часть полей в базовом классе Team
        {
            Name_Of_Org = name_of_org_value;
            listPubValue = listPub_value;
            publications = new ArrayList();
            participants = new ArrayList();
        }
        public ResearchTeam() : base("MIET", 0) // Часть полей в базовом классе Team
        {
            Name_Of_Org = "MIET";
            listPubValue = TimeFrame.Year;
            participants = new ArrayList();
            publications = new ArrayList();
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
        public TimeFrame ListPubValue
        {
            get
            {
                return listPubValue;
            }
            set
            {
                listPubValue = value;
            }
        }
        public ArrayList Publications
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
        public ArrayList Participants
        {
            get
            {
                return participants;
            }
            set
            {
                participants = value;
            }
        }

        public Team Base // Часть полей в базовом классе Team
        {
            get
            {
                return new Team(Name_Of_Org, Reg_num);
            }
            set
            {
                Name_Of_Org = value.NameOrg;
                Name = value.Name;
                Reg_num = value.RegNum;
            }
        }

        public bool this[TimeFrame listPub_]
        {
            get
            {
                return listPub_ == listPubValue;
            }
        }

        public Paper GetLastPublication
        {
            get
            {
                if (publications.Count == 0)
                {
                    return null;
                }
                int lp_ind = 0; // индекс последней публикации
                System.DateTime time = System.DateTime.MinValue;
                for (int i = 0; i < publications.Count; i++)
                {
                    if ((publications[i] as Paper).DateValue > time)
                    {
                        time = (publications[i] as Paper).DateValue;
                        lp_ind = i;
                    }
                }
                return (Paper)publications[lp_ind];
            }
        }

        // перегруженная версию виртуального метода object DeepCopy();
        public override object DeepCopy()
        {
            ResearchTeam copy = new ResearchTeam(theme, Name_Of_Org, Reg_num, listPubValue);
            for (int i = 0; i < publications.Count; i++)
            {
                copy.publications.Add(publications[i]); // Добавление нового элемента в публикации для копирования
            }
            for (int i = 0; i < participants.Count; i++)
            {
                copy.participants.Add(participants[i]);// Добавление нового элемента в участников проекта для копирования
            }
            return copy;
        }

        // Метод void AddPapers для добавления элементов в список публикаций;
        public void AddPapers(params Paper[] items)
        {
            for (int i = 0; i < items.Length; i++)
            {
                publications.Add(items[i]); // Добавление нового элемента в публикации
            }
        }

        // Метод void AddMembers для добавления элементов в список участников проекта;
        public void AddMembers(params Person[] items)
        {
            for (int i = 0; i < items.Length; i++)
            {
                participants.Add(items[i]);  // Добавление нового элемента в участников проекта
            }
        }

        // Перегруженный ToString
        public override string ToString()
        {
            string text = "Theme: " + theme + " OrgName: " + Name_Of_Org + "| ID: " + Reg_num.ToString() + "| Duration: " + listPubValue.ToString();

            text += "\nПубликации:\n";
            for (int i = 0; i < publications.Count; i++)
            {
                text += ((Paper)publications[i]).ToString() + "\n";  // Выводим публикацаии
            }
            text += "\nУчастники:\n";
            for (int i = 0; i < participants.Count; i++)
            {
                text += ((Person)participants[i]).ToString() + "\n"; // Выводим поиск
            }
            return text;
        }

        public virtual string ToShortString()
        {
            return "Theme: " + theme + " OrgName: " + Name_Of_Org + " ID: " + Reg_num.ToString() + " Duration: " + listPubValue.ToString();
        }

        public IEnumerable SearchPersonWithoutPublic()
        {
            int count = 0;
            for (int i = 0; i < participants.Count; i++)
            {
                bool isCorrect = false;
                for (int j = 0; j < publications.Count; j++)
                {
                    //Автор из Paper сравнивается с автором из Person
                    if ((publications[j] as Paper).SurnameValue.Equals((Person)participants[i]))
                    {
                        isCorrect = true;
                        break;
                    }

                }
                if (!isCorrect) // Если не у всех пользователей есть публикацаии
                {
                    count++;
                    yield return participants[i]; // Оператор yield return используется для возврата каждого элемента по одному.

                }
            }
            if (count == 0)
            {
                Console.WriteLine("У всех пользователей есть публикации:)");
            }
        }
        public IEnumerable SearchPublications(int n)
        {
            DateTime now = DateTime.Now;
            int count = 0;
            for (int i = 0; i < publications.Count; i++)
            {
                // TotalDays Свойство представляет целые и дробные дни
                if (((now - (publications[i] as Paper).DateValue).TotalDays / 365) < n) //Если разница меньше 2
                {
                    count++;
                    yield return publications[i];
                }
            }
            if (count == 0)
            {
                Console.WriteLine("Все публикации опубликованы раньше:)");
            }
        }
    }
}


   