namespace Lab_5_1
{
    public interface INameAndCopy
    {
        string Name { get; set; }
        object DeepCopy();
    }
}