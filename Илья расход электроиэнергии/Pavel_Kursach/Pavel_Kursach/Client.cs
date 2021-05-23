using System;
namespace Pavel_Kursach
{
    [Serializable]
    public class Client
    {
        public string Name { get; set; }
        public string Number { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public int Energy { get; set; }
        public int Prise { get; set; }
        public static int Counter;
        public Client() { Counter++; }

        public void AddData()
        {
            Console.WriteLine("Введите имя: ");
            Name = Console.ReadLine();
            Console.WriteLine("Введите фамилию: ");
            Surname = Console.ReadLine();
            Console.WriteLine("Введите номер телефона: ");
            Number = Console.ReadLine();
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
            Console.WriteLine("Введите колличество используемой энегрии: ");
            Energy = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Введите задолжность: ");
            Prise = Convert.ToInt32(Console.ReadLine());
        }
        public override string ToString()
        {
            return $" Имя: {Name}" +
                   $" Фамилия: {Surname}" +
                   $" Возраст: {Age}" +
                   $" Колличество используемой энергии: {Energy} КВт/ч" +
                   $" Задолжность: {Prise} рублей" +
                   $" Номер телефона: {Number}";
        }
    }
}
