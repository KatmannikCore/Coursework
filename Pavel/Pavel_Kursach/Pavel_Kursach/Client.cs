using System;
namespace Pavel_Kursach
{
    [Serializable]
    public class Client
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Musical_Instrument { get; set; }
        public string Number { get; set; }
        public static int Counter;
        public Client() { Counter++; }

        public void AddData()
        {
            Console.WriteLine("Введите имя: ");
            Name = Console.ReadLine();
            while (true)
            {
                int result;
                Console.WriteLine("Введите возраст: ");
                string AgeStr = Console.ReadLine();
                bool check = int.TryParse(AgeStr, out result);
                if (check)
                {
                    Age = Convert.ToInt32(AgeStr);
                    if (Age > 100 || Age < 1)
                        Console.WriteLine("Номер находиться вне обсасти допустимых значений");
                    else
                        break;
                }
                else
                    Console.WriteLine("Возраст введён неправильно!");
            }
            Console.WriteLine("Введите музыкальный инструмент: ");
            Musical_Instrument = Console.ReadLine();
            Console.WriteLine("Введите номер телефона: ");
            Number = Console.ReadLine();
        }
        public override string ToString()
        {
            return $" Имя: {Name}" +
                   $" Возраст: {Age}" +
                   $" Музыкальный инструмент: {Musical_Instrument}" +
                   $" Номер телефона: {Number}";
        }
    }
}
