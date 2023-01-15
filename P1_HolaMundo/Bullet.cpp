#include "Bullet.h"

//Se a�ade a la actualizaci�n normal de cualquier esfera el incremento del tiempo que lleva existiendo, para posteriormente eliminar la bala.
void Bullet::Update(const float& time)
{
	Sphere::Update(time);
	tiempoVida += time;
}

//M�todo que comprueba si la bala lleva m�s de 500 unidades de tiempo existiendo.
bool Bullet::EstaEliminado()
{
	return tiempoVida > 500;
}

//M�todo que obliga a que supere el l�mite de tiempo impuesto para que siga existiendo la bala.
void Bullet::Destruir()
{
	tiempoVida = 501;
}