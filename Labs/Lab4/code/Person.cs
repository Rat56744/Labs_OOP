using System;
namespace Lab_4
{
    class Person : INameAndCopy
    {
        private string NameValue;
        private string SurnameValue;
        private System.DateTime birthday;

        //Конструктор
        public Person(string nameValue, string surnameValue, System.DateTime _birthday)
        {
            NameValue = nameValue;
            SurnameValue = surnameValue;
            birthday = _birthday;
        }
        public Person()
        {
            NameValue = "Stas";
            SurnameValue = "Ivashkov";
            birthday = new DateTime(1999, 12, 31);
        }
        
        //Get/Set
        public string Name
        {
            get
            {
                return NameValue;
            }
            set { NameValue = value; }
        }
        
        public string Surname
        {
            get
            {
                return SurnameValue;
            }
            set { SurnameValue = value; }
        }
        public DateTime Birthday
        {
            get
            {
                return birthday;
            }
            set
            { birthday = value; }
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
        
        //Определяет, равны ли два экземпляра объекта.
        public override bool Equals(object obj) //obj - Объект, который требуется сравнить с текущим объектом.
        {
            Person tempPerson = (Person)obj;
            return NameValue.Equals(tempPerson.NameValue) && SurnameValue.Equals(tempPerson.SurnameValue) && birthday.Equals(tempPerson.birthday);
        }
        
        //виртуальный метод int GetHashCode();
        public override int GetHashCode()
        {
            return (NameValue + SurnameValue).GetHashCode() + birthday.GetHashCode();//Хэш-код для текущих объектов
        }

        //Перегрузка операторов, чтобы трактовалось как совпадение данных , а не ссылок
        public static bool operator !=(Person person1, Person person2)
        {
            return !person1.Equals(person2);
        }
        public static bool operator ==(Person person1, Person person2)
        {
            return person1.Equals(person2);
        }
        
        //определить виртуальный метод object DeepCopy()
        public object DeepCopy()
        {
            Person result = new Person(NameValue, SurnameValue, birthday);
            return result;
        }
        
        //виртуальный метод string ToString() для формирования строки со значениями всех полей класса
        public override string ToString()
        {
            return (NameValue + " " + SurnameValue + " " + birthday.ToShortDateString());
        }
    }
}