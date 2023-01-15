#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "InterGameScene.h"
#include "PauseScene.h"
#include "EndGameScene.h"
#include<time.h>
#include "Text.h"
#include "Player.h"
#include "Asteroid.h"
#include <stdlib.h>

using namespace std;

//MÉTODO PRIVADO QUE SE ENCARGA DE LA CREACIÓN DEL JUGADOR
void Game::CreatePlayer() 
{
	ModelLoader* loader = new ModelLoader();

	Model* naveModel = new Model();
	//Configuracion Nave Espacial
	loader->setScale(0.1);
	loader->loadModel("..\\SpaceShip2.obj");
	*naveModel = loader->getModel();

	naveModel->paintColor(Color(1.0, 0.5, 0.6));
	naveModel->SetOrientation(Vector3D(0, 0, 0));
	naveModel->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	naveModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	naveModel->SetHitBoxRadius(0.4);

	loader->clear();
	this->player = new Player(naveModel, Vector3D(1, 0, 0));
}

///////////////////////////////////IMPLEMENTACIÓN DE LA INTERFAZ SCENEMANAGER///////////////////////////////////////////
void Game::SetTitleScene() 
{
	if (activeScene != NULL)
	{
		activeScene->Clean();
	}

	//Inicializamos la primera Scena
	this->indexScene = -1;
	this->activeScene = titleScene;
	this->player->SetLifesNum(3);
	this->player->SetScore(0);
	activeScene->Init();
}

void Game::SetGameOverScene() 
{
	if (activeScene != NULL)
	{
		activeScene->Clean();
	}

	this->player->SetSpeed(0);
	this->player->SetWPressed(false);
	this->player->SetAPressed(false);
	this->player->SetDPressed(false);
	this->activeScene = gameOverScene;
	activeScene->Init();
}

void Game::SetNextScene() 
{
	if (activeScene != NULL)
	{
		activeScene->Clean();
	}

	this->player->SetSpeed(0);
	this->player->SetWPressed(false);
	this->player->SetAPressed(false);
	this->player->SetDPressed(false);
	this->indexScene++;
	if (this->indexScene == this->scenes.size())
	{
		//Fin del Juego
		this->activeScene = this->endGameScene;
		this->activeScene->Init();
		return;
	}
	
	this->activeScene = this->scenes[this->indexScene];
	this->activeScene->Init();
}

void Game::SetPause()
{
	this->prePauseScene = this->activeScene;
	this->activeScene = this->pauseScene;
	this->activeScene->Init();
}

void Game::SetNoPause()
{
	this->activeScene = this->prePauseScene;
	this->prePauseScene = NULL;
}

/////////////////////////////MÉTODOS DE INICIALIZACIÓN DE ESCENAS Y ACTUALIZACIÓN Y RENDERIZADO DE LA ESCENA ACTIVA DEL JUEGO///////////////////////////
void Game::Init() {
	ModelLoader* loader = new ModelLoader();
	CreatePlayer();


	//CREACI�N DE ESCENAS COMUNES
	this->titleScene = new(nothrow) TitleScene(this);

	this->gameOverScene = new(nothrow) GameOverScene(this, player);

	this->endGameScene = new(nothrow) EndGameScene(this, player);

	this->pauseScene = new(nothrow) PauseScene(this);

	for (int lv = 1;lv < 5;lv++) 
	{
		Scene* preGameScene1 = new(nothrow) InterGameScene(this, lv, player);
		Scene* gameScene1 = new(nothrow) GameScene(this, player, lv);

		//A�ADIR LAS ESCENAS AL JUEGO
		this->scenes.push_back(preGameScene1);
		this->scenes.push_back(gameScene1);
	}

	SetTitleScene();
}

void Game::Render() {
	this->activeScene->Render();
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}

/////////////////////////////PROCESAMIENTO DE TECLAS DEL JUEGO/////////////////////////////////////////////////
void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessKeyUp(unsigned char key, int px, int py){

	this->activeScene->ProcessKeyUp(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	this->activeScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	this->activeScene->ProcessMouseClick(button,state,x,y);
}