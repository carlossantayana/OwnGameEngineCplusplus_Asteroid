#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"

using namespace std;

class Game
{
private: //Los atributos ser�n privados
	Teapot teapot1;
	Teapot teapot2;
	Cube cube1;
	Cube cube2;
	Sphere sphere1;
	Sphere sphere2;
public: //El m�todo constructor as� como el resto de m�todos ser�n p�blicos

	Game() :
		teapot1 (Teapot(-1.0, 1.0, -2.0, 1.0, 0.5, 0.6, 180.0, 180.0, 90.0, 0.2)),
		teapot2 (Teapot(-1.0, 0.0, -2.0, 1.0, 0.5, 0.6, 180.0, 180.0, 90.0, 0.4)),
		cube1 (Cube(0.0, 1.0, -2.0, 1.0, 0.5, 0.6, 45.0, 45.0, 45.0, 0.2)),
		cube2 (Cube(0.0, 0.0, -2.0, 1.0, 0.5, 0.6, 45.0, 45.0, 45.0, 0.4)),
		sphere1 (Sphere(1.0, 1.0, -2.0, 1.0, 0.5, 0.6, 0.0, 45.0, 0.0, 0.2, 20, 20)),
		sphere2 (Sphere(1.0, 0.0, -2.0, 1.0, 0.5, 0.6, 0.0, 45.0, 0.0, 0.4, 20, 20))
	{}

	Teapot GetTeapot1() { return this->teapot1; }
	Cube GetCube1() { return this-> cube1; }
	Sphere GetSphere1() { return this-> sphere1; }
	Teapot GetTeapot2() { return this->teapot2; }
	Cube GetCube2() { return this->cube2; }
	Sphere GetSphere2() { return this->sphere2; }
	void Init(); //M�todo de inicializaci�n
	void Render(); //M�todo de dibujado
	void Update(); //M�todo de actualizaci�n
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
	void ChangeProperties();
};
