using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;

namespace Lab_4
{
    enum Revision { Remove, Replace, Property };
    delegate void ResearchTeamsChangedHandler<TKey>(object source, ResearchTeamsChangedEventArgs<TKey> args);
  
    class ResearchTeam : Team, IEnumerable, INameAndCopy, INotifyPropertyChanged
    {
        #region Private

        private string theme;
        private TimeFrame listpub;
        private List<Person> participants;
        private List<Paper> publications;

        #endregion

        #region Constructors

        public ResearchTeam(string theme_value, string name_of_org_value, int reg_num_value, TimeFrame listPub_value) :
            base(theme_value, reg_num_value) // Часть полей в базовом классе Team
        {
            Name_Of_Org = name_of_org_value;
            listpub = listPub_value;
            publications = new List<Paper>();
            participants = new List<Person>();
        }

        public ResearchTeam() : base("MIET", 0) // Часть полей в базовом классе Team
        {
            Name_Of_Org = "MIET";
            listpub = TimeFrame.Year;
            participants = new List<Person>();
            publications = new List<Paper>();
        }

        #endregion

        
        public event PropertyChangedEventHandler PropertyChanged;
        public string Theme
        {
            get { return theme; }
            set
            {stl
                theme = value; 
                PropertyChanged(this,new PropertyChangedEventArgs("Theme"));
            }
        }

        public TimeFrame Listpub
        {
            get { return listpub; }
            set
            {
                listpub = value;
                PropertyChanged(this,new PropertyChangedEventArgs("List Pub"));
            }
        }

        #region Get/Set (From 3 laboratory)

        public List<Paper> Publications
        {
            get { return publications; }
            set { publications = value; }
        }

        public List<Person> Participants
        {
            get { return participants; }
            set { participants = value; }
        }

        public Team Base // Часть полей в базовом классе Team
        {
            get { return new Team(Name_Of_Org, Reg_num); }
            set
            {
                Name_Of_Org = value.OrgName;
                Name = value.Name;
                Reg_num = value.RegNum;
            }
        }
        
        public bool this[TimeFrame _listpub]
        {
            get { return _listpub == listpub; }
        }


        #endregion
       
        //перегруженную версию виртуального метода object DeepCopy();
        public new object DeepCopy()
        {
            ResearchTeam copy = new ResearchTeam(theme, Name_Of_Org, Reg_num, listpub);
            for (int i = 0; i < publications.Count; i++)
            {
                copy.publications.Add(publications[i]); //добавление нового элемента в публикации для копирования
            }
            for (int i = 0; i < participants.Count; i++)
            {
                copy.participants.Add(participants[i]); 
            }
            return copy;
        }

        //метод void AddPapers (params Paper*+ ) для добавления элементов в список публикаций;
        public void AddPapers(params Paper[] newPapers)
        {
            for (int i = 0; i < newPapers.Length; i++)
            {
                publications.Add(newPapers[i]); //добавление нового элемента в публикации
            }
        }

        //метод void AddMembers ( params Person[] ) для добавления элементов в список участников проекта;
        public void AddMembers(params Person[] newPersons)
        {
            for (int i = 0; i < newPersons.Length; i++)
            {
                participants.Add(newPersons[i]); //добавление нового элемента в участников проекта
            }
        }

        //Перегруженный ToString
        public override string ToString()
        {
            string text = "Theme: " + theme + " OrgName: " + Name_Of_Org + " ID: " + Reg_num + " Duration: " + listpub;
            text += "\nПубликации:\n";
            for (int i = 0; i < publications.Count; i++)
            {
                text += publications[i] + "\n"; //Выводим публикации
            }
            text += "\nУчастники:\n";
            for (int i = 0; i < participants.Count; i++)
            {
                text += participants[i] + "\n"; //Выводим поиск
            }

            return text;
        }
        
        public virtual string ToShortString()
        {
            return theme + " " + Name_Of_Org + " " + Reg_num + " " + listpub;
        }
        
        string INameAndCopy.Name
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
        

        #region IEnumerable

        public IEnumerable SearchPersonWithoutPublic()
        {
            int count = 0;
            for (int i = 0; i < participants.Count; i++)
            {
                bool isCorrect = false;
                for (int j = 0; j < publications.Count; j++)
                {
                    //Автор которой есть в Paper сравнивается с автором из Person
                    if ((publications[j] as Paper).AuthorValue.Equals((Person) participants[i]))
                    {
                        isCorrect = true;
                        break;
                    }

                }

                if (!isCorrect) //Если не у всех пользователей есть публикацаии то возвращать...
                {
                    count++;
                    yield return participants
                        [i]; //Оператор yield return используется для возврата каждого элемента по одному.

                }
            }

            if (count == 0)
            {
                Console.WriteLine("У всех пользователей есть публикации");
            }
        }

        public IEnumerable SearchPublications(int n)
        {
            DateTime now = DateTime.Now;
            int count = 0;
            for (int i = 0; i < publications.Count; i++)
            {
                //TotalDays Свойство представляет целые и дробные дни
                if (((now - (publications[i] as Paper).DateValue).TotalDays / 365) < n
                ) //Если разница меньше 2 то вернуть ...
                {
                    count++;
                    yield return publications
                        [i]; //Оператор yield return используется для возврата каждого элемента по одному.
                }
            }

            if (count == 0)
            {
                Console.WriteLine("Все публикации опубликованы раньше");
            }
        }
        // Дополнительное задание:
        public IEnumerable SearchTwoAndMorePublication()
        {
            int count = 0;
            for (int i = 0; i < participants.Count; i++)
            {
                int count2 = 0;
                for (int j = 0; j < publications.Count; j++)
                {
                    //Автор которой есть в Paper сравнивается с автором из Person
                    if ((publications[j] as Paper).AuthorValue.Equals((Person) participants[i]))
                    {
                        count2++;
                    }
                }

                if (count2 > 1)
                {
                    //Если больше 1 то вернуть ...
                    yield return participants
                        [i]; //Оператор yield return используется для возврата каждого элемента по одному.
                    count++;
                }
            }

            if (count == 0)
            {
                Console.WriteLine("Все участники сделали меньше 2 публикации");
            }
        }

        public IEnumerable SearchLastYearPublication()
        {
            int count = 0;
            for (int i = 0; i < publications.Count; i++)
            {
                if (((DateTime.Now - (publications[i] as Paper).DateValue).TotalDays / 365) < 1)
                {
                    count++;
                    yield return publications[i];
                }
            }

            if (count == 0)
            {
                Console.WriteLine("Все публикации выпущены раньше");
            }

        }

        public IEnumerator GetEnumerator()
        {
            return new ResearchTeamEnumerator(participants, publications);
        }
        
        #endregion
    }
}