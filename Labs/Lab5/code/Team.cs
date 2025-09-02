using System;

namespace Lab_5_1
{
    [Serializable]
    public class Team : INameAndCopy
    {
        protected string Name_Of_Org = string.Empty;
        protected int Reg_num;

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

        public string OrgName
        {
            get => Name_Of_Org;
            set => Name_Of_Org = value;
        }

        public int RegNum
        {
            get => Reg_num;
            set
            {
                if (value <= 0)
                    throw new ArgumentOutOfRangeException(nameof(value), "Регистрационный номер должен быть положительным");
                Reg_num = value;
            }
        }

        public string Name
        {
            get => Name_Of_Org;
            set => Name_Of_Org = value;
        }

        public override string ToString()
        {
            return $"{Name_Of_Org} :: {Reg_num}";
        }

        public virtual object DeepCopy()
        {
            return new Team(Name_Of_Org, Reg_num);
        }
    }
}