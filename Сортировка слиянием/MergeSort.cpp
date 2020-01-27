// Тест на работу.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Сортировка слиянием

#include "pch.h"
#include <iostream>

int round_half_down(int p, int r)
{
	return ((p + r) / 2);
}

void Show(int *A, int MaxLength)
{
	for (int i = 0; i < MaxLength; i++)
		std::cout << A[i]<< " ";
}


void Merge(int *A, int first, int split, int last)
{
	
	
	int pos1 = first;	//первая позиция
	int pos2 = split +1;//2
	int pos3 = 0;//3
	int *temp = new int[last - first + 1];//буфер

	while (pos1 <= split && pos2 <= last) 
	{
		if (A[pos1] < A[pos2])
			temp[pos3++] = A[pos1++];
		else
			temp[pos3++] = A[pos2++];
	}
	while (pos2 <= last)   // пока вторая последовательность непуста 
		temp[pos3++] = A[pos2++];
	while (pos1 <= split)  // пока первая последовательность непуста
		temp[pos3++] = A[pos1++];

	
	for (pos3 = 0; pos3 < last - first + 1; pos3++)	//копирование буфера
		A[first + pos3] = temp[pos3];

	delete temp;
	
}


int Sort(int A[], int p, int MaxLength)
{
	
	if (p < MaxLength)
	{
		int split = round_half_down(p, MaxLength);

		Sort(A, p, split);	//левая часть
		Sort(A, split + 1, MaxLength);// правая часть 
		Merge(A, p, split, MaxLength); //слияние
	}
	
	return *A;
}

int main()
{ 
	const int MaxLength = 20;
	int A[MaxLength+1];
	for (int i = 0; i < MaxLength+1; ++i) A[i] = 0;	//Обнуление

	for (int i = 0; i < MaxLength; i++)
		A[i] = rand()%10;
	
	 A[0] = Sort(A, 0, MaxLength);
	 Show(A, MaxLength);
	 
	 return 0;

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
