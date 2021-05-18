import pickle
from datetime import date
import json
counter = 1
FILENAME = "test.dat"
Klient = {
"1":[
        ("Имя:","Артём"),
        ("Фамилия:" ,"Трифанов"),
        ("Отчесство:", "Валерьевич"),
        ("Возраст:","12"),
        ("Диагноз:", "Кариес"),
        ("Дата приёма:",date.today())],
"2":[
        ("Имя:", "Оксана"),
        ("Фамилия:", "Войтова"),
        ("Отчесство:", "Михайловна"),
        ("Возраст:", "12"),
        ("Диагноз:", "Кариес"),
        ("Дата приёма:", date.today())],
}

def Save():
    with open(FILENAME, 'wb') as file:
        pickle.dump(Klient, file)
with open(FILENAME, 'rb') as f:
     Klient = pickle.load(f)


while bool:
    print("Выберите операцию",  "1 - Простомтеть данные", "2 - Внести данные", "3 - Изменить", sep='\n')
    value = input()
    counter = 0
    for key in Klient.keys():
        counter += 1
    if value == '1':
        for key in Klient:
            print(key, " - ", Klient[key][0][0], Klient[key][0][1],
                              Klient[key][1][0], Klient[key][1][1],
                              Klient[key][2][0], Klient[key][2][1],
                              Klient[key][3][0], Klient[key][3][1],
                              Klient[key][4][0], Klient[key][4][1],
                              Klient[key][5][0], Klient[key][5][1])
    if value == '2':
        Add = {
            counter: [
                ("Имя:", input("Имя: ")),
                ("Фамилия:", input("Фамилия: ")),
                ("Отчесство:", input("Отчесство: ")),
                ("Возраст:", input("Возраст: ") ),
                ("Диагноз:", input("Диагноз: ")),
                ("Дата приёма:", date.today())]
        }
        Klient.update(Add)
        Save()
    if value == '3':
        print("Введите номер изменяемого пункта. Колличество пунктов:", counter - 1)
        while True:
            try:
                Number = int(input())
                if Number <1 or Number >counter-1:
                    print("Число выходит за облость допустимых значений. Попробуйте снова: ")
                else:
                    break
            except ValueError:
                print("Вы ввели не число. Попробуйте снова: ")
        Change = {
            Number: [
                ("Имя:", input("Имя: ")),
                ("Фамилия:", input("Фамилия: ")),
                ("Отчесство:", input("Отчесство: ")),
                ("Возраст:", input("Возраст: ")),
                ("Диагноз:", input("Диагноз: ")),
                ("Дата приёма:", date.today())]
        }
        Klient.update(Change)
        Save()

