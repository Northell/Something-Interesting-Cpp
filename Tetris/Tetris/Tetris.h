#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>


//Размеры игрового поля
#define sizeHeightField 25
#define sizeWidthField 10

class Tetris
{

private:
	
	float _timer = 0;			//Время таймера
	float _delay = 0.2;		//Время задержки фигуры 

	int _dx = 0;					//Изменение координаты по x
	bool _isRotate = 0;		//Признак возможности поворота фигуры
	int _colorNewFigure = 1;		//Цвет фигуры
	int _score = 0;			//Общий счет

private:

	sf::RenderWindow* _mainWnd = nullptr;

	sf::Texture _shapeTexture ;
	sf::Texture _backgroundTexture ;

	sf::Sprite _backgroundSprite ;
	sf::Sprite _shapeSprite ;
	sf::Font _font;

	sf::Text _scoreHead ;

	sf::Clock clock;

	//Рабочее поле 
	int FieldWorking[sizeHeightField][sizeWidthField] = { 0 };

	//Набор фигур на поле
	int arrAllTypesFigure[7][4] =
	{
		1,3,5,7, //I
		2,4,5,7, //Z
		3,5,4,6, //S
		3,5,4,7, //T
		2,3,5,7, //L
		3,5,7,6, //J
		2,3,4,5, //O
	};


	/// <summary>
	///		Метод проверяет возможность перемещения фигуры по полю. 
	/// </summary>
	/// <returns> true - если фигуру можно переместить к заданным координатам, иначе false</returns>
	bool IsAbilityToMoveShape();

	/// <summary>
	///		Метод обрабатывает события нажатия клавиш клавиатуры
	/// </summary>
	/// <param name="event"> Объект события</param>
	void PollEvent();

	/// <summary>
	///		Метод поворачивает фигуру, если это разрешено флагом _isRotate
	/// </summary>
	void RotateShape();

	/// <summary>
	///		Метод перемещает фигуру вниз
	/// </summary>
	void MoveShape();

	/// <summary>
	///		Метод проверяет линии на заполненность. Если какой то ряд заполнен полностью, то он удаляется.
	/// </summary>
	void UpdateLines();

	/// <summary>
	///		Метод проверяет таймер. Если тот истек, вернет true
	/// </summary>
	bool IsCreateShape();

	/// <summary>
	///		Метод создает фигуру на поле
	/// </summary>
	void CreateShape();

	/// <summary>
	///		Метод отрисовывает кадр
	/// </summary>
	void Draw();

	/// <summary>
	///		Метод отрисовыввает экран поражения
	/// </summary>
	/// <param name="Score"></param>
	void DrawGameOverScreen(std::ostringstream &Score);

public:
	Tetris();
	~Tetris();

	/// <summary>
	///		Инициализирует все поля класса
	/// </summary>
	void InitTetris();

	/// <summary>
	///		Запускает цикл обработки событий
	/// </summary>
	void RunPolling();


};