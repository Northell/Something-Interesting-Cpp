#pragma once
class Custom
{
private:

	int _color = 5;
	
	/*
	Red = 0,
	Yellow = 1,
	Blue = 2,
	Cyan = 3,
	Green = 4,
	Magenta = 5
	*/
	

	unsigned int _particles = 40;
	int _speed = 10;
	int _saluteNum = 1;
	


public:
	Custom();
	~Custom();
	
	void setColor(int col);
	void setPartucles(int particles);
	void setSpeed(int speed);
	
	void setSaluteNum(int value);						//Количество салютов

	int getColor();
	
	int getParticles();
	int getSpeed();
	

	const Custom operator = (Custom& cust);

};

