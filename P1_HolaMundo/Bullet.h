#pragma once
#include "Sphere.h"

class Bullet : public Sphere
{
private:
	//ATRIBUTO DE LA CLASE BULLET
	float tiempoVida; //Permite eliminar las balas transcurrido un periodo de tiempo

public:
	//CONSTRUCTOR DE LAS BALAS
	Bullet() : tiempoVida(0) {
		SetColor(Color(255.0, 255.0, 255.0));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
		SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
		SetRadius(0.05);
		SetSlacks(12.0);
		SetSlices(12.0);
		SetSpeed(Vector3D(0.0, 0.0, 0.0));
	}

	//CONTROL ACTUALIZACIÓN
	void Update(const float& time);

	//CONTROL ESTADO DE LA BALA
	bool EstaEliminado();
	void Destruir();
};