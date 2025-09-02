using System;
using System.Collections.Generic;
using System.Text;

namespace Lab_5_1
{
    class TeamsJournal
    {
        // закрытое поле List<TeamsJournalEntry> для списка изменений
        private List<TeamsJournalEntry> listChange = new List<TeamsJournalEntry>(); 
        
        // обработчик события ResearchTeamsChanged
        public void OnPropertyChange(object source, ResearchTeamsChangedEventArgs<string> obj)
        {

            TeamsJournalEntry teamJE = new TeamsJournalEntry(obj.Namecollect, obj.Reason, obj.NameRT, obj.NumbregRT);
            listChange.Add(teamJE);
        }
        
        //перегруженную версию метода string ToString() для формирования строки 
        public override string ToString()
        {
            string result = "";
            foreach (TeamsJournalEntry i in listChange)
            {
                result += i.ToString() + "\n\n";
            }
            return result;
        }
    }
}