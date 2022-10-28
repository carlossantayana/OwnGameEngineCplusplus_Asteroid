#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"

class Cube
{
private: //Atributos
	Vector3D pos;

	Color color;

	Vector3D orientation;

	float size;
public:
	Cube(float x, float y, float z, float red, float green, float blue, float rx, float ry, float rz, float sizeParameter) : //Constructor
		pos (Vector3D(x,y,z)),
		color (Color(red, green, blue)),
		orientation (Vector3D(rx, ry, rz)),
		size (sizeParameter)
	{}
	Cube(float sizeParameter = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		pos (Vector3D()),
		color (Color()),
		orientation (Vector3D()),
		size (sizeParameter)
	{}

	//Getters

	inline Vector3D GetPos() const {
		return this->pos;
	}
	inline Color GetColor() const {
		return this->color;
	}
	inline Vector3D GetOrientation() const {
		return this->orientation;
	}
	inline float GetSize() const {
		return this->size;
	}

	//Setters

	inline void SetPos(Vector3D newPos) {
		this->pos = newPos;
	}
	inline void SetColor(Color newColor) {
		this->color = newColor;
	}
	inline void SetOrientation(Vector3D newOrientation) {
		this->orientation = newOrientation;
	}
	inline void SetSize(const float& sizeToSet) {
		this->size = sizeToSet;
	}

	void Render();
};

