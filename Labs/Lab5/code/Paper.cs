using System;
using System.Collections.Generic;

namespace Lab_5_1
{
    [Serializable]
    public class Paper : IComparable, IComparer<Paper>
    {
        public string NameOfPub { get; set; } = string.Empty;
        public Person AuthorValue { get; set; } = new Person();
        public DateTime DateValue { get; set; }

        public Paper(string nameOfPub, Person authorValue, DateTime dateValue)
        {
            NameOfPub = nameOfPub;
            AuthorValue = authorValue;
            DateValue = dateValue;
        }

        public Paper()
        {
            NameOfPub = "MIET";
            AuthorValue = new Person();
            DateValue = new DateTime(2000, 1, 1);
        }

        public override string ToString()
        {
            return $"{NameOfPub} {AuthorValue} {DateValue.ToShortDateString()}";
        }

        public int CompareTo(object? obj)
        {
            if (obj is not Paper other) return -1;
            return DateValue.CompareTo(other.DateValue);
        }

        public int Compare(Paper? x, Paper? y)
        {
            if (x == null) return y == null ? 0 : -1;
            if (y == null) return 1;
            return string.Compare(x.NameOfPub, y.NameOfPub, StringComparison.Ordinal);
        }

        public object DeepCopy()
        {
            return new Paper(NameOfPub, (Person)AuthorValue.DeepCopy(), DateValue);
        }
    }
}