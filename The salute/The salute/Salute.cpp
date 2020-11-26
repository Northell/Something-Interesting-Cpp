#include "Salute.h"

Salute::Salute(Custom &cust)
{
	_speed = cust.getSpeed();								// cust.getSpeed();
	
	_particles = cust.getParticles();
	

	
	_rotation /= _particles;
	_alpha = _rotation;

	particles = new Particle[_particles];

	setIntensity(_intensity);
	for (int i = 0; i < _particles; i++)				
	{
		particles[i].setColor(cust.getColor());
		particles[i].setRotation(_rotation*i);
		
	}
}

Salute::~Salute()
{
		delete[] particles;
}

void Salute::drawSalute(RenderWindow & window)
{
	for (int i = 0; i < _particles; i++)
	particles[i].DrawParticle(window);

}

void Salute::setPosition(Vector2f pos)
{
	for (int i = 0; i < _particles; i++)
		particles[i].setPosParticle(pos);
}

void Salute::setPosition(int x, int y)
{
	for (int i=0; i<_particles; i++)
	particles[i].setPosParticle(Vector2f(x, y));
}


void Salute::setParticles(int value)
{
	_particles = value;
}

void Salute::setColorSalute(Particle particle, int &col)
{
	particle.setColor(col);
}

void Salute::setIntensity(float value)
{
	for(int i=0;i<_particles; ++i)
	particles[i].setRadiusParticle(value);
}







void Salute::Dt(RenderWindow &window,float time, Text FPS, Sprite &button)
{
	for (int i = 0; i < _particles; i++)
	{
		float x0 = (particles[i].getPosParticle().x);
		float y0 = (particles[i].getPosParticle().y);
		float x;
		float y;

		
		
		float _Vx = _speed * cos(_alpha);
		float _Vy = _speed * sin(_alpha + _gravity * time);

		if ((particles[i].getRotation() > 90) && (particles[i].getRotation() < 270)) { _Vx = -_Vx; } //0 градусов - вправо
		if ((particles[i].getRotation() > 360) || (particles[i].getRotation() < 180)) { _Vy = -_Vy; }

		drawSalute(window);
		
		y = y0 - (_Vy * sin(_alpha) - ((_gravity*pow(time, 4))/2) ); // у нас ж точка (0,0) вверху слева находится, поэтому меняем знак после y0, чтобы падало вниз
		x = x0 + (_Vx * time * cos(_alpha));
		_alpha = _Vx / _Vy;

		particles[i].setPosParticle(Vector2f(x, y));

	}
	window.draw(FPS);
	window.draw(button);
	window.display();
		
}



Vector2f Salute::getPosition()
{
	return particles[0].getPosParticle();
}

int Salute::getIntensity()
{
	return _intensity;
}

int Salute::getRotation()
{
	return _rotation;
}

