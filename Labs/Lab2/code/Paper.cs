using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{
    public class Paper
    {
        public Paper(string name_value, Person surname_value, System.DateTime date_value)
        {
            NameValue = name_value;
            SurnameValue = surname_value;
            DateValue = date_value;
        }
        public Paper()
        {
            NameValue = "NoData";
            SurnameValue = new Person();
            DateValue = new System.DateTime(2000, 1, 1);
        }

        public string NameValue { get; set; }
        public Person SurnameValue { get; set; }
        public System.DateTime DateValue { get; set; }
        public override string ToString()
        {
            return NameValue + " " + SurnameValue.ToString() + " " + DateValue.ToShortDateString();
        }
        public object DeepCopy()
        {
            Paper temp = new Paper(NameValue, SurnameValue, DateValue);
            return temp;
        }
    }
}