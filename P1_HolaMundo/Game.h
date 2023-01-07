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

using namespace chrono;
using namespace std;

class Game
{
private: 
	Scene* activeScene;
	vector<Scene*> scenes;

	const double TIME_INCREMENT = 0.4; //ms en tiempo de juego
	const long UPDATE_PERIOD = 10; //ms en tiempo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;


public: //El método constructor así como el resto de métodos serán públicos

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	
	void Init(); //Método de inicialización
	void Render(); //Método de dibujado
	void Update(); //Método de actualización
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
};

