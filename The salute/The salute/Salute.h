#pragma once
#include "Particle.h"
#include "Lib.h"

using namespace std;
class Salute
{
	unsigned int _particles;
	float _gravity = 10;		
	int _rotation = 360;

	float _intensity = 5;
	 

	int _speed;
	float _alpha;									//угол по отношению к горизонту
	
		
	Particle *particles;						//Хранить списком все партиклы и обрабатывать по очереди?
	
	
public:
	Salute(Custom &cust);
	~Salute();

	void drawSalute(RenderWindow &window);


	void setPosition( Vector2f pos);
	void setPosition(int x, int y);

	void setColorSalute(Particle particle, int &col);		//Установка цвета салюлта
	void setIntensity(float value);		//установка интенсивности салюта
	

	void setParticles(int value);		//Установка количества партиклов
	

	
	
	
	
	void Dt(RenderWindow &window, float time, Text FPS, Sprite &button);							//Физика изменения во времени

	Vector2f getPosition();
	int getIntensity();
	int getRotation();

	
	
};

