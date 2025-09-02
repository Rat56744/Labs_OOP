using System.Collections.Generic;

namespace Lab_5_1
{
    public class PaperComparer : IComparer<Paper>
    {
        public int Compare(Paper? x, Paper? y)
        {
            if (x == null) return y == null ? 0 : -1;
            if (y == null) return 1;
            return string.Compare(x.AuthorValue.Surname, y.AuthorValue.Surname, StringComparison.Ordinal);
        }
    }
}