// Бд труб.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <list>
#include <fstream>

/* Разработать структуру базы данных с минимальным количеством таблиц, достаточных
для хранения указанных данных. Также необходимо, чтобы при увеличении количества
реквизитов не пришлось бы менять структуру базы данных, данные изменения учитывались бы
простым добавлением новых записей в существующие таблицы.


Т.к структура бд подразумевает только хранение и добвление, буду хранить это в файле. Идея в том, чтобы загрузить в программу
(решение не работает с большими файлами, нужно использовать другоой алоритм).

*/

using namespace std;


class BD
{
private: 
	string Path = "data/Bd.txt"; //Путь к файлу
	int id;						//id строки для удобства удаления 
	list<string> cont;			//Контейнер	
	
public:
	BD() { Show(); Menu(); }		

	
	
	void Show()				//Отображение содержимого файла
	{
		id = 1;
		cont.clear();
		string temp;
		try{
			ifstream fin;
			fin.open(Path);
			if (!fin.is_open()) throw 1;
			

			else {
				cout << " №     Вид       Имя   t  Год пр-ва\n";
				while (!fin.eof())
				{


					getline(fin, temp);
					
					cout << " " <<id << "  " << temp<<endl  ;
					cont.push_back(temp);
					id++;
				}

			}
			id--;
			
			fin.close();
		}
		catch (int s)
		{
			if (s == 1)
				cout << "Ошибка чтения из файла";
		}
	}
	void Menu()				//Интуитивно понятный интерфейс работы с пользователем
	{
		int menu = 0;
		bool end = false;
		while (!end)
		{
			menu = 0;
			cout << "\n\n\n1. Добавить информацию о трубах \n2. Удалить информацию\n 3. Выход\n ";
			while (menu < 1 || menu >3)
			{
				cin >> menu;
				if (menu < 1 || menu >3)
					cout << "Ошибка меню, повторите запрос\n";
			}
			switch (menu)
			{
			case 1:
				Add();
				break;
			case 2:
				Remove();
				
				break;

			case 3: 
				end = true;
				break;
			}
			
		}
	}
	void Add()							//формирование информации
	{
		setlocale(LC_ALL, "ru");
		string tempcont ;
		string temp;

			cout << "Введите Вид Оборудования:\n";
			cin >> temp;
			int i = temp.length();
			for (int i = temp.length(); i < 13;i++)
				temp += " ";
			
			tempcont += temp;
			cout << "Введите Наименование\n";
			cin >> temp;
			i = temp.length();
			for (int i = temp.length(); i < 6; i++)
				temp += " ";
			tempcont += temp;
			cout << "Введите рабочую температуру:\n";
			cin >> temp;
			i = temp.length();
			for (int i = temp.length(); i < 5; i++)
				temp += " ";
			tempcont += temp;
			cout << "Введите год производства:\n";
			cin >> temp;
			i = temp.length();
			tempcont += temp;
			id++;
			
			cont.push_back(tempcont);
			WriteFile();
			
			
	}
	void WriteFile()			//Запись в файл(Стираем старые данные и пишем новые)
	{
		
		int tempid = 1;
		try {
			ofstream fout;
			fout.open(Path, std::ios::trunc);
			if (!fout.is_open()) throw 1;
			else
			{
				
				for (auto it : cont)
				{
					if (tempid != id)
						fout << it << endl;
					else
						fout << it;
					tempid++;
				}
					
			}

			fout.close();
			
			cout << "Ok\n\n\n";
			Show();
		}
		catch (int num)
		{
			if (num == 1)
				cout << "Ошибка открытия файла для записи";

		}
	}
	void Remove()			//Удаление какой-либо строки из файла
	{
		int tempid = NULL;
		int temp = 1;
	
			cout << "Введите id удаления изделия:\n";
			
			while (tempid > id || tempid ==NULL)								//Ошибка id
			{
				
				if (tempid > id || tempid < 0) { cout << "Ошибка id, повторите попытку\n"; tempid = NULL; }
				else
				cin >> tempid;
				

			}
			
			
				auto it = cont.begin();
				while (temp < tempid)
				{
					it++;
					temp++;
				}
				cont.erase(it);
				id--;
			WriteFile();
			Menu();
			
			
		
	
		
	};
		
};
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	BD start;
	

	
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
