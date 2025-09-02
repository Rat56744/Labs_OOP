using System;
using System.Collections.Generic;

namespace Lab_5_1
{
    public delegate KeyValuePair<TKey, TValue> GenerateElement<TKey, TValue>(int j) where TKey : notnull;

    public class TestCollections<TKey, TValue> where TKey : notnull
    {
        private List<TKey> genericKeys = new List<TKey>();
        private List<string> stringKeys = new List<string>();
        private Dictionary<TKey, TValue> genericDict = new Dictionary<TKey, TValue>();
        private Dictionary<string, TValue> stringDict = new Dictionary<string, TValue>();
        private GenerateElement<TKey, TValue> genElement;

        public TestCollections(int collectionSize, GenerateElement<TKey, TValue> func)
        {
            genElement = func;

            for(int i = 0; i < collectionSize; i++)
            {
                var element = genElement(i);
                genericKeys.Add(element.Key);
                genericDict.Add(element.Key, element.Value);

                string sKey = i.ToString();
                stringKeys.Add(sKey);
                stringDict.Add(sKey, element.Value);
            }
        }
        
        public bool Contains(TKey key)
        {
            return genericKeys.Contains(key);
        }
        
        public bool Contains(string key)
        {
            return stringKeys.Contains(key);
        }

        public bool ContainKey(TKey key)
        {
            return genericDict.ContainsKey(key);
        }

        public bool ContainKey(string key)
        {
            return stringDict.ContainsKey(key);
        }

        public bool ContainsValue(TValue value)
        {
            return genericDict.ContainsValue(value);
        }
    }
}