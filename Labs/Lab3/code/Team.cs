using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    public class Team
    {
        protected string Name_Of_Org;
        protected int Reg_num;

        public Team(string nameOfOrg, int regNum)
        {
            this.Name_Of_Org = nameOfOrg;
            this.Reg_num = regNum;
        }
        public Team() : this("MIET", 31) { }

        public string NameOrg
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

        public int RegNum
        {
            get
            {
                return Reg_num;
            }
            set
            {
                try
                {
                    if (value <= 0) throw new ArgumentOutOfRangeException();
                    Reg_num = value;
                }
                catch (ArgumentOutOfRangeException)
                {
                    throw;
                }
            }
        }
        public string Name { get; set; }
        public object DeepCopy()
        {
            return new Team(Name_Of_Org, Reg_num);
        }
        public override bool Equals(object obj)
        {
            Team tmp = (Team)obj;
            return (Name_Of_Org == tmp.Name_Of_Org) && (Reg_num == tmp.Reg_num);
        }

        public static bool operator !=(Team team1, Team team2)
        {
            return !team1.Equals(team2);
        }
        public static bool operator ==(Team team1, Team team2)
        {
            return team1.Equals(team2);
        }
        public override int GetHashCode()
        {
            return Name_Of_Org.GetHashCode() + Reg_num.GetHashCode(); // Хэш-код для текущих объектов
        }
        public override string ToString()
        {
            return Name_Of_Org + " :: " + Reg_num.ToString();
        }
    }
}