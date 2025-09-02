using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    internal class PaperComparer : IComparer<Paper> // Вспомогательный класс для сравнения объектов
                                                    // типа Paper по фамилии автора
    {
        public int Compare(Paper? x, Paper? y) // Реализация интерфейса IComparer
        {
            return x.Person.Surname.CompareTo(y.Person.Surname);
        }
    }
}
