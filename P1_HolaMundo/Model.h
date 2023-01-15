#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Model : public Solid {

private:
	//Atributo: vector de tri�ngulos que conforman un modelo 3D
	vector<Triangle> triangles;
	
public:
	//Constructor de modelos
	Model(Vector3D pos = Vector3D(), Color color = Color(), Vector3D rotation = Vector3D()) : Solid(pos, color, rotation) {}

	//M�todos que permiten manejar un modelo 3D. A�adir tri�ngulos, pintar el modelo de un color, etc
	void addTriangle(Triangle triangle);
	void paintColor(Color color);
	void clear();

	//Renderizado de un modelo 3D
	void Render();
};

