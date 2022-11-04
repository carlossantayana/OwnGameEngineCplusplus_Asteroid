/*#pragma once
#include<GL/glut.h>
#include"Solid.h"
class Prisma :public Solid
{
private:

	float longitud;
	float altura;
	float anchura;

public:
	Prisma(Vector3D pos, Color color, Vector3D rot, float longitud, float altura, float anchura) : //Constructor
		Solid(pos, rot, color),
		longitud(longitud),
		altura(altura),
		anchura(anchura)
	{}

	Prisma(float longitud=0, float altura = 0, float anchura = 0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		Solid(),
		longitud(longitud),
		altura(altura),
		anchura(anchura)
	{}

	inline float GetLongitude() const { return this->longitud; }
	inline float GetHigh() const { return this->altura; }
	inline float GetWidht() const { return this->anchura; }

	inline void SetLongitude(const float& longToSet) { this->longitud = longToSet; }
	inline void SetHigh(const float& highToSet) { this->altura = highToSet; }
	inline void SetWidht(const float& widhtToSet) { this->anchura = widhtToSet; }

	void Render();
};*/

