#pragma once
#include<GL/glut.h>
#include"Solid.h"
class Torus :public Solid
{
private:

	float radiusI;
	float radiusE;
	int faces;
	int rings;

public:
	//Torus() : Solid(Vector3D(0.0, 0.0, -2.0), Vector3D(0.0, 0.0, 0.0), Color()), radiusI(0.4), radiusE(0.5), faces(8),rings(8) {}
	Torus(Vector3D pos, Color color, Vector3D rot, float radiusI, float radiusE, int faces, int rings) : //Constructor
		Solid(pos, color, rot),
		radiusI(radiusI),
		radiusE(radiusE),
		faces(faces),
		rings(rings)
	{}

	Torus(float radiusI = 0, float radiusE = 0,int faces = 0, int rings=0) : //Constructor alternativo que solo recibe el tamaño y a su vez se puede omitir, contando entonces con un constructor por defecto
		Solid(),
		radiusI(radiusI),
		radiusE(radiusE),
		faces(faces),
		rings(rings)

	{}

	inline float GetRadiusI() const { return this->radiusI; }
	inline float GetRadiusE() const { return this->radiusE; }
	inline int GetFaces() const { return this->faces; }
	inline int GetRings() const { return this->rings; }

	inline void SetRadiusI(const float& radiusToSet) { this->radiusI = radiusToSet; }
	inline void SetRadiusE(const float& radiusToSet) { this->radiusE = radiusToSet; }
	inline void Setfaces(const int& facesToSet) { this->faces = facesToSet; }
	inline void SetRings(const int& ringsToSet) { this->rings = ringsToSet; }

	void Render();
};

