using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Serialization;

namespace Pavel_Kursach
{
    class Program
    {
        static async System.Threading.Tasks.Task Main(string[] args)
        {
            while (true)
            { 
            List<Client> Array = new List<Client>();
      
            XmlSerializer formatter = new XmlSerializer(typeof(List<Client>));
            try
            {
               
                using (FileStream fs = new FileStream("client.xml", FileMode.OpenOrCreate))
                {
                    Array = (List<Client>)formatter.Deserialize(fs);
                }
            }
            catch(InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("Выберите желаемую операцию");
            Console.WriteLine("1 - Просмотреть список клиентов");
            Console.WriteLine("2 - Добавить нового клиента");
            Console.WriteLine("3 - Удалить клиета");
            Console.WriteLine("4 - Сортировка");
            Console.WriteLine("5 - Изменить данные");
            string selection = Console.ReadLine();
                switch (selection)
                {
                    case "1":
                        int i = 0;
                        foreach (Client p in Array)
                        {
                            Console.WriteLine($"Id: {i}" + p.ToString());
                            i++;
                        }
                        break;
                    case "2":
                        
                        Client client = new Client();
                        client.AddData();
                        Array.Add(client);
                        Save(formatter, Array);
                        break;
                    case "3":
                        Console.WriteLine($"Введите номер удаляемого эллемента\nКолличество эллементов: {Array.Count}");
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
                                if (Number > Array.Count || Number < 1)
                                    Console.WriteLine("Номер находиться вне обсасти допустимых значений");
                                else
                                    break;
                            }
                            else
                                Console.WriteLine("Номер введён неправильно!");

                        }
                        Array.RemoveAt(Number - 1);
                        File.Delete("client.xml");
                        Save(formatter, Array);
                        break;
                    case "4":
                        Console.WriteLine("Выберите позитицию для сортировки");
                        Console.WriteLine("1 - Имя");
                        Console.WriteLine("2 - Возвраст");
                        Console.WriteLine("3 - Инструмент");
                        string choice = Console.ReadLine();
                        switch (choice)
                        {
                            case "1":
                                IEnumerable<Client> sortedAge = Array.OrderBy(i => i.Age);
                                Print(sortedAge);
                                break;
                            case "2":
                                IEnumerable<Client> sortedName = Array.OrderBy(i => i.Name);
                                Print(sortedName);
                                break;
                            case "3":
                                IEnumerable<Client> sortedInstrument = Array.OrderBy(i => i.Musical_Instrumenta);
                                Print(sortedInstrument);
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
                            Console.WriteLine($"Введите номер изменяемого эллемента\nКолличество эллементов: {Array.Count}");
                            string NumberStr = Console.ReadLine();
                            bool check = int.TryParse(NumberStr, out result);
                            if (check)
                            {
                                number = Convert.ToInt32(NumberStr);
                                if (number > Array.Count || number < 1)
                                    Console.WriteLine("Номер находиться вне обсасти допустимых значений");
                                else
                                    break;
                            }
                            else
                                Console.WriteLine("Номер введён неправильно!");

                        }
                        Array[number - 1].AddData();
                        File.Delete("client.xml");
                        Save(formatter, Array);
                        break;
                    default:
                        Console.WriteLine("Данные введены не верно");
                        break;
                }
            }            
        }
        public static void Save(XmlSerializer formatter, List<Client> Array)
        {
            using (FileStream fs = new FileStream("client.xml", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, Array);
            }
        }
        public static void Print(IEnumerable<Client> Array)
        {
            foreach (var i in Array)
            {
                Console.WriteLine(i.ToString());
            }
        }
    }
   
}
