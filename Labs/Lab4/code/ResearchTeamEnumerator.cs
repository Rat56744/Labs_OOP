using System;
using System.Collections;
using System.Collections.Generic;

namespace Lab_4
{
    class ResearchTeamEnumerator : IEnumerator
    {
        
        private int ind = -1; //Задали начальную позицию
        private List<Person> listPerson;
        private List<Paper> listPaper;
        
        public ResearchTeamEnumerator(List<Person> listPerson_value, List<Paper> listPaper_value)
        {
            this.listPerson = listPerson_value;
            this.listPaper = listPaper_value;
        }

        // Выполнять пока не дойдем до конца коллекции.
        public bool MoveNext()
        {
            ind++;
            for(;;)
            {
                if (ind == listPerson.Count - 1)
                {
                    return false;
                }
                for (int i = 0; i < listPaper.Count; i++)
                {
                    Paper tmp = listPaper[i] as Paper;
                    if ((Person)listPerson[ind] == tmp.AuthorValue)
                        return true;
                }
                return false;
            }
        }
        
        public object Current // текущий элемент в контейнере
        {
            get
            {
                if (ind == -1 || ind >= listPerson.Count)
                    throw new InvalidOperationException();
                //InvalidOperationException используется в случаях, когда сбой вызова метода вызван по причинам, отличным от недопустимых аргументов.
                return listPerson[ind];
            }
        }
        
        public void Reset() // перемещение в начало контейнера
        {
            ind = -1;
        }
    }
}
