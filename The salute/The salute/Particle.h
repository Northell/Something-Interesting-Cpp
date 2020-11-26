#pragma once
#include "Lib.h"
#include "Custom.h"


using namespace sf;
class Particle
{
private:
	CircleShape particle;
	int _rotation;

	
public:
	
	Particle();
	~Particle();
	

	


	void setColor(int value);
	void setRadiusParticle(float _rad);			//радиус партикла
	void setRotation(int rotation);
	void setPosParticle(const Vector2f &pos);
	
	Vector2f getPosParticle();
	float getRadParticle();
	int getRotation() const;

	void DrawParticle(RenderWindow &window);

	
	
	
	
};

