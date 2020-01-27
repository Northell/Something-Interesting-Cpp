// Сортировка больгих чисел(1).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <set>
#include <ctime>
#include<fstream>
 /* Задача: Напишите программу, которая отсортирует числа формата double
хранящихся в текстовом файле размером 1Гб (одно число в одной строке).  Программа должна использовать не более 100 мб оперативной памяти.
Обязательные параметры: <имя файла не отсортированного> <имя файла отсортированного>
Также должен быть написан генератор не отсортированного 1Гб файла с числами формата double*/

using namespace std;
class File {
private:
	multiset <double> FileCont;
	string ReadF = "FileStart.txt";
	string InpF = "FileFinish.txt";
	
	int mn = pow(10, 2);				//максимально возможное число

	
	const int MaxBuf = 1000000;
	const int MaxLength = pow(10, 7);
	const int MAX = 150;
public:
	

	void InputInTempFile(string FILENAME)
	{
		std::ofstream out;          // поток для записи
		out.open(FILENAME, ios_base::app); // окрываем файл для записи
		if (out.is_open())
		{
			out.precision(MAX);
			for (auto it = FileCont.begin(); it != FileCont.end(); it++) {
				out << *it << "\n";
			}
		}
		FileCont.clear();
		

		
	}


	void ReadFile(string FILENAME)
	{
		std::string line;
		double convert;
		

		int i2 = 0;
		int i1 = 0;
		int temp = 10;					//переменная для шага
		
		for (int i = 0; i < mn + 1; i=i+temp)
		{
			std::ifstream in(FILENAME); // окрываем файл для чтения
			while (getline(in, line))
			{
				convert = atof(line.c_str());
				if ((i <= convert) &&(convert< (i + temp)))
				{
					FileCont.insert(convert);
					i1++;
				}
				
				i2++;
				
			}

			in.close();		// закрываем файл
			InputInTempFile(InpF);

		}
		
	

		



	}
	
	bool Gen()
	{
		string FILENAME = "FileStart.txt";
		
	
		
		
		std::ofstream out;          // поток для записи
		out.open(FILENAME); // окрываем файл для записи
		if (out.is_open())
		{
			out.precision(150);
			for (int i = 0; i< MaxLength; i++)
				
			out << static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / mn)) << "\n"; //генерация случайных чисел
			
			out.close();

		}
		else return false;
		return true;
	}
};

int main()

{
	srand(static_cast <unsigned> (time(0)));
	File file;
	//cout << file.Gen();
	file.ReadFile("FileStart.txt");
	
	
	
	std::cout << "End of program" << std::endl;
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
