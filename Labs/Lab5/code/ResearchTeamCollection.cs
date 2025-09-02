using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;

namespace Lab_5_1
{
    public delegate TKey KeySelector<TKey>(ResearchTeam rt);
    public delegate void ResearchTeamsChangedHandler<TKey>(object source, ResearchTeamsChangedEventArgs<TKey> args);

    public enum Revision
    {
        Add,
        Remove,
        Replace,
        Property
    }

    public class ResearchTeamCollection<TKey> where TKey : notnull
    {
        private Dictionary<TKey, ResearchTeam> teamsDictionary;
        private KeySelector<TKey> KeyFunctionValue;

        public ResearchTeamCollection(KeySelector<TKey> functionValue)
        {
            KeyFunctionValue = functionValue;
            teamsDictionary = new Dictionary<TKey, ResearchTeam>();
        }

        public string Namecollect { get; set; } = string.Empty;
        public event ResearchTeamsChangedHandler<TKey>? ResearchTeamsChanged;

        public void AddDefaults()
        {
            ResearchTeam rt1 = new ResearchTeam("Team1", "Org1", 1, TimeFrame.Year);
            ResearchTeam rt2 = new ResearchTeam("Team2", "Org2", 2, TimeFrame.TwoYears);
            AddResearchTeams(rt1, rt2);
        }

        public void AddResearchTeams(params ResearchTeam[] teams)
        {
            foreach (var team in teams)
            {
                TKey key = KeyFunctionValue(team);
                if (!teamsDictionary.ContainsKey(key))
                {
                    teamsDictionary.Add(key, team);
                    team.PropertyChanged += OnPropertyChange;
                }
            }
        }

        private void OnPropertyChange(object? sender, PropertyChangedEventArgs args)
        {
            if (sender is ResearchTeam rt)
            {
                ResearchTeamsChanged?.Invoke(this, 
                    new ResearchTeamsChangedEventArgs<TKey>(
                        Namecollect, 
                        Revision.Property, 
                        args.PropertyName ?? "Unknown", 
                        rt.RegNum));
            }
        }

        public override string ToString()
        {
            return string.Join("\n", teamsDictionary.Values);
        }
    }
}