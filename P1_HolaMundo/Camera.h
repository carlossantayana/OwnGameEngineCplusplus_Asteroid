#pragma once
#include "Solid.h"
class Camera : public Solid
{
public:
	//Constructor de la cámara
	Camera(Vector3D positionArgument = Vector3D()) : Solid(positionArgument) {}

	//Método de renderizado de la cámara
	void Render();
};

