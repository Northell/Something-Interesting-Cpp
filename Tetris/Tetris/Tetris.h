#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>


//������� �������� ����
#define sizeHeightField 25
#define sizeWidthField 10

class Tetris
{

private:
	
	float _timer = 0;			//����� �������
	float _delay = 0.2;		//����� �������� ������ 

	int _dx = 0;					//��������� ���������� �� x
	bool _isRotate = 0;		//������� ����������� �������� ������
	int _colorNewFigure = 1;		//���� ������
	int _score = 0;			//����� ����

private:

	sf::RenderWindow* _mainWnd = nullptr;

	sf::Texture _shapeTexture ;
	sf::Texture _backgroundTexture ;

	sf::Sprite _backgroundSprite ;
	sf::Sprite _shapeSprite ;
	sf::Font _font;

	sf::Text _scoreHead ;

	sf::Clock clock;

	//������� ���� 
	int FieldWorking[sizeHeightField][sizeWidthField] = { 0 };

	//����� ����� �� ����
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
	///		����� ��������� ����������� ����������� ������ �� ����. 
	/// </summary>
	/// <returns> true - ���� ������ ����� ����������� � �������� �����������, ����� false</returns>
	bool IsAbilityToMoveShape();

	/// <summary>
	///		����� ������������ ������� ������� ������ ����������
	/// </summary>
	/// <param name="event"> ������ �������</param>
	void PollEvent();

	/// <summary>
	///		����� ������������ ������, ���� ��� ��������� ������ _isRotate
	/// </summary>
	void RotateShape();

	/// <summary>
	///		����� ���������� ������ ����
	/// </summary>
	void MoveShape();

	/// <summary>
	///		����� ��������� ����� �� �������������. ���� ����� �� ��� �������� ���������, �� �� ���������.
	/// </summary>
	void UpdateLines();

	/// <summary>
	///		����� ��������� ������. ���� ��� �����, ������ true
	/// </summary>
	bool IsCreateShape();

	/// <summary>
	///		����� ������� ������ �� ����
	/// </summary>
	void CreateShape();

	/// <summary>
	///		����� ������������ ����
	/// </summary>
	void Draw();

	/// <summary>
	///		����� ������������� ����� ���������
	/// </summary>
	/// <param name="Score"></param>
	void DrawGameOverScreen(std::ostringstream &Score);

public:
	Tetris();
	~Tetris();

	/// <summary>
	///		�������������� ��� ���� ������
	/// </summary>
	void InitTetris();

	/// <summary>
	///		��������� ���� ��������� �������
	/// </summary>
	void RunPolling();


};