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
	Cube(Vector3D pos, Color color, Vector3D rot, Vector3D rotS, Vector3D speed, float sizeParameter) : //Constructor
		Solid(pos, color, rot, rotS, speed),
		size(sizeParameter)
	{}
	Cube(float sizeParameter = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
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

	//Metodos
	void Render();
	void Update();
};

