#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Solid.h"
#include "Scene.h"
#include <chrono>
#include <vector>
#include "Model.h"
#include "Player.h" 

using namespace chrono;
using namespace std;

class Game
{
private: 
	Scene* activeScene;
	vector<Scene*> scenes;

	const double TIME_INCREMENT = 10; //ms en tiempo de juego
	const long UPDATE_PERIOD = 16; //ms en tiempo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

public: //El m�todo constructor as� como el resto de m�todos ser�n p�blicos

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	
	void Init(); //M�todo de inicializaci�n
	void Render(); //M�todo de dibujado
	void Update(); //M�todo de actualizaci�n

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};

