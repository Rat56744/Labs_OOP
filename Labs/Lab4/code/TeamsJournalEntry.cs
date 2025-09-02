using System;
using System.Collections.Generic;
using System.Text;

namespace Lab_4
{
    class TeamsJournalEntry
    {
        public string Namecollect { get; set; } // автореализуемые свойства типа string с названием коллекции;
        public Revision Reason { get; set; }// автореализуемые свойства типа Revision c информацией о типе события;
        public string NameRt { get; set; }// автореализуемые типа string с названием свойства класса ResearchTeam;
        public int NumbRegRt { get; set; }// автореализуемые свойства типа int с номером регистрации объекта ResearchTeam;
        
        //Конструктор
        public TeamsJournalEntry(string namecollectValue, Revision Reason_value, string NameRT_value, int NumbtegRT_value)
        {
            Namecollect = namecollectValue;
            Reason = Reason_value;
            NameRt = NameRT_value;
            NumbRegRt = NumbtegRT_value;
        }
        
        //Перегруженная ToString
        public override string ToString()
        {
            return   Namecollect+ ": " + "Information: [" + Reason + "] Name: [" + NameRt + "] ID: [" + NumbRegRt + "]";
        }
    }
}