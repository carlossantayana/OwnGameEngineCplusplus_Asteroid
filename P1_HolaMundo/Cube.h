#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include"Solid.h"

class Cube :public Solid
{
private: //Atributos
	float size;
public:
	Cube(Vector3D pos, Color color, Vector3D rot, float sizeParameter) : //Constructor
		Solid(pos, rot, color),
		size(sizeParameter)
	{}
	Cube(float sizeParameter = 0) : //Constructor alternativo que solo recibe el tama�o y a su vez se puede omitir, contando entonces con un constructor por defecto
		Solid(),
		size (sizeParameter)
	{}

	//Getters
	inline float GetSize() const {
		return this->size;
	}

	//Setters
	inline void SetSize(const float& sizeToSet) {
		this->size = sizeToSet;
	}

	void Render();
};

