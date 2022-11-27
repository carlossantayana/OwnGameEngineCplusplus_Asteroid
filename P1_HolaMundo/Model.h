#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Model : public Solid {

private:
	vector<Triangle> triangles;
	
public:

	Model(Vector3D pos = Vector3D(), Color color = Color(), Vector3D rotation = Vector3D()) : Solid(pos, color, rotation) {}

	void addTriangle(Triangle triangle);
	void paintColor(Color color);
	void clear();


	void Render();


};

