#pragma once
#include "Lib.h"
#include "Salute.h"


using namespace sf;
class SFML
{
private:
	const int MAXX = 320;
	const int MAXY = 480;
	const int MAXCOLOR = 5;				//Максимум 5 цветов
	const int MAXFPS = 60;

	bool isMenu;						//чек на меню
	int menuNum;						//нумерация для меню(вариативность)
	Custom Cust;						//настройки из меню настроек(чтобы пихать в салют)

	Texture _buttonYesNo;				//Соберем кнопку в конструкторе, т.к испльзуется более чем в 1 месте
	Sprite yesButton;
	Sprite noButton;

	Texture backGround;					
	Sprite _backGround;

	Font font;							//Настройки текстовой составляющей
	
	

public:
	SFML();
	~SFML();

	void Window();
	Text FPS();
	void customWindow(RenderWindow &window);
	void Exit(RenderWindow &generalWindow);


	void setIsMenu(bool value);				
	void setMenuNum(int value);				//нумерация для меню(вариативность)
	


	bool getIsmenu();
	int getMenuNum();

	bool checkColor(int value);
	bool checkValue(int value);				//проверка на 0

	

	

	


	
};

