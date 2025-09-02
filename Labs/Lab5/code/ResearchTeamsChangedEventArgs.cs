using System;

namespace Lab_5_1
{
    public class ResearchTeamsChangedEventArgs<TKey> : EventArgs
    {
        public string Namecollect { get; set; } = string.Empty;
        public Revision Reason { get; set; }
        public string NameRT { get; set; } = string.Empty;
        public int NumbregRT { get; set; }

        public ResearchTeamsChangedEventArgs(string namecollectValue, Revision reasonValue, string nameRTValue, int numbtegRTValue)
        {
            Namecollect = namecollectValue;
            Reason = reasonValue;
            NameRT = nameRTValue;
            NumbregRT = numbtegRTValue;
        }

        public override string ToString()
        {
            return $"Название коллекции: {Namecollect} Информация о событии: {Reason} Название свойства: {NameRT} Номер регистрации объекта: {NumbregRT}";
        }
    }
}