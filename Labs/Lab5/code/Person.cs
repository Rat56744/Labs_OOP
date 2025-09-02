using System;

namespace Lab_5_1
{
    [Serializable]
    public class Person : INameAndCopy
    {
        public string Name { get; set; } = string.Empty;
        public string Surname { get; set; } = string.Empty;
        public DateTime Birthday { get; set; }

        public Person(string name, string surname, DateTime birthday)
        {
            Name = name;
            Surname = surname;
            Birthday = birthday;
        }

        public Person()
        {
            Name = "Nickolay";
            Surname = "Yazykov";
            Birthday = new DateTime(2000, 1, 1);
        }

        public override bool Equals(object? obj)
        {
            return obj is Person person &&
                   Name == person.Name &&
                   Surname == person.Surname &&
                   Birthday == person.Birthday;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name, Surname, Birthday);
        }

        public static bool operator ==(Person? left, Person? right)
        {
            return EqualityComparer<Person>.Default.Equals(left, right);
        }

        public static bool operator !=(Person? left, Person? right)
        {
            return !(left == right);
        }

        public virtual object DeepCopy()
        {
            return new Person(Name, Surname, Birthday);
        }

        public override string ToString()
        {
            return $"{Name} {Surname} {Birthday.ToShortDateString()}";
        }
    }
}