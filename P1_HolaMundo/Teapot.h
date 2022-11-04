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
	Teapot(Vector3D position, Color color,Vector3D orientation, float sizeParameter) : //Constructor

		Solid(position, orientation, color),
		size (sizeParameter)
	{}
	Teapot(float sizeParameter = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		
		Solid(),
		size (sizeParameter)
	{}

	//Getters
	inline float GetSize() const{
		return this->size;
	}

	//Setters
	inline void SetSize(const float& sizeToSet) {
		this->size = sizeToSet;
	}

	void Render();
};

