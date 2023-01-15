#include "Bullet.h"

Bullet::Bullet() : tiempoVida(0)
{
	SetColor(Color(255.0, 255.0, 255.0));
	SetOrientation(Vector3D(0.0, 0.0, 0.0));
	SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	SetRadius(0.05);
	SetSlacks(12.0);
	SetSlices(12.0);
	SetSpeed(Vector3D(0.0, 0.0, 0.0));
}

void Bullet::Update(const float& time)
{
	Sphere::Update(time);
	tiempoVida += time;
}

bool Bullet::EstaEliminado()
{
	return tiempoVida > 500;
}

void Bullet::Destruir()
{
	tiempoVida = 501;
}
