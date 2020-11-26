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
	float _alpha;									//���� �� ��������� � ���������
	
		
	Particle *particles;						//������� ������� ��� �������� � ������������ �� �������?
	
	
public:
	Salute(Custom &cust);
	~Salute();

	void drawSalute(RenderWindow &window);


	void setPosition( Vector2f pos);
	void setPosition(int x, int y);

	void setColorSalute(Particle particle, int &col);		//��������� ����� �������
	void setIntensity(float value);		//��������� ������������� ������
	

	void setParticles(int value);		//��������� ���������� ���������
	

	
	
	
	
	void Dt(RenderWindow &window, float time, Text FPS, Sprite &button);							//������ ��������� �� �������

	Vector2f getPosition();
	int getIntensity();
	int getRotation();

	
	
};

