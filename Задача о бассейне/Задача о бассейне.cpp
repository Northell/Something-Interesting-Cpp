// Задача о бассейне.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <map>
#include <string>
#include <fstream>



/*  1. Спроектировать базу данных, которая обеспечивала бы хранение всей
информации по процессу;
	
	2. Написать пример кода сохранения карточки клиента в базу. (Add)


*/	

using namespace std;

class BD
{
private:
	map<string, string> Cont;
	string Path = "data/Bd.txt"; //Путь к файлу


public:
	BD() { Start(); Menu(); }

	void Show()
	{
		auto itt = Cont.begin();
		itt++;
		for (itt; itt != Cont.end(); ++itt)
			
			cout << itt->first << " --> " << itt->second << endl;

	}
	void Menu() 
	{
		int menu = NULL;
		cout << "\n\n\n\n1. Поиск клиента по значению\n2. Добавить клиента\n3. Удалить клиента\n4. Выход\n\n\n";
		cin >> menu;
		while (!CheckInput(1, 4, menu))
			cin >> menu;
		switch (menu)
		{
		case 1:
			Find();
			break;
		case 2:
			Add();
			break;
		case 3: 
			Remove();
			break;
		case 4:
		break;
		}
	}
	void Start()
	{
		Cont.clear();
		string id;
		string temp;
		try {
			ifstream fin;
			fin.open(Path);
			if (!fin.is_open()) throw 1;


			else {
				
				while (!fin.eof())
				{


					getline(fin, temp);
					
					bool check = false;
					for (int i = 0; i< temp.length(); i++)
					{
						
						
						if (temp[i] != ','&& !check)
						{
							id += temp[i];
							temp.erase(0, 1);
							i--;
						}
						else
						{
							check = true;
							temp.erase(0, 1);
							break;
						}
						
						
					}
					
					Cont.emplace(id, temp);
					id = "";
					
				}

			}
		

			fin.close();


		}

		catch (int s)
		{
			if (s == 1)
				cout << "Ошибка чтения из файла";
		}
	}
	void Find()
	{
		string key = "";
		cout << "Введите id:\n";
		cin >> key;
		auto result =Cont.find(key);
		if (result != Cont.end())
		cout << result->first << " --> " << result->second;
		else 
		{
			cout << "Человек не найден\n ";
		}
		Menu();
	}
	bool CheckInput(int min, int max, int temp)
	{

		if ( temp > max || temp < min)
		{
			cout << "\n Ошибка ввода, повторите:\n";
			return false;

		}
		else 
		return true;
	}
	void Add()						//Добавление карточки в базу
	{
		int id = Cont.size()+1;
		string Id = to_string(id);

		bool check = 0;
		string temp = "";
		string result = "";
		cout << "Введите ФИО человека полностью: \n";
		
		cin.ignore(32767, '\n');
		getline(cin, temp);
		

		result = temp+ " ";
		cout << "Введите год рождения: \n";
		cin >> temp;
		result += temp + " ";
		cout << "Наличие справки медосмотра? (д/н)\n";
		cin >> temp;
		result += temp + " ";
		cout << "Вид абнемента: 1. Разовый\n2. На 4 занятия в месяц\n3. На 12 занятий в 3 месяца\n4. На 24 занятия в пол года\n ";
		cin >> temp;
		while (!CheckInput(1,4,stoi(temp)))
		cin >> temp;
		result += temp + " ";
		
		
			
		
		Cont.emplace(Id, result);
		cout << endl << "Ok \n\n ";
		Show();
		WriteFile();
		Menu();

		
	}
	void WriteFile()
	{

		try {
			ofstream fout;
			fout.open(Path, std::ios::trunc);
			if (!fout.is_open()) throw 1;
			else
			{
				for (auto it : Cont)
				{
					if (it.first != "" && it.second!= "")
					fout << it.first << "," << it.second << endl;
				}

			}

			fout.close();
		}
			catch (int num)
			{
				if (num == 1)
					cout << "Ошибка открытия файла для записи";

			}

	}
	void Remove()
	{
		int temp;
		Show();
		cout << "Введите номер записи для удаления:\n";
			cin >> temp;
		while (!CheckInput(1, Cont.size(), temp))
			cin >> temp;
		auto it = Cont.find(to_string(temp));
		if (it == Cont.end())
			cout << "Такого клиента не существует \n";
		else
		{
			Cont.erase(it);
			
		}

		WriteFile();
		Show();
		Menu();

	}				
};

int main()
{
	setlocale(LC_ALL, "rus");
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
