#pragma once
#include "Solid.h"
class Camera : public Solid
{
public:
	//Constructor de la c�mara
	Camera(Vector3D positionArgument = Vector3D()) : Solid(positionArgument) {}

	//M�todo de renderizado de la c�mara
	void Render();
};

