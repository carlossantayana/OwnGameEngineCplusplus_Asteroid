#pragma once
#include<GL/glut.h>
#include"Solid.h"
class Cuboid :public Solid
{
private:

	float lenght;
	float height;
	float width;

public:
	Cuboid(Vector3D pos, Color color, Vector3D rot, Vector3D rotS, Vector3D speed, float lenght, float height, float width) : //Constructor
		Solid(pos, color, rot, rotS, speed),
		lenght(lenght),
		height(height),
		width(width)
	{}

	Cuboid(float lenght=0, float height = 0, float width = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		Solid(),
		lenght(lenght),
		height(height),
		width(width)
	{}

	//Getters
	inline float GetLenght() const { return this->lenght; }
	inline float GetHight() const { return this->height; }
	inline float GetWidth() const { return this->width; }

	//Setters
	inline void SetLenght(const float& lenghtToSet) { this->lenght = lenghtToSet; }
	inline void SetHight(const float& hightToSet) { this->height = hightToSet; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	//Metodos
	void Render();
	void Update();
};

