#include "SFML.h"


using namespace sf;

SFML::SFML()
{
	_buttonYesNo.loadFromFile("Data/Images/ButtonYesNo.png");

	backGround.loadFromFile("Data/Images/BackGround.jpg");
	_backGround.setTexture(backGround);

	
	font.loadFromFile("Data/Fonts/Fonts.TTF");	

	yesButton.setTexture(_buttonYesNo);
	noButton.setTexture(_buttonYesNo);

	yesButton.setTextureRect(IntRect(0, 0, 60, 50));
	noButton.setTextureRect(IntRect(60, 0, 45, 50));


	menuNum = 0;



	Window();
}
SFML::~SFML()
{
}

void SFML::Window()
{
	
	RenderWindow window(VideoMode(MAXX, MAXY), "The Salute");
	window.setFramerateLimit(MAXFPS);

	Texture _buttonSettings;
	_buttonSettings.loadFromFile("Data/Images/Setting.png");

	Sprite buttonSettings(_buttonSettings);
	buttonSettings.setTextureRect(IntRect(0, 0, 27, 30));
	buttonSettings.setPosition(Vector2f(290, 450));
	//Время
	float timer = 0, delay = 2000.0f;
	


	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		
		//Время
		float time = 0.0001;			//Можно было использовать CLock, но чет не получилось, слишком большая скорость, как бы не менял значение


		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
			{
				Exit(window);
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				customWindow(window);
				
			}
			else if (Mouse::isButtonPressed(Mouse::Left))
			{
				//Салют
				Salute sSalute(Cust);
				sSalute.setPosition(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
				bool _checkClick = true;				//Проверяем нажатие кнопки
				if (IntRect(buttonSettings.getPosition().x, buttonSettings.getPosition().y, buttonSettings.getTextureRect().width, buttonSettings.getTextureRect().height).contains(Mouse::getPosition(window))) { customWindow(window); _checkClick = false; }	//нажатие кнопки да
				
				float _intens = sSalute.getIntensity();		
				float _timerForGravity = 0;
				
				while ((sSalute.getPosition().x < MAXX) && (sSalute.getPosition().x > 0) && (sSalute.getPosition().y < MAXY) && (sSalute.getPosition().y > 0)&&(_intens>0)&&(_checkClick))
				{
					_timerForGravity += 0.2;
					

					while (timer < delay)					//Временная задержка
						timer += time;
					
					if (_intens > 0)
					
					{

						window.draw(_backGround);
						sSalute.Dt(window, _timerForGravity, FPS(),buttonSettings);	//тут скосячил, надо было сделать метод возвращаемым что нибудь сюда, чтобы не передавать кучу аргументов
						sSalute.setIntensity(_intens);


						_intens -= 0.5;
					}
				
					timer = 0;

				}

				_checkClick = true;
			}

				

		}
		
		
		// Отрисовка окна	
		window.clear();
		window.draw(_backGround);
		window.draw(buttonSettings);
		window.draw(FPS());
		window.display();
		

	}
}

Text SFML::FPS()
{
	Text _FPS;
	_FPS.setFont(font);
	_FPS.setFillColor(Color::White);
	_FPS.setPosition(200,10);
	_FPS.setCharacterSize(12);

	ostringstream _fps;
	_fps << "fps:\t\t\t\t\t\t"<< MAXFPS << "\n" << "Вариант цвета:\t " <<Cust.getColor()  << "\nКол-во частиц:  \t"<<Cust.getParticles() <<"\nСкорость:\t\t\t\t"<< Cust.getSpeed();
	_FPS.setString(_fps.str());
	return _FPS;
	
}


