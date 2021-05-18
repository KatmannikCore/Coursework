using System;
namespace Angrey
{
    [Serializable]
    public class Ingredient
    {
        public int Volume;
        public string Name;
        public Ingredient(int volume, string name)
        {
            Name = name;
            Volume = volume;
        }
        public Ingredient() { }
        public override string ToString()
        {
            return $"Название ингридие: {Name}   Объем: {Volume}";
        }
    }
}
