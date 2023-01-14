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

class Game : public SceneManager
{
private: 
	Player* player;
	
	Scene* activeScene;

	Scene* titleScene;
	Scene* gameOverScene;
	Scene* endGameScene;

	int initialScene = 0;
	vector<Scene*> scenes;

	const double TIME_INCREMENT = 10; //ms en tiempo de juego
	const long UPDATE_PERIOD = 16; //ms en tiempo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	void CreatePlayer();

public: //El método constructor así como el resto de métodos serán públicos

#pragma region SceneManager
	void SetTitleScene();
	void SetGameOverScene();
	void SetNextScene();
#pragma endregion

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	
	void Init(); //Método de inicialización
	void Render(); //Método de dibujado
	void Update(); //Método de actualización

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
};

