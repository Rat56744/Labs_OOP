using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Lab_5_1
{
    [Serializable]
    public class ResearchTeam : Team, INameAndCopy, INotifyPropertyChanged
    {
        private string theme = string.Empty;
        private TimeFrame timeFrame;
        private List<Paper> papers = new List<Paper>();
        private List<Person> members = new List<Person>();
        public event PropertyChangedEventHandler? PropertyChanged;

        public string Theme
        {
            get => theme;
            set
            {
                theme = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Theme)));
            }
        }

        public TimeFrame TimeFrame
        {
            get => timeFrame;
            set
            {
                timeFrame = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(TimeFrame)));
            }
        }

        public List<Paper> Papers
        {
            get => papers;
            set
            {
                papers = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Papers)));
            }
        }

        public List<Person> Members
        {
            get => members;
            set
            {
                members = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Members)));
            }
        }

        public ResearchTeam(string theme, string orgName, int regNum, TimeFrame timeFrame)
            : base(orgName, regNum)
        {
            Theme = theme;
            TimeFrame = timeFrame;
        }

        public ResearchTeam() : base()
        {
            Theme = "Default theme";
            TimeFrame = TimeFrame.Year;
        }

        public void AddPapers(params Paper[] newPapers)
        {
            papers.AddRange(newPapers);
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Papers)));
        }

        public void AddMembers(params Person[] newMembers)
        {
            members.AddRange(newMembers);
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Members)));
        }

        public new ResearchTeam DeepCopy()
        {
            var options = new JsonSerializerOptions 
            { 
                WriteIndented = true,
                ReferenceHandler = ReferenceHandler.Preserve
            };
            
            using var stream = new MemoryStream();
            JsonSerializer.Serialize(stream, this, options);
            stream.Position = 0;
            return JsonSerializer.Deserialize<ResearchTeam>(stream, options)!;
        }

        public bool Save(string filename)
        {
            try
            {
                var options = new JsonSerializerOptions 
                {
                    WriteIndented = true,
                    ReferenceHandler = ReferenceHandler.Preserve
                };
                File.WriteAllText(filename, JsonSerializer.Serialize(this, options));
                return true;
            }
            catch
            {
                return false;
            }
        }

        public bool Load(string filename)
        {
            try
            {
                var options = new JsonSerializerOptions 
                {
                    ReferenceHandler = ReferenceHandler.Preserve
                };
                var loaded = JsonSerializer.Deserialize<ResearchTeam>(File.ReadAllText(filename), options);
                
                if (loaded != null)
                {
                    Theme = loaded.Theme;
                    OrgName = loaded.OrgName;
                    RegNum = loaded.RegNum;
                    TimeFrame = loaded.TimeFrame;
                    Papers = loaded.Papers;
                    Members = loaded.Members;
                    return true;
                }
                return false;
            }
            catch
            {
                return false;
            }
        }

        public static bool Save(string filename, ResearchTeam rt)
        {
            try
            {
                var options = new JsonSerializerOptions 
                {
                    WriteIndented = true,
                    ReferenceHandler = ReferenceHandler.Preserve
                };
                File.WriteAllText(filename, JsonSerializer.Serialize(rt, options));
                return true;
            }
            catch
            {
                return false;
            }
        }

        public static bool Load(string filename, ref ResearchTeam rt)
        {
            try
            {
                var options = new JsonSerializerOptions 
                {
                    ReferenceHandler = ReferenceHandler.Preserve
                };
                var loaded = JsonSerializer.Deserialize<ResearchTeam>(File.ReadAllText(filename), options);
                
                if (loaded != null)
                {
                    rt.Theme = loaded.Theme;
                    rt.OrgName = loaded.OrgName;
                    rt.RegNum = loaded.RegNum;
                    rt.TimeFrame = loaded.TimeFrame;
                    rt.Papers = loaded.Papers;
                    rt.Members = loaded.Members;
                    return true;
                }
                return false;
            }
            catch
            {
                return false;
            }
        }

        public bool AddFromConsole()
        {
            Console.WriteLine("Введите данные публикации в формате: Название|Фамилия автора|Имя автора|Год рождения|Месяц|День|Год публикации");
            string? input = Console.ReadLine();
            
            if (string.IsNullOrWhiteSpace(input))
            {
                Console.WriteLine("Ошибка ввода: пустая строка");
                return false;
            }

            try
            {
                string[] parts = input.Split('|');
                if (parts.Length != 7)
                {
                    throw new FormatException("Неверный формат ввода");
                }

                var author = new Person(
                    parts[2].Trim(),
                    parts[1].Trim(),
                    new DateTime(int.Parse(parts[3]), int.Parse(parts[4]), int.Parse(parts[5]))
                );

                var paper = new Paper(
                    parts[0].Trim(),
                    author,
                    new DateTime(int.Parse(parts[6]), 1, 1)
                );

                AddPapers(paper);
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка ввода: {ex.Message}");
                return false;
            }
        }

        public override string ToString()
        {
            return $"ResearchTeam: {Theme}, {OrgName}, {RegNum}, {TimeFrame}\n" +
                   $"Papers:\n{string.Join("\n", Papers)}\n" +
                   $"Members:\n{string.Join("\n", Members)}";
        }
    }
}