void SFML::customWindow(RenderWindow &window)
	{
		
		Text Menu;
		Menu.setFont(font);
		Menu.setPosition(20, 20);
		Menu.setFillColor(Color::White);
		Menu.setOutlineColor(Color::White);
		Menu.setCharacterSize(24);

		Text Equals;
		Equals.setFont(font);
		Equals.setPosition(260, 20);
		Equals.setFillColor(Color::White);
		Equals.setOutlineColor(Color::White);
		Equals.setCharacterSize(24);


		//Настройки кнопок
		yesButton.setPosition(20, 380);			
		noButton.setPosition(250, 380);

		
		
		Texture _buttonUpDown;
		_buttonUpDown.loadFromFile("Data/Images/ButtonUpDown.png");

		//===========Color==========
		Sprite buttonUpColor(_buttonUpDown);
		buttonUpColor.setTextureRect(IntRect(0, 0, 7, 10));
		buttonUpColor.setPosition(300, 65);
		
		Sprite buttonDownColor(_buttonUpDown);
		buttonDownColor.setTextureRect(IntRect(0, 0, 7, 10));
		buttonDownColor.setOrigin(buttonDownColor.getPosition().x+8, buttonDownColor.getPosition().y-10.5);
		buttonDownColor.rotate(180);
		buttonDownColor.setPosition(300, 105);


		//========Particle========

		Sprite buttonUpParticles(_buttonUpDown);
		buttonUpParticles.setTextureRect(IntRect(0, 0, 7, 10));
		buttonUpParticles.setPosition(300, 110);

		Sprite buttonDownParticles(_buttonUpDown);
		buttonDownParticles.setTextureRect(IntRect(0, 0, 7, 10));
		buttonDownParticles.setOrigin(buttonDownParticles.getPosition().x + 8, buttonDownParticles.getPosition().y - 10.5);
		buttonDownParticles.rotate(180);
		buttonDownParticles.setPosition(300, 150);

		//============Speed=========
		
		Sprite buttonUpSpeed(_buttonUpDown);
		buttonUpSpeed.setTextureRect(IntRect(0, 0, 7, 10));
		buttonUpSpeed.setPosition(300, 155);

		Sprite buttonDownSpeed(_buttonUpDown);
		buttonDownSpeed.setTextureRect(IntRect(0, 0, 7, 10));
		buttonDownSpeed.setOrigin(buttonDownSpeed.getPosition().x + 8, buttonDownSpeed.getPosition().y - 10.5);
		buttonDownSpeed.rotate(180);
		buttonDownSpeed.setPosition(300, 195);

		//======================


		Custom custom;			//Сохраняем состояние на случай, ес пользователь отменит действие и решит не сохранять настройки
		custom = Cust;
	
		setIsMenu(true);
		setMenuNum(0);

		//Цикл окна
		while ((window.isOpen())&&(getIsmenu()))
		{
			
			//Обработчик событий
			
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					Exit(window);
				}
				if (Mouse::isButtonPressed(Mouse::Left))
				{

					if (IntRect(yesButton.getPosition().x, yesButton.getPosition().y, yesButton.getTextureRect().width, yesButton.getTextureRect().height).contains(Mouse::getPosition(window))) setMenuNum(1);		//нажатие кнопки да
					else if (IntRect(noButton.getPosition().x, noButton.getPosition().y, noButton.getTextureRect().width, noButton.getTextureRect().height).contains(Mouse::getPosition(window)))   setMenuNum(2);		//нет
					
					else if (IntRect(buttonUpColor.getPosition().x, buttonUpColor.getPosition().y, buttonUpColor.getTextureRect().width, buttonUpColor.getTextureRect().height).contains(Mouse::getPosition(window)))   setMenuNum(3);		//цвет вверх
					else if (IntRect(buttonDownColor.getPosition().x, buttonDownColor.getPosition().y - 21, buttonDownColor.getTextureRect().width, buttonDownColor.getTextureRect().height).contains(Mouse::getPosition(window)))  setMenuNum(4);		//цвет вниз

					else if (IntRect(buttonUpParticles.getPosition().x, buttonUpParticles.getPosition().y, buttonUpParticles.getTextureRect().width, buttonUpParticles.getTextureRect().height).contains(Mouse::getPosition(window)))   setMenuNum(5);		//партиклы вверх
					else if (IntRect(buttonDownParticles.getPosition().x, buttonDownParticles.getPosition().y - 21, buttonDownParticles.getTextureRect().width, buttonDownParticles.getTextureRect().height).contains(Mouse::getPosition(window)))  setMenuNum(6);		//партиклы вниз

					else if (IntRect(buttonUpSpeed.getPosition().x, buttonUpSpeed.getPosition().y, buttonUpSpeed.getTextureRect().width, buttonUpSpeed.getTextureRect().height).contains(Mouse::getPosition(window)))   	setMenuNum(7);		//партиклы вверх
					else if (IntRect(buttonDownSpeed.getPosition().x, buttonDownSpeed.getPosition().y - 21, buttonDownSpeed.getTextureRect().width, buttonDownSpeed.getTextureRect().height).contains(Mouse::getPosition(window)))  		setMenuNum(8);		//партиклы вниз



					if (getMenuNum() == 1) { Cust = custom; isMenu = false; }		//Кнопка сохранить
					else if (getMenuNum() == 2) { isMenu = false; }					//Кнопка не сохранять
					
					else if (getMenuNum() == 3)									   { custom.setColor(custom.getColor() + 1); }					//Вверх для цвета
					else if ((getMenuNum() == 4)&&(checkColor(custom.getColor()))) { custom.setColor(custom.getColor() - 1); }					//Вниз для цвета

					else if (getMenuNum() == 5) { custom.setPartucles(custom.getParticles() + 1); }												//Вверх партиклы
					else if ((getMenuNum() == 6)&&(checkValue(custom.getParticles()))) { custom.setPartucles(custom.getParticles() - 1); }		//Вниз партиклы

					else if (getMenuNum() == 7) { custom.setSpeed(custom.getSpeed() + 1); }														//Вверх скорость
					else if ((getMenuNum() == 8) && (checkValue(custom.getSpeed()))) { custom.setSpeed(custom.getSpeed() - 1); }				//Вниз скорость
						
					setMenuNum(0);
				}
			}

			
			//Формируем текстовое поле

			std::ostringstream _textMenu;
			_textMenu << "Меню настроек:\n\n"  << "Цвет:\n\n" << "Партиклы на салют:\n\n" << "Скорость  частиц: "<<"\n";
			Menu.setString(_textMenu.str());


			std::ostringstream _textEquals;
			_textEquals << "\n\n" << custom.getColor() << "\n\n" << custom.getParticles() << "\n\n" << custom.getSpeed() << "\n";
			Equals.setString(_textEquals.str());



			//========Рисуем окно==========
			window.clear(Color::Blue);
			window.draw(_backGround);
			

			//Меню
			window.draw(Menu);
			window.draw(Equals);


			//Кнопки
			window.draw(buttonUpColor);
			window.draw(buttonDownColor);
			window.draw(yesButton);
			window.draw(noButton);
			window.draw(buttonUpParticles);
			window.draw(buttonDownParticles);
			window.draw(buttonUpSpeed);
			window.draw(buttonDownSpeed);


			window.display();
		}
	}







