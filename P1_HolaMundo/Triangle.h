#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <GL/glut.h>

class Triangle
{
private:
	//Atributos de un triángulo
	//3 vértices
	Vector3D vertex1;
	Vector3D vertex2;
	Vector3D vertex3;

	//Una normal por vértice
	Vector3D normal1;
	Vector3D normal2;
	Vector3D normal3;

	//Un color por vértice
	Color color1;
	Color color2;
	Color color3;

public:
	//Constructor de triángulos
	Triangle(Vector3D vertex1 = Vector3D(), Vector3D vertex2 = Vector3D(), Vector3D vertex3 = Vector3D(), 
		Vector3D normal1 = Vector3D(),  Vector3D normal2 = Vector3D(), 
		Vector3D normal3 = Vector3D(), Color color1 = Color(), Color color2 = Color(), Color color3 = Color()) :
	    vertex1(vertex1), vertex2(vertex2), vertex3(vertex3), 
		normal1(normal1), normal2(normal2), normal3(normal3), 
		color1(color1), color2(color2), color3(color3) 
	{}

	//Método de renderizado de triángulos
	void Render();

	//Getters
	inline Vector3D getVertex1() { return vertex1; }
	inline Vector3D getVertex2() { return vertex2; }
	inline Vector3D getVertex3() { return vertex3; }

	inline Vector3D getNormal1() { return normal1; }
	inline Vector3D getNormal2() { return normal2; }
	inline Vector3D getNormal3() { return normal3; }

	inline Color getColor1() { return color1; }
	inline Color getColor2() { return color2; }
	inline Color getColor3() { return color3; }

	//Setters
	inline void setVertex1(Vector3D vertex1ToSet) { vertex1 = vertex1ToSet; }
	inline void setVertex2(Vector3D vertex2ToSet) { vertex2 = vertex2ToSet; }
	inline void setVertex3(Vector3D vertex3ToSet) { vertex1 = vertex3ToSet; }

	inline void setNormal1(Vector3D normal1ToSet) { normal1 = normal1ToSet; }
	inline void setNormal2(Vector3D normal2ToSet) { normal2 = normal2ToSet; }
	inline void setNormal3(Vector3D normal3ToSet) { normal3 = normal3ToSet; }

	inline void setColor1(Color color1ToSet) { color1 = color1ToSet; }
	inline void setColor2(Color color2ToSet) { color2 = color2ToSet; }
	inline void setColor3(Color color3ToSet) { color3 = color3ToSet; }
};

