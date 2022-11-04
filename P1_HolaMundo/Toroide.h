#pragma once
#include<GL/glut.h>
#include"Solid.h"
class Toroide :public Solid
{
private:

	float radioI;
	float radioE;
	int faces;
	int rings;

public:
	Toroide() : Solid(Vector3D(0.0, 0.0, -2.0), Vector3D(0.0, 0.0, 0.0), Color()), radioI(0.4), radioE(0.4), faces(8),rings(8) {}

	inline float GetRadioI() const { return this->radioI; }
	inline float GetRadioE() const { return this->radioE; }
	inline int GetFaces() const { return this->faces; }
	inline int GetRings() const { return this->rings; }

	inline void SetRadioI(const float& radioToSet) { this->radioI = radioToSet; }
	inline void SetRadioE(const float& radioToSet) { this->radioE = radioToSet; }
	inline void Setfaces(const int& facesToSet) { this->faces = facesToSet; }
	inline void SetRings(const int& ringsToSet) { this->rings = ringsToSet; }

	void Render();
};

