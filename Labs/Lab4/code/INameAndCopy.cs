namespace Lab_4
{
    public interface INameAndCopy
    {
        string Name { get; set; }
        object DeepCopy();
    }
}