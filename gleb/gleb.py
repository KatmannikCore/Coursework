import pickle
from datetime import date
counter = 1
FILENAME = "users.dat" 
product = { 
"1":[
	("Наименование:","Кирпич"),
	("Колличество:" ,100), 
	( "Цена:", 20), 
	("Датa:", date.today()), 
	("Имя:","Иван"), 
	("Фамилия:","Иванов"), 
	("Отчество:","Иванович")],
"2":
	[("Наименование:", "Алмаз"),
     ("Колличество:" ,100),
  	 ( "Цена:", 20),
  	 ("Датa:", date.today()), 
  	 ("Имя:","Иван"),
  	 ("Фамилия:","Иванов"), 
  	 ("Отчество:","Иванович")]
} 
def Save(): 
	with open(FILENAME, "wb") as file: 
		pickle.dump(product, file) 
with open(FILENAME, "rb") as file:
	product = pickle.load(file) 
for key in product.keys(): 
	counter += 1 
while bool: 
	print("Выберите операцию", "1 - Простомтеть склад", "2 - Ввести товар на слад ", "3 - Изменение", sep='\n')
	value = input() 
	if value == '1': 
		for key in product: 
			print(key, " - ", product[key][0][0], product[key][0][1],
							  product[key][1][0], product[key][1][1],
							  product[key][2][0], product[key][2][1],
							  product[key][3][0], product[key][3][1],
							  product[key][4][0], product[key][4][1], 
							  product[key][5][0], product[key][5][1],
							  product[key][6][0], product[key][6][1], ) 
	if value == '2': 
		PPP2 = {
			 counter: [
		   		("Наименование:", input("Наименование товара: ")),
		   		("Колличество:", input("Колличество: ")),
		   		("Цена:", input("Цена: ")),
		  		("Датa:", date.today()),
				("Имя:", input("Имя: ")),
		   		("Фамилия:", input("Фамилия: ")),
		   		("Отчество:", input("Отчество: ")),]
		}
		product.update(PPP2)
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
		PPP = {
			 Number: [
		 		("Наименование:", input("Наименование товара: ")),
	     		("Колличество:", input("Колличество: ")),
	     		("Цена:", input("Цена: ")),
	     		("Датa:", date.today()),
	     		("Имя:", input("Имя: ")),
	     		("Фамилия:", input("Фамилия: ")),
	     		("Отчество:", input("Отчество: ")), ]
	     } 
		product.update(PPP)
		Save()


















