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

	//Instancia del jugador, que se compartir� entre todas las escenas del juego
	Player* player;
	
	//Escena Activa, se asignar� en funci�n del estado del juego
	Scene* activeScene;

	//Escena de Pausa, se asignar� cuando se invoque el m�todo SceneManager::SetPause()
	Scene* pauseScene;
	//Escena anterior a activar Pausa, se asignar� para poder recuperarla al terminar la pausa
	Scene* prePauseScene = NULL;


	//Escena De T�tulo, se asignar� cuando se invoque el m�todo SceneManager::SetTitleScene()
	Scene* titleScene;

	//Escena De Fin de Juego (Muerte), se asignar� cuando se invoque el m�todo SceneManager::SetGameOverScene()
	Scene* gameOverScene;

	//Escena De Fin de Juego (Fin de Niveles), se asignar� cuando terminen tras invocar el m�todo SceneManager::SetNextScene y no queden mas escenas disponibles en "scenes"
	Scene* endGameScene;

	//Indice para recorrer las escenas del juego almacenadas en "scenes"
	int indexScene = 0;
	//Vector que almacena en orden las distintas escenas que componen el juego (quedan excluidas las excepcionales como Men�, Fin de Juego, Pausa, ...)
	vector<Scene*> scenes;

	const double TIME_INCREMENT = 10; //ms en tiempo de juego
	const long UPDATE_PERIOD = 16; //ms en tiempo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	void CreatePlayer();

public: //El m�todo constructor as� como el resto de m�todos ser�n p�blicos

#pragma region SceneManager
	void SetTitleScene();
	void SetGameOverScene();
	void SetNextScene();
	void SetPause();
	void SetNoPause();
#pragma endregion

	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	
	void Init(); //M�todo de inicializaci�n
	void Render(); //M�todo de dibujado
	void Update(); //M�todo de actualizaci�n

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};

