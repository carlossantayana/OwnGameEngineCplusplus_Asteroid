#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <GL/glut.h>
#include "Solid.h"
class Cylinder : public Solid
{
private: //Atributos de la clase Cylinder

	float radiusB;
	float radiusT;
	float hight;
	int slices;
	int slacks;

public:
	Cylinder(Vector3D posArgument, Color colorArgument, Vector3D orientationArgument, Vector3D orientationSpeedArgument, Vector3D speedArgument, float radiusB, float radiusT, float hight, int slices, int slacks) : //Constructor
		Solid(posArgument, colorArgument, orientationArgument, orientationSpeedArgument, speedArgument),
		radiusB(radiusB),
		radiusT(radiusT),
		hight(hight),
		slices(slices),
		slacks(slacks)
	{}

	Cylinder(float radiusB = 0.0f, float radiusT = 0.0f, float hight = 0.0f, int slices = 0, int slacks = 0) : //Constructor alternativo en el que únicamente se le pasan los valores correspondientes al tamaño de la esfera, estos a su vez se pueden omitir, contando entonces con un constructor por defecto
		Solid(),
		radiusB(radiusB),
		radiusT(radiusT),
		hight(hight),
		slices(slices),
		slacks(slacks)
	{}

	//Getters
	inline float GetRadiusB() const { return this->radiusB; }
	inline float GetRadiusT() const { return this->radiusT; }
	inline float GetHight() const { return this->hight; }
	inline int GetSlices() const { return this->slices; }
	inline int GetSlacks() const { return this->slacks; }

	//Setters
	inline void SetRadiusB(const float& radiusToSet) { this->radiusB = radiusToSet; }
	inline void SetRadiusT(const float& radiusToSet) { this->radiusT = radiusToSet; }
	inline void SetHight(const float& hightToSet) { this->hight = hightToSet; }
	inline void SetSlices(const int& slicesToSet) { this->slices = slicesToSet; }
	inline void SetSlacks(const int& slacksToSet) { this->slacks = slacksToSet; }

	//Metodos
	void Render();
};

