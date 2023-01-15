#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Model : public Solid {

private:
	//Atributo: vector de triángulos que conforman un modelo 3D
	vector<Triangle> triangles;
	
public:
	//Constructor de modelos
	Model(Vector3D pos = Vector3D(), Color color = Color(), Vector3D rotation = Vector3D()) : Solid(pos, color, rotation) {}

	//Métodos que permiten manejar un modelo 3D. Añadir triángulos, pintar el modelo de un color, etc
	void addTriangle(Triangle triangle);
	void paintColor(Color color);
	void clear();

	//Renderizado de un modelo 3D
	void Render();
};

