import pickle
from tkinter import *
from tkinter import messagebox
import sys
root = Tk()
root.geometry("200x500")
root.title("Войти в систему")

# Регистрация
def registration():
    text = Label(text="Для входа - зарегистрируйтесь")
    text_log = Label(text="Введите ваш логин:")
    registr_login = Entry()
    text_password1 = Label(text="ВВедите ваш пароль:")
    registr_password1 = Entry()
    text_password2 = Label(text="Еще раз пароль:")
    registr_password2 = Entry(show="*")
    button_register = Button(text="Зарегистрироваться", command=lambda: save())
    text.pack()
    text_log.pack()
    registr_login.pack()
    text_password1.pack()
    registr_password1.pack()
    text_password2.pack()
    registr_password2.pack()
    button_register.pack()

    def save():
        login_pass_save = {}
        login_pass_save[registr_login.get()] = registr_password1.get()
        f = open("login.txt", "wb")
        pickle.dump(login_pass_save, f)
        f.close()
        login()

def login():
    text_log = Label(text=" Вы можете войти в систему ")
    text_enter_login = Label(text="Введите ваш логин :")

    enter_login = Entry()
    text_enter_pass = Label(text="Введите ваш пароль:")
    enter_password = Entry(show="*")
    button_enter = Button(text="Войти", command=lambda: log_pass())
    text_log.pack()
    text_enter_login.pack()
    enter_login.pack()
    text_enter_pass.pack()
    enter_password.pack()
    button_enter.pack()

    def log_pass():
        f = open("login.txt" , "rb")
        a = pickle.load(f)
        f.close()
        if enter_login.get() in a:
            if enter_password.get() == a[enter_login.get()]:
                messagebox.showinfo("Привет, добро пожаловать!")
            else:
                messagebox.showerror("Ошибка", "Неверный логин или пароль")
        else:
            messagebox.showerror("Ошибка","Неверный логин или пароль")


registration()


root.mainloop()

users = {

        "Андрюшкевич Н.Д": {
            "История культуры Беларуси": "Срок возварата неделя",
            "Начальный курс по математике": "Срок вовзврата 3 дня",
            "Первая мировая война":"Срок возврата 3 дня"

        },
        "Зиканов А.Е": {
            "Пайтон с 0":"Срок возврата 2 недели",
            "Основы кулинарии":"Срок возврата 4 дня",

        },
        "Олешко И.В": {
            "Бог как илюзия":"Срок возварата 2 месяца",
            "Вторая мировая война как феномен":"Срок возварата 1 месяц",
        },
        "Можиловская Д.С.": {
            "Вебдизайн":"Срок возврата 2 месца",
        },
        "Ковалев В.И.": {
            "Комиксы Last of as":"Срок возврата 3 дня",
            "Уроки пения":"Срок возврата 1 месяц",
            "Уроки кулинарии":"Срок возврата 2 недели",
        }

}



# вывод всего словаря
def show():
    for key, value in users.items():



        print("{0}: {1}".format(key, value))




# вывод всех ключей
def show_keys():
    for key, value in users.items():
        print(key)





# получение значений по ключу
def get_value():
    print('Введите имя читателя в билиотеке!')


    key = input(str())

    print(users.get(key))
# Добавление
def dobavit():
    print("Добавить ученика")
    rt = input(str(""))
    print('Что в нее вписать')
    dobav_value=input(str())
    users.setdefault(rt,dobav_value)
    messagebox.showinfo("Успешно добавили")

# Удалени
def udalit():
    print("Выберите ученика")
    udal_stud = input(str())
    del users[udal_stud]
    messagebox.showinfo("Успешно удалили")
#выход из программы
def exit():
    sys.exit("выход из программы")

root = Tk()
root.title("GUI на Python")
root.geometry("400x350")

main_menu = Menu()

file_menu = Menu(font=("Verdana", 13, "bold"), tearoff=0)
file_menu.add_command(label="Журнал имен",command=show_keys)
file_menu.add_command(label="Жрнал книг",command=show)
file_menu.add_command(label="Начать",command=get_value)
file_menu.add_separator()
file_menu.add_command(label="Выход",command=exit)

main_menu.add_cascade(label="Журнал", menu=file_menu)
main_menu.add_cascade(label="Добавить читателя", command=dobavit)
main_menu.add_cascade(label="Удалить читателя",command=udalit)

root.config(menu=main_menu)
root.mainloop()
