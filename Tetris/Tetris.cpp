
#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
using namespace sf;
const int M = 25;
const int N = 10; //17
int field[M][N] = { 0 };

struct Point
{
	int x, y;
}a[4], b[4];
int figures[7][4] =
{
	1,3,5,7, //I
	2,4,5,7, //Z
	3,5,4,6, //S
	3,5,4,7, //T
	2,3,5,7, //L
	3,5,7,6, //J
	2,3,4,5, //O

};

bool check()
{
	for (int i = 0; i < 4; i++)
	
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;
	
		return 1;
	
};
int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(320, 480), "The Tetris GameNrt");

	Texture t;
	t.loadFromFile("images/Tetris.png");
	Texture Back;
	Back.loadFromFile("images/BackGround.png");
	Sprite back(Back);
	
	Sprite s(t);
	s.setTextureRect(IntRect(0, 0, 18, 18));

	sf::Font font;
	font.loadFromFile("Fonts/Fonts.TTF");

	


	int dx = 0; bool rotate = 0; int colorNum = 1; int score = 0;

	sf::Text ScoreHead;
	ScoreHead.setFont(font);
	ScoreHead.setCharacterSize(24);
	
	ScoreHead.setFillColor(sf::Color::Black);
	ScoreHead.setOutlineColor(sf::Color::Black);
	ScoreHead.setPosition(200, 400);

	float timer = 0, delay = 0.2;

	Clock clock;

	// Главный цикл приложения
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		// Обрабатываем события в цикле
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Кроме обычного способа наше окно будет закрываться по нажатию на Escape
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up) rotate = true;
				else if (event.key.code == Keyboard::Left) dx = -1;
				else if (event.key.code == Keyboard::Right) dx = 1;
				
			
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
		//// Move //
		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
		if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
		//Rotate //
		if (rotate)
		{
			Point p = a[1];		// Center of rotation
			for (int i = 0; i < 4; i++)
			{
				int x = a[i].y - p.y;
				int y = a[i].x - p.x;
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
			if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
		}

		//Tick //
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
			if (!check())
			{
				for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

				colorNum = 1 + rand() % 7;
				int n = rand() % 7;
				for (int i = 0; i < 4; i++)
				{
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
					
				}
				
			}
			timer = 0;
		}

		//check lines//
		int k = M - 1;
		for (int i = M - 1; i > 0; i--)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) count++; 
				field[k][j] = field[i][j];
				
			}
			if (count < N)	k--;  
			else score++;
		}
		
		

		dx = 0; rotate = 0; delay = 0.3;
		
		// Draw //
		window.clear(Color::Black);
		window.draw(back);
		for ( int i= 0; i<M; i++)
			for (int j = 0; j < N; j++)
			{
				if (field[i][j] == 0) continue;
				s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
				s.setPosition(j * 18, i * 18);
				window.draw(s);
			}

		for (int i = 0; i < 4; i++)
		{
			s.setTextureRect(IntRect(colorNum*18, 0, 18, 18));
			s.setPosition(a[i].x * 18, a[i].y * 18);
			
			window.draw(s);
		}
		std::ostringstream Score;
		Score << score;
		ScoreHead.setString("Score:\n " + Score.str());
		window.draw(ScoreHead);
		// Тут будут вызываться функции обновления и отрисовки объектов
		// Отрисовка



		// Game Over
		
			if (field[1][N])
			{
				window.clear(Color::White);
				ScoreHead.setFillColor(Color::Red);
				ScoreHead.setString("Game Over\n You Score:\n"+Score.str());
				window.draw(ScoreHead);


			}
		window.display();
	}

	return 0;
}