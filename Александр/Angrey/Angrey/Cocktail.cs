using System;
using System.Collections.Generic;

namespace Angrey
{
    [Serializable]
    public class Cocktail
    {
        public string Name;
        public int Prise;
        List<Ingredient> ingredients = new List<Ingredient>();
        public int ResultVolume;
        public void CountVolume()
        {
            ResultVolume = 0;
            foreach (var i in ingredients)
                ResultVolume += i.Volume;
        }
        public void Add()
        {
            Console.WriteLine("Имя:");
            Name = Console.ReadLine();
            Console.WriteLine("Введите цену:");
            Prise = Convert.ToInt32(Console.ReadLine());
            bool whil = true;
            while (whil)
            {
                Console.WriteLine("Выберите операцию:\n1 - Добавить эллемент\n2 - Законьчить добавление");
                string selection = Console.ReadLine();
                switch (selection)
                {
                    case "1":
                        Ingredient ingr = new Ingredient();
                        Console.WriteLine("Введите имя ингридиента");
                        ingr.Name = Console.ReadLine();

                        Console.WriteLine("Введите объём ингридиента");
                        ingr.Volume = Convert.ToInt32(Console.ReadLine());
                        ingredients.Add(ingr);
                        break;
                    case "2":
                        whil = false;
                        break;
                    default:
                        Console.WriteLine("Неверно введены данные");
                        break;
                }
            }
        }
        public Cocktail(int prise, List<Ingredient> Ingredients)
        {
             Prise = prise;
             ingredients = Ingredients;
             CountVolume();
        }
        public Cocktail() { }
        public override string ToString()
        {
            CountVolume();
            string result = $"Название {Name} Цена {Prise}  Объём товаров {ResultVolume}\n";
            foreach (var item in ingredients)
            {
                result += item.ToString() + "\n";
            }
            return result;
        }
    }
}
