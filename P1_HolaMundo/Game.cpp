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
#include<time.h>
#include "Text.h"
#include "Player.h"
#include "Asteroid.h"
#include <stdlib.h>

using namespace std;

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

void Game::CreatePlayer() 
{
	//CREACIÓN DE OBJETOS
	ModelLoader* loader = new ModelLoader();

	//Modelos Importados
	Model* naveModel = new Model();
	//Configuracion Nave Espacial
	loader->setScale(0.25);
	loader->loadModel("..\\SpaceShip2.obj");
	*naveModel = loader->getModel();

	naveModel->SetPos(Vector3D(1.0, 1.0, 1));
	naveModel->paintColor(Color(1.0, 0.5, 0.6));
	naveModel->SetOrientation(Vector3D(0, 0, 0));
	naveModel->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	naveModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	loader->clear();
	delete loader;

	this->player = new Player(naveModel, Vector3D(1, 0, 0));
}



void Game::Init() {
	CreatePlayer();


	//CREACIÓN DE ESCENAS
	this->titleScene = new(nothrow) TitleScene(this);
	this->gameOverScene = new(nothrow) GameOverScene(this);

	//TODO: Hacer la EndGame
	this->endGameScene = new(nothrow) GameOverScene(this);

	//Scene* kk = new(nothrow) InterGameScene(this, this->player, 1);
	//this->activeScene = kk;
	//activeScene->Init();


	for (int lv = 1;lv < 5;lv++) 
	{
		Scene* preGameScene1 = new(nothrow) InterGameScene(this, this->player, lv);
		Scene* gameScene1 = new(nothrow) GameScene(this, this->player, lv);

		//AÑADIR LAS ESCENAS AL JUEGO
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

void Game::SetTitleScene() 
{
	//Inicializamos jugador
	this->player->InicializarDatosPartida();

	//Inicializamos la primera Scena
	this->initialScene = -1;
	this->activeScene = titleScene;
	activeScene->Init();
}

void Game::SetGameOverScene() 
{
	this->activeScene = gameOverScene;
	activeScene->Init();
}

void Game::SetNextScene() 
{
	this->initialScene++;
	if (this->initialScene == this->scenes.size())
	{
		//Fin del Juego
		this->activeScene = this->endGameScene;
		this->activeScene->Init();
		return;
	}
	
	this->activeScene = this->scenes[this->initialScene];
	this->activeScene->Init();
}
