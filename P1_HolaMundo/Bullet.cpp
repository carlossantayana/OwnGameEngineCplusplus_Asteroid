#include "Bullet.h"

//Se añade a la actualización normal de cualquier esfera el incremento del tiempo que lleva existiendo, para posteriormente eliminar la bala.
void Bullet::Update(const float& time)
{
	Sphere::Update(time);
	tiempoVida += time;
}

//Método que comprueba si la bala lleva más de 500 unidades de tiempo existiendo.
bool Bullet::EstaEliminado()
{
	return tiempoVida > 500;
}

//Método que obliga a que supere el límite de tiempo impuesto para que siga existiendo la bala.
void Bullet::Destruir()
{
	tiempoVida = 501;
}