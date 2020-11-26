#include "Particle.h"





Particle::Particle()
{
	particle.setRadius(5);			//радиус партикла
	
}

Particle::~Particle()
{
	
}







void Particle::setColor(int value)
{
	switch (value)
	{
	case 1:
		particle.setFillColor(Color::Yellow);
		break;
	case 2:
		particle.setFillColor(Color::Blue);
		break;
	case 3:
		particle.setFillColor(Color::Cyan);
		
		break;
	case 4:
		particle.setFillColor(Color::Green);
		
		break;
	case 5:
		particle.setFillColor(Color::Magenta);
		
		break;
	case 6:
		particle.setFillColor(Color::Red);
		break;
	}
}

void Particle::setRadiusParticle(float _rad)
{
	particle.setRadius(_rad);
}

void Particle::setRotation(int rotation)
{
	_rotation = rotation;
	particle.setRotation(_rotation);
	
	
}

void Particle::setPosParticle(const Vector2f &pos)
{
	particle.setPosition(pos);
}

Vector2f Particle::getPosParticle()
{
	return particle.getPosition();
}

float Particle::getRadParticle()
{
	return particle.getRadius();
}

int Particle::getRotation() const
{
	return _rotation;
}

void Particle::DrawParticle(RenderWindow &window)
{
	window.draw(particle);
}






