using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    class Paper : IComparable, IComparer<Paper>
    {
        public Paper(string nameOfPub, Person authorValue, System.DateTime dateValue)
        {
            NameOfPub = nameOfPub;
            AuthorValue = authorValue;
            DateValue = dateValue;
        }
        public Paper()
        {
            NameOfPub = "MIET";
            AuthorValue = new Person();
            DateValue = new System.DateTime(2000, 1, 1);
        }
        
        public string NameOfPub { get; set; }
        public Person AuthorValue { get; set; }
        public System.DateTime DateValue { get; set; }
        
        //виртуальный метод string ToString() для формирования строки со значениями всех полей класса
        public override string ToString()
        {
            return NameOfPub + " " + AuthorValue.ToString() + " " + DateValue.ToShortDateString();
        }
        
        // CompareTo Сравнивает текущий экземпляр с другим объектом того же типа и возвращает целое число
        public int CompareTo(object obj)
        {
            if(obj.GetType() != GetType())
            {
                return -1;
            }
            // Для сравнения объектов типа Paper по дате выхода публикации;
            return DateValue.CompareTo((obj as Paper).DateValue);
        }
        
        // для сравнения объектов типа Paper по названию публикации.
        public int Compare(Paper x, Paper y)
        {
            return x.NameOfPub.CompareTo(y.NameOfPub);
        }

    }
}