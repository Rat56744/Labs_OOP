using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;



namespace Lab3
{
    class Paper : IComparable<Paper>, IComparer<Paper>
    {
        public string Title { get; set; }
        public Person Person { get; set; }
        public DateTime PublicationDate { get; set; }

        public Paper(string _title, Person _person, DateTime date_pub_value)
        {
            Title = _title;
            Person = _person;
            PublicationDate = date_pub_value;
        }
        public Paper()
        {
            Title = "NoData";
            Person = new Person();
            PublicationDate = new DateTime(1999, 12, 31);
        }

        public override string ToString()
        {
            return Title + " " + Person.ToString() + " " + PublicationDate.ToShortDateString();
        }

        public int CompareTo(Paper? obj) // Релизация интерфейса IComparable. Сравнение по дате выхода
        {
            return PublicationDate.CompareTo(obj.PublicationDate);
        }

        public int Compare(Paper? x, Paper? y) // Реализация интерфейса IComparer Сравнение по названию публикации
        {
            return x.Title.CompareTo(y.Title);
        }
    }
}