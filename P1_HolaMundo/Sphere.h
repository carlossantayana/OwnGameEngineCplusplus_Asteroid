#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"

class Sphere
{
private:
	Vector3D pos;

	Color color;

	Vector3D orientation;

	float radius;
	int slices;
	int slacks;
public:
	Sphere(float x, float y, float z, float red, float green, float blue, float rx, float ry, float rz, float radius, float slices, float slacks) : //Constructor
		pos (Vector3D(x, y, z)),
		color (Color(red, green, blue)),
		orientation (Vector3D(rx, ry, rz)),
		radius(radius),
		slices(slices),
		slacks(slacks)
		{}

	Sphere(float radius = 0.0f, float slices = 0.0f, float slacks = 0.0f) : //Constructor alternativo en el que únicamente se le pasan los valores correspondientes al tamaño de la esfera, estos a su vez se pueden omitir, contando entonces con un constructor por defecto
		pos (Vector3D()),
		color (Color()),
		orientation (Vector3D()),
		radius (radius),
		slices (slices),
		slacks (slacks)
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
	inline float GetRadius() const {
		return this->radius;
	}
	inline float GetSlices() const {
		return this->slices;
	}
	inline float GetSlacks() const {
		return this->slacks;
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
	inline void SetRadius(const float& radiusToSet) {
		this->radius = radiusToSet;
	}
	inline void SetSlices(const float& slicesToSet) {
		this->slices = slicesToSet;
	}
	inline void SetSlacks(const float& slacksToSet) {
		this->slacks = slacksToSet;
	}

	void Render();
};

