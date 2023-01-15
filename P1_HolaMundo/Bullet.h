#pragma once
#include "Sphere.h"
class Bullet : public Sphere
{
	float tiempoVida;
public:
	Bullet();

	void Update(const float& time);

	bool EstaEliminado();

	void Destruir();
};

