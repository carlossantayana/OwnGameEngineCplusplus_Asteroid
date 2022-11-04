#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Solid.h"

using namespace std;

class Game
{
private: //Los atributos serán privados
	Teapot teapot1;
	Teapot teapot2;
	Cube cube1;
	Cube cube2;
	Sphere sphere1;
	Sphere sphere2;
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
	*/ //Preguntar por qué
public: //El método constructor así como el resto de métodos serán públicos

	Game() :
		teapot1 (Teapot(Vector3D(-1.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), 0.2)),
		teapot2 (Teapot(Vector3D(-1.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), 0.4)),
		cube1 (Cube(Vector3D(0.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), 0.2)),
		cube2 (Cube(Vector3D(0.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), 0.4)),
		sphere1 (Sphere(Vector3D(1.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), 0.2, 20, 20)),
		sphere2 (Sphere(Vector3D(1.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), 0.4, 20, 20))
	{}

	Teapot GetTeapot1() { return this->teapot1; }
	Cube GetCube1() { return this-> cube1; }
	Sphere GetSphere1() { return this-> sphere1; }
	Teapot GetTeapot2() { return this->teapot2; }
	Cube GetCube2() { return this->cube2; }
	Sphere GetSphere2() { return this->sphere2; }
	void Init(); //Método de inicialización
	void Render(); //Método de dibujado
	void Update(); //Método de actualización
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
	void ChangeProperties();
};

