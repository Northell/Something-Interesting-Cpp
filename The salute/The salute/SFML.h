#pragma once
#include "Lib.h"
#include "Salute.h"


using namespace sf;
class SFML
{
private:
	const int MAXX = 320;
	const int MAXY = 480;
	const int MAXCOLOR = 5;				//�������� 5 ������
	const int MAXFPS = 60;

	bool isMenu;						//��� �� ����
	int menuNum;						//��������� ��� ����(�������������)
	Custom Cust;						//��������� �� ���� ��������(����� ������ � �����)

	Texture _buttonYesNo;				//������� ������ � ������������, �.� ����������� ����� ��� � 1 �����
	Sprite yesButton;
	Sprite noButton;

	Texture backGround;					
	Sprite _backGround;

	Font font;							//��������� ��������� ������������
	
	

public:
	SFML();
	~SFML();

	void Window();
	Text FPS();
	void customWindow(RenderWindow &window);
	void Exit(RenderWindow &generalWindow);


	void setIsMenu(bool value);				
	void setMenuNum(int value);				//��������� ��� ����(�������������)
	


	bool getIsmenu();
	int getMenuNum();

	bool checkColor(int value);
	bool checkValue(int value);				//�������� �� 0

	

	

	


	
};

