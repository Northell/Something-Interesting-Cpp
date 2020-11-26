#include "Custom.h"



Custom::Custom()
{
}



void Custom::setColor(int col)
{
	_color = col;
}

void Custom::setPartucles(int particles)
{
	

	_particles = particles;
	
	
}


void Custom::setSpeed(int speed)
{
	_speed = speed;
}

void Custom::setSaluteNum(int value)
{
	_saluteNum = value;
}

int Custom::getColor()
{
	return _color;
}




int Custom::getParticles()
{
	return _particles;
}

int Custom::getSpeed()
{
	return _speed;
}



const Custom Custom::operator=( Custom & cust) 
{
	this->setColor(cust.getColor());
	this->setPartucles(cust.getParticles());
	this->setSpeed(cust.getSpeed());


	return *this;
}

Custom::~Custom()
{
}
