namespace Lab_5_1
{
    public class TeamsJournalEntry
    {
        public string Namecollect { get; set; } = string.Empty;
        public Revision Reason { get; set; }
        public string NameRt { get; set; } = string.Empty;
        public int NumbRegRt { get; set; }

        public TeamsJournalEntry(string namecollectValue, Revision reasonValue, string nameRTValue, int numbtegRTValue)
        {
            Namecollect = namecollectValue;
            Reason = reasonValue;
            NameRt = nameRTValue;
            NumbRegRt = numbtegRTValue;
        }

        public override string ToString()
        {
            return $"{Namecollect}: Information: [{Reason}] Name: [{NameRt}] ID: [{NumbRegRt}]";
        }
    }
}