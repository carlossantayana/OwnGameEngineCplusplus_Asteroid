#pragma once
#include<GL/glut.h>
#include"Solid.h"
class Prisma :public Solid
{
private:

	float longitud;
	float altura;
	float anchura;

public:
	Prisma() : Solid(Vector3D(0.0, 0.0, -2.0), Vector3D(0.0, 0.0, 0.0), Color()), longitud(0.4), altura(0.4), anchura(0.4) {}

	inline float GetLongitude() const { return this->longitud; }
	inline float GetHigh() const { return this->altura; }
	inline float GetWidht() const { return this->anchura; }

	inline void SetLongitude(const float& longToSet) { this->longitud = longToSet; }
	inline void SetHigh(const float& highToSet) { this->altura = highToSet; }
	inline void SetWidht(const float& widhtToSet) { this->anchura = widhtToSet; }

	void Render();
};

