#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Solid.h"
#include "Scene.h"
#include <vector>


using namespace std;

class Game
{
private: 
	Scene mainScene;
	


public: //El método constructor así como el resto de métodos serán públicos

	Game()  {}
	
	void Init(); //Método de inicialización
	void Render(); //Método de dibujado
	void Update(); //Método de actualización
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
};

