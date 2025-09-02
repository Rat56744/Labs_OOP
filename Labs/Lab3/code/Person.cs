using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    public class Person : INameAndCopy
    {
        private string name;
        private string surname;
        private DateTime birthday;

        public Person(string name_value, string surname_value, System.DateTime birthday_value)
        {
            name = name_value;
            surname = surname_value;
            birthday = birthday_value;
        }
        public Person()
        {
            name = "NoData";
            surname = "Nodata";
            birthday = new System.DateTime(1999, 12, 31);
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public string Surname
        {
            get
            {
                return surname;
            }
            set
            {
                surname = value;
            }
        }
        public DateTime Birthday
        {
            get
            {
                return birthday;
            }
            set
            {
                birthday = value;
            }
        }
        public int Year
        {
            get
            {
                return birthday.Year;
            }
            set
            {
                birthday = new DateTime(value, birthday.Month, birthday.Day);
            }
        }

        public override bool Equals(object obj) // Совпадение данных, а не ссылок
        {
            Person tempPerson = (Person)obj;
            return name.Equals(tempPerson.name) && surname.Equals(tempPerson.surname) && birthday.Equals(tempPerson.birthday);
        }
        public override int GetHashCode()
        {
            return name.GetHashCode() + surname.GetHashCode() + birthday.GetHashCode();// Хэш-код для текущих объектов
        }

        // Перегрузка операторов, чтобы трактовалось как совпадение данных, а не ссылок на объекты Person
        public static bool operator !=(Person person1, Person person2)
        {
            return !person1.Equals(person2);
        }
        public static bool operator ==(Person person1, Person person2)
        {
            return person1.Equals(person2);
        }
        public object DeepCopy() // Виртуальный метод object DeepCopy()
        {
            Person result = new Person(name, surname, birthday);
            return result;
        }
        public virtual string ToShortString()
        {
            return name + " " + surname;
        }
        public override string ToString()
        {
            return Name + " " + Surname + " " + birthday.ToShortDateString();
        }
    }
}
