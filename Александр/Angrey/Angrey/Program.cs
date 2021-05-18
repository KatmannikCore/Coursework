using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace Angrey
{
    class Program
    {
        static void Main(string[] args)
        {
          
            List<Cocktail> cocktails = new List<Cocktail>();
            BinaryFormatter formatter = new BinaryFormatter();
            try
            {
                using (FileStream fs = new FileStream("client.dat", FileMode.OpenOrCreate))
                {
                    cocktails = (List<Cocktail>)formatter.Deserialize(fs);
                }
            }
            catch (SerializationException ex)
            {
                Console.WriteLine(ex.Message);
            }
            while (true)
            {
                Console.WriteLine("Выберите операцию");
                Console.WriteLine("1 - Просмотреть весь список");
                Console.WriteLine("2 - Добавить эллемет в список");
                Console.WriteLine("3 - Удалить клиента");
                Console.WriteLine("4 - Сортировка");
                Console.WriteLine("5 - Изменить данные");
                string selection = Console.ReadLine();
                switch(selection)
                {
                    case "1":
                        foreach (var item in cocktails)
                        {
                            Console.WriteLine(item.ToString());
                        }
                        break;
                    case "2":
                        Cocktail cocktail = new Cocktail();
                        cocktail.Add();
                        cocktails.Add(cocktail);
                        Save(formatter, cocktails);
                        break;
                    case "3":
                        Console.WriteLine($"Введите номер удаляемого эллемента\nКолличество эллементов: {cocktails.Count}");
                        int Number;
                        while (true)
                        {
                            int result;
                            Console.WriteLine("Введите номер удаляемого эллемента: ");
                            string NumberStr = Console.ReadLine();
                            bool check = int.TryParse(NumberStr, out result);
                            if (check)
                            {
                                Number = Convert.ToInt32(NumberStr);
                                if (Number > cocktails.Count || Number < 1)
                                    Console.WriteLine("Номер находиться вне обсасти допустимых значений");
                                else
                                    break;
                            }
                            else
                                Console.WriteLine("Номер введён неправильно!");

                        }
                        cocktails.RemoveAt(Number - 1);
                        File.Delete("client.xml");
                        Save(formatter, cocktails);
                        break;
                    case "4":
                        Console.WriteLine("Выберите позитицию для сортировки");
                        Console.WriteLine("1 - Цена");
                        Console.WriteLine("2 - Имя");
                        Console.WriteLine("3 - Объём");
                        string choice = Console.ReadLine();
                        switch (choice)
                        {
                            case "1":
                                IEnumerable<Cocktail> sortedPrise = cocktails.OrderBy(i => i.Prise);
                                Print(sortedPrise);
                                break;
                            case "2":
                                IEnumerable<Cocktail> sortedName = cocktails.OrderBy(i => i.Name);
                                Print(sortedName);
                                break;
                            case "3":
                                IEnumerable<Cocktail> sortedResultVolume = cocktails.OrderBy(i => i.ResultVolume);
                                Print(sortedResultVolume);
                                break;
                            default:
                                Console.WriteLine("Вы выбрали неверный пунтк");
                                break;
                        }
                        break;
                    case "5":

                        int number = 0;
                        while (true)
                        {
                            int result;
                            Console.WriteLine($"Введите номер изменяемого эллемента\nКолличество эллементов: {cocktails.Count}");
                            string NumberStr = Console.ReadLine();
                            bool check = int.TryParse(NumberStr, out result);
                            if (check)
                            {
                                number = Convert.ToInt32(NumberStr);
                                if (number > cocktails.Count || number < 1)
                                    Console.WriteLine("Номер находиться вне обсасти допустимых значений");
                                else
                                    break;
                            }
                            else
                                Console.WriteLine("Номер введён неправильно!");

                        }
                        cocktails[number - 1].Add();
                        File.Delete("client.xml");
                        Save(formatter, cocktails);
                        break;
                    default:
                        Console.WriteLine("Данные введены не верно");
                    break;
                }
            }
        }
        public static void Save(BinaryFormatter formatter, List<Cocktail> Array)
        {
            using (FileStream fs = new FileStream("client.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, Array);
            }
        }
        public static void Print(IEnumerable<Cocktail> Array)
        {
            foreach (var i in Array)
            {
                Console.WriteLine(i.ToString());
            }
        }
    }
}
