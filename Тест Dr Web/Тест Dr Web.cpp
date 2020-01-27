// Тест Dr Web.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

template<class TKey, class TValue>
class Dictionary
{
public:
	virtual ~Dictionary() = default;

	virtual const TValue& Get(const TKey& key) const = 0;
	virtual void Set(const TKey& key, const TValue& value) = 0;
	virtual bool IsSet(const TKey& key) const = 0;
};

template<class TKey>
class NotFoundException : public std::exception
{
public:
	virtual const TKey& GetKey() const noexcept = 0;
};

template <class TKey>
class Exception : NotFoundException<TKey>
{
	TKey key;
	public:
		Exception(TKey key, string err) :key(key) { cout << "\nЧто-то пошло не так( " << err << "( " << GetKey() << ")" << ")\n"; exit(key); };
		~Exception() = default;
		const TKey& GetKey() const noexcept
	{		
		return key;
	}

};

template <class TKey, class TValue>

	class Abs : public Dictionary<TKey, TValue>
	{

	private:
		map <TKey, TValue> cont;
	public:
		
		const TValue &Get(const TKey &key) const
		{
			if (cont.find(key) == cont.end()) { IsSet(-1000); }
			else
				return cont.find(key)->second;
		}
		void Set(const TKey& key, const TValue &value) 
		{
			try
			{if (IsSet(key) == false)
				cont.insert(pair<TKey, TValue>(key, value));
			else throw key;
			}
			catch (const exception& ex)
			{
				Exception<TKey> Err(-1003, ex.what());
			}
			catch (...)
			{
				IsSet(key);
			}
		}
		bool IsSet(const TKey&key) const
		{
			const int Exc = -1000;
			if (key == Exc )
			{
				Exception<TKey> Err(key,"Ошибка, такого ключа не существует.");
				return 1;
			}
			else if ((key < 0) && (key > Exc))
			{
				Exception<TKey> Err(key,"Ошибка, добавления.");
				return 1;
			}
			
			
			else return 0;
		}
		
	};

	

int main()
{
	setlocale(LC_ALL, "rus");
	Abs<int, string> abb;

	abb.Set(5, "Pias");
	abb.Set(4, "Ex");

	cout << abb.Get(4) << endl;
	cout << abb.Get(5) << endl;
	
	abb.Set(-5, "tur");
	cout << abb.Get(-5);
	
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
