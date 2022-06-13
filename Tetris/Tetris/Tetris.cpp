#include "Tetris.h"
#include "Point.h"
using namespace sf;

bool Tetris::IsAbilityToMoveShape()
{
	bool result = true;

	for (int i = 0; i < 4; i++)
	{
		//≈сли фигура по иксу меньше 0 или больше по ширине размера игровой области или по игреку больше высоты
		// »Ћ» поле проинициализировано одним нулем, возвращаем false
		if ((a[i].x < 0)
			|| (a[i].x >= sizeWidthField)
			|| (a[i].y >= sizeHeightField)
			|| (FieldWorking[a[i].y][a[i].x]))
		{
			result = false;
			break;
		}
	}

	return result;
}

void Tetris::PollEvent()
{
	sf::Event event;

	while (_mainWnd->pollEvent(event))
	{
		//  роме обычного способа окно будет закрыватьс€ по нажатию на Escape
		if ((event.type == sf::Event::Closed)
			|| ((event.type == sf::Event::KeyPressed)
				&& event.key.code == sf::Keyboard::Escape))
		{
			_mainWnd->close();
		}

		if (Event::KeyPressed == event.type)
		{
			if (Keyboard::Up == event.key.code)
			{
				_isRotate = true;
			}
			else if (Keyboard::Left == event.key.code)
			{
				_dx = -1;
			}
			else if (Keyboard::Right == event.key.code)
			{
				_dx = 1;
			}
			else if (Keyboard::Down == event.key.code)
			{
				_delay = 0.05;
			}
		}
	}
}

void Tetris::RotateShape()
{
	if (_isRotate)
	{
		Point p = a[1];		// Center of rotation

		for (int i = 0; i < 4; i++)
		{
			int x = a[i].y - p.y;
			int y = a[i].x - p.x;
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}

		//≈сли фигуру нельз€ переместить, оставл€ем ее на месте
		if (!IsAbilityToMoveShape())
		{
			for (int i = 0; i < 4; i++)
			{
				a[i] = b[i];
			}
		}
	}
}

void Tetris::MoveShape()
{
	//// Move //
	for (int i = 0; i < 4; i++)
	{
		b[i] = a[i];
		a[i].x += _dx;
	}

	if (!IsAbilityToMoveShape())
	{
		for (int i = 0; i < 4; i++)
		{
			a[i] = b[i];
		}
	}
}

void Tetris::UpdateLines()
{
	//check lines//
	int k = sizeHeightField - 1;

	for (int i = sizeHeightField - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < sizeWidthField; j++)
		{
			if (FieldWorking[i][j])
			{
				count++;
			}

			FieldWorking[k][j] = FieldWorking[i][j];
		}

		if (count < sizeWidthField)
		{
			k--;
		}
		else
		{
			_score++;
		}
	}
}

bool Tetris::IsCreateShape()
{
	bool result = false;

	//Tick //
	if (_timer > _delay)
	{
		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
		if (!IsAbilityToMoveShape())
		{
			for (int i = 0; i < 4; i++)
			{
				FieldWorking[b[i].y][b[i].x] = _colorNewFigure;
			}

			result = true;
		}
		_timer = 0;
	}

	return result;
}

void Tetris::CreateShape()
{
	int newTypeFigure = rand() % 7;
	_colorNewFigure = 1 + rand() % 7;

	for (int i = 0; i < 4; i++)
	{
		a[i].x = arrAllTypesFigure[newTypeFigure][i] % 2;
		a[i].y = arrAllTypesFigure[newTypeFigure][i] / 2;
	}
}

void Tetris::Draw()
{
	std::ostringstream Score;

	if (FieldWorking[1][sizeWidthField])
	{
		DrawGameOverScreen(Score);
	}
	else
	{
		// Draw //
		_mainWnd->clear(Color::Black);
		_mainWnd->draw(_backgroundSprite);

		for (int i = 0; i < sizeHeightField; i++)
		{
			for (int j = 0; j < sizeWidthField; j++)
			{
				if (FieldWorking[i][j] != 0)
				{
					_shapeSprite.setTextureRect(IntRect(FieldWorking[i][j] * 18, 0, 18, 18));
					_shapeSprite.setPosition(j * 18, i * 18);
					_mainWnd->draw(_shapeSprite);
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			_shapeSprite.setTextureRect(IntRect(_colorNewFigure * 18, 0, 18, 18));
			_shapeSprite.setPosition(a[i].x * 18, a[i].y * 18);

			_mainWnd->draw(_shapeSprite);
		}

		Score << _score;

		_scoreHead.setString("Score:\n " + Score.str());

		_mainWnd->draw(_scoreHead);
	}

}

void Tetris::DrawGameOverScreen(std::ostringstream& Score)
{
	// Game Over
	if (FieldWorking[1][sizeWidthField])
	{
		_mainWnd->clear(Color::White);
		_scoreHead.setFillColor(Color::Red);
		_scoreHead.setString("Game Over\n You Score:\n" + Score.str());
		_mainWnd->draw(_scoreHead);
	}
}

Tetris::Tetris()
{
	
}

Tetris::~Tetris()
{
	_mainWnd->close();
	/*if (_shapeTexture != nullptr) delete _shapeTexture;
	if (_backgroundTexture != nullptr) delete _backgroundTexture;
	if (_shapeSprite != nullptr) delete _shapeSprite;
	if (_backgroundSprite != nullptr) delete _backgroundSprite;
	if (_scoreHead != nullptr) delete _scoreHead;*/
	if (_mainWnd != nullptr) delete _mainWnd;
}

void Tetris::InitTetris()
{
	srand(time(0));

	_mainWnd = new RenderWindow(VideoMode(320, 480), "The Tetris GameNrt");

	//_shapeTexture = new sf::Texture();
	bool resShaoe = _shapeTexture.loadFromFile("Resources\\images\\Tetris.png");

	//_backgroundTexture = new sf::Texture();
	 bool resBack =_backgroundTexture.loadFromFile("Resources\\images\\BackGround.jpg");


	_shapeSprite = Sprite(_shapeTexture);
	_backgroundSprite = Sprite(_backgroundTexture);

	_shapeSprite.setTextureRect(IntRect(0, 0, 18, 18));


	bool resFont = _font.loadFromFile("Resources\\Fonts\\Fonts.TTF");

	//_scoreHead = new  sf::Text();
	_scoreHead.setFont(_font);
	_scoreHead.setCharacterSize(24);

	_scoreHead.setFillColor(sf::Color::Black);
	_scoreHead.setOutlineColor(sf::Color::Black);
	_scoreHead.setPosition(200, 400);
}

void Tetris::RunPolling()
{
	// √лавный цикл приложени€
	while (_mainWnd->isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();

		clock.restart();

		_timer += time;

		// ќбрабатываем событи€ в цикле
		PollEvent();

		MoveShape();
		RotateShape();

		if (IsCreateShape())
		{
			CreateShape();
		}

		UpdateLines();

		
		Draw();

		_mainWnd->display();

		_dx = 0; _isRotate = 0; _delay = 0.3;
	}
}
