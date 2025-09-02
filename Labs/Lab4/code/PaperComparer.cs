using System.Collections.Generic;

namespace Lab_4
{
    //Класс который можно использовать для сравнения объектов типа Paper по фамилии автора публикации
    public class PaperComparer: IComparer<Paper>
    {
        int IComparer<Paper>.Compare(Paper x, Paper y)
        {
            return x.AuthorValue.Surname.CompareTo(y.AuthorValue.Surname);
        }
    }
}