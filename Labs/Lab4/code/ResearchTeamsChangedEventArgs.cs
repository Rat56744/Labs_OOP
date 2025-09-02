using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace Lab_4
{
    class ResearchTeamsChangedEventArgs<TKey>: EventArgs
    {
        public string Namecollect { get; set; }
        public Revision Reason { get; set; }
        public string NameRT { get; set; }
        public int NumbregRT { get; set; }
        public ResearchTeamsChangedEventArgs(string Namecollect_value, Revision Reason_value, string NameRT_value, int NumbtegRT_value)
        {
            Namecollect = Namecollect_value;
            Reason = Reason_value;
            NameRT = NameRT_value;
            NumbregRT = NumbtegRT_value;
        }
        public override string ToString()
        {
            string result = "Название коллекции: " + Namecollect + " Информация о событии: " + Reason + " Название свойства: " + NameRT + " Номер регистрации объекта: " + NumbregRT;
            return result;
        }
    }
}