void SFML::Exit(RenderWindow &generalWindow)
	{
		RenderWindow window(VideoMode(350, 120), "The Salute");  //окно для всякого дерьма
		Custom Cust;											 //класс с настройками


		//Настройки текста
		Font font;
		font.loadFromFile("Data/Fonts/Fonts.TTF");
		Text Menu;
		Menu.setFont(font);
		Menu.setPosition(40,20);
		Menu.setFillColor(Color::White);
		Menu.setOutlineColor(Color::White);
		Menu.setCharacterSize(18);
		
		Vector2f yesPos = yesButton.getPosition();
		Vector2f noPos = noButton.getPosition();

		yesButton.setPosition(20, 50);
		noButton.setPosition(290, 50);




		while (window.isOpen())
		{
			
			//Обработчик событий
			Event event;
			while (window.pollEvent(event))
			{

				if (event.type == Event::Closed)
				{
						window.close();
				}
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (IntRect(yesButton.getPosition().x, yesButton.getPosition().y, yesButton.getTextureRect().width, yesButton.getTextureRect().height).contains(Mouse::getPosition(window)))												//нажатие кнопки да
					{
						generalWindow.close(); 
						window.close();
					}
					if (IntRect(noButton.getPosition().x, noButton.getPosition().y, noButton.getTextureRect().width, noButton.getTextureRect().height).contains(Mouse::getPosition(window)))												    //нет
					{ 
						yesButton.setPosition(yesPos);
						noButton.setPosition(noPos);  
						window.close(); 
					}	

				}
				
			}

			//Формируем текстовое поле

			std::ostringstream text;
			text << "Вы действительно хотите выйти?";
			Menu.setString(text.str());


			//Формируем кнопки


			//Отрисовка окна
			window.clear(Color::Black);
			window.draw(Menu);
			window.draw(yesButton);
			window.draw(noButton);
			window.display();
		}

	}

void SFML::setIsMenu(bool value)
{
	isMenu = value;
}

void SFML::setMenuNum(int value)
{
	menuNum = value;
}

bool SFML::getIsmenu()
{
	return isMenu;
}

int SFML::getMenuNum()
{
	return menuNum;
}

bool SFML::checkColor(int value)
{
	if ((value - 1 > 0)&&(value+1<6))
		return true;
	else 
	return false;
}

bool SFML::checkValue(int value)
{
	if (value - 1 > 0)
		return true;
	else
		return false;
}






