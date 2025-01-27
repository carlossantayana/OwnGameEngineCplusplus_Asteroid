#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:
	//Atributos de una esfera
	float radius;
	int slices;
	int slacks;

public:
	//Constructores de esferas
	Sphere(Vector3D posArgument, Color colorArgument, Vector3D orientationArgument, Vector3D orientationSpeedArgument, Vector3D speedArgument, float radius, float slices, float slacks) : //Constructor
		Solid(posArgument, colorArgument, orientationArgument, orientationSpeedArgument, speedArgument),
		radius(radius),
		slices(slices),
		slacks(slacks)
		{}

	Sphere(float radius = 0.0f, float slices = 0.0f, float slacks = 0.0f) : //Constructor alternativo en el que �nicamente se le pasan los valores correspondientes al tama�o de la esfera, estos a su vez se pueden omitir, contando entonces con un constructor por defecto
		Solid(),
		radius (radius),
		slices (slices),
		slacks (slacks)
		{}

	//Getters
	inline float GetRadius() const { return this->radius; }
	inline float GetSlices() const { return this->slices; }
	inline float GetSlacks() const { return this->slacks; }

	//Setters
	inline void SetRadius(const float& radiusToSet) { this->radius = radiusToSet; }
	inline void SetSlices(const float& slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(const float& slacksToSet) { this->slacks = slacksToSet; }

	//M�todo de renderizado de una esfera
	void Render();
};

