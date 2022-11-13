#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Solid.h"
#include <vector>


using namespace std;

class Game
{
private: //Los atributos ser�n privados
	/*
	Vector3D posTeapot1 = Vector3D(-1.0, 1.0, -2.0);
	Color colorTeapot1 = Color(1.0, 0.5, 0.6);
	Vector3D orientationTeapot1 = Vector3D(180.0, 180.0, 90.0);

	Vector3D posTeapot2 = Vector3D(-1.0, 0.0, -2.0);
	Color colorTeapot2 = Color(1.0, 0.5, 0.6);
	Vector3D orientationTeapot2 = Vector3D(180.0, 180.0, 90.0);

	Vector3D posCube1 = Vector3D(0.0, 1.0, -2.0);
	Color colorCube1 = Color(1.0, 0.5, 0.6);
	Vector3D orientationCube1 = Vector3D(45.0, 45.0, 45.0);

	Vector3D posCube2 = Vector3D(0.0, 0.0, -2.0);
	Color colorCube2 = Color(1.0, 0.5, 0.6);
	Vector3D orientationCube2 = Vector3D(45.0, 45.0, 45.0);

	Vector3D posSphere1 = Vector3D(1.0, 1.0, -2.0);
	Color colorSphere1 = Color(1.0, 0.5, 0.6);
	Vector3D orientationSphere1 = Vector3D(0.0, 45.0, 0.0);

	Vector3D posSphere2 = Vector3D(1.0, 0.0, -2.0);
	Color colorSphere2 = Color(1.0, 0.5, 0.6);
	Vector3D orientationSphere2 = Vector3D(0.0, 45.0, 0.0);
	*/ //Preguntar por qu� no funcionan
	vector <Solid*> gameObjects;
	Vector3D boundary;

	void CheckBoundary();

public: //El m�todo constructor as� como el resto de m�todos ser�n p�blicos

	Game() : boundary(Vector3D(8.0, 6.0, 4.0)) {}
	
	void Init(); //M�todo de inicializaci�n
	void Render(); //M�todo de dibujado
	void Update(); //M�todo de actualizaci�n
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};

