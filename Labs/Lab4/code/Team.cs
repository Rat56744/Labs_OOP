using System;

namespace Lab_4
{
    class Team : INameAndCopy
    {
        protected string Name_Of_Org;
        protected int Reg_num;
        
        //Конструктор
        public Team(string nameOfOrg, int regNum)
        {
            Name_Of_Org = nameOfOrg;
            Reg_num = regNum;
        }
        public Team()
        {
            Name_Of_Org = "MIET";
            Reg_num = 31;
        }
        
        //Cвойство типа string для доступа к полю с названием организации; 
        public string OrgName
        {
            get
            {
                return Name_Of_Org;
            } 
            set
            {
                Name_Of_Org = value;
            } 
        }
        
        //Cвойство типа int для доступа к полю с номером регистрации; в методе set бросить исключение
        public int RegNum
        {
            get
            {
                return Reg_num;
            }
            set
            {
                try {
                    if (value <= 0) throw new ArgumentOutOfRangeException();
                    Reg_num = value;
                    // ArgumentOutOfRangeException() - Исключение, которое выдается, если значение аргумента не соответствует допустимому диапазону значений, установленному вызванным методом.
                }           
                catch (ArgumentOutOfRangeException) {
                    throw;                 
                }
            }
        }
        
        public string Name { get; set; }
        
        //Определили виртуальный метод
        public object DeepCopy()
        {
            return new Team(Name_Of_Org, Reg_num);
        }
        
        //Определяет, равны ли два экземпляра объекта.
        public override bool Equals(object obj) //obj - Объект, который требуется сравнить с текущим объектом.
        {
            Team tmp = (Team)obj;
            return (Name_Of_Org == tmp.Name_Of_Org) && (Reg_num == tmp.Reg_num); 
        }
        
        //Перегрузка опрераторов
        public static bool operator !=(Team team1, Team team2)
        {
            return !team1.Equals(team2);
        }
        public static bool operator ==(Team team1, Team team2)
        {
            return team1.Equals(team2);
        }
        
        //виртуальный метод int GetHashCode();
        public override int GetHashCode()
        {
            return Name_Of_Org.GetHashCode() + Reg_num.GetHashCode(); //Хэш-код для текущих объектов
        }
        
        //виртуальный метод string ToString() для формирования строки со значениями всех полей класса
        public override string ToString()
        {
            return Name_Of_Org + " :: " + Reg_num.ToString();
        }
    }
}