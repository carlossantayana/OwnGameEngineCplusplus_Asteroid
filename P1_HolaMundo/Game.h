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

	//Instancia del jugador, que se compartirá entre todas las escenas del juego
	Player* player;
	
	//Escena Activa, se asignará en función del estado del juego
	Scene* activeScene;

	//Escena de Pausa, se asignará cuando se invoque el método SceneManager::SetPause()
	Scene* pauseScene;
	//Escena anterior a activar Pausa, se asignará para poder recuperarla al terminar la pausa
	Scene* prePauseScene = NULL;


	//Escena De Título, se asignará cuando se invoque el método SceneManager::SetTitleScene()
	Scene* titleScene;

	//Escena De Fin de Juego (Muerte), se asignará cuando se invoque el método SceneManager::SetGameOverScene()
	Scene* gameOverScene;

	//Escena De Fin de Juego (Fin de Niveles), se asignará cuando terminen tras invocar el método SceneManager::SetNextScene y no queden mas escenas disponibles en "scenes"
	Scene* endGameScene;

	//Indice para recorrer las escenas del juego almacenadas en "scenes"
	int indexScene = 0;
	//Vector que almacena en orden las distintas escenas que componen el juego (quedan excluidas las excepcionales como Menú, Fin de Juego, Pausa, ...)
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
	void SetPause();
	void SetNoPause();
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

