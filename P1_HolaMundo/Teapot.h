#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <GL/glut.h>
#include "Solid.h"

class Teapot : public Solid
{
private: //Atributos de la clase Teapot
	
	float size;

public:
	Teapot(Vector3D position, Color color,Vector3D orientation, Vector3D orientationSpeed,Vector3D speed, float sizeParameter) : //Constructor

		Solid(position, color, orientation, orientationSpeed, speed),
		size (sizeParameter)
	{}
	Teapot(float sizeParameter = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		
		Solid(),
		size (sizeParameter)
	{}

	//Getters
	inline float GetSize() const{ return this->size; }

	//Setters
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	//Metodos
	void Render();
	void Update();
};

