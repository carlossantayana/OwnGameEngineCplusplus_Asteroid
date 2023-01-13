#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameOverScene.h"
#include "GameScene.h"
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

void Game::Init() {
	//CREACIÓN DE OBJETOS
	ModelLoader* loader = new ModelLoader();

	//Modelos Importados
	Model* naveModel = new Model();
	Model* asteroidModel1 = new Model();
	Model* asteroidModel2 = new Model();
	Model* asteroidModel3 = new Model();
	

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

	Player* player = new Player(naveModel, Vector3D(1, 0, 0));
	
	//Configuracion Texto
	Text* textoPoints = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "0000");
	Text* textoLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "LEVEL 1");

	//Configuracion Asteroides
	loader->setScale(0.05);
	loader->loadModel("..\\AsteroidModel1.obj");
	*asteroidModel1 = loader->getModel();

	asteroidModel1->SetPos(Vector3D(-3.0, -2.0, 1.0));
	asteroidModel1->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel1->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel1->SetOrientationSpeed(Vector3D(0.1, 0.15, 0.2));
	asteroidModel1->SetSpeed(Vector3D(0.01, 0.02, 0.0));
	loader->clear();

	Asteroid* asteroide1 = new Asteroid(asteroidModel1);

	loader->setScale(0.05);
	loader->loadModel("..\\AsteroidModel2.obj");
	*asteroidModel2 = loader->getModel();

	asteroidModel2->SetPos(Vector3D(15.0, 11.0, 1.0));
	asteroidModel2->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel2->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel2->SetOrientationSpeed(Vector3D(0.1, 0.2, 0.15));
	asteroidModel2->SetSpeed(Vector3D(0.02, 0.01, 0.0));
	loader->clear();

	Asteroid* asteroide2 = new Asteroid(asteroidModel2);

	loader->setScale(0.05);
	loader->loadModel("..\\AsteroidModel3.obj");
	*asteroidModel3 = loader->getModel();

	asteroidModel3->SetPos(Vector3D(2.0, 2.0, 1.0));
	asteroidModel3->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel3->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel3->SetOrientationSpeed(Vector3D( 0.2, 0.15, 0.1));
	asteroidModel3->SetSpeed(Vector3D(0.01, 0.01, 0.0));
	loader->clear();

	Asteroid* asteroide3 = new Asteroid(asteroidModel3);

	loader->setScale(0.05);
	loader->loadModel("..\\AsteroidModel3.obj");
	*asteroidModel3 = loader->getModel();

	asteroidModel3->SetPos(Vector3D(13, 2.0, 1.0));
	asteroidModel3->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel3->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel3->SetOrientationSpeed(Vector3D(0.2, 0.15, 0.1));
	asteroidModel3->SetSpeed(Vector3D(0.01, 0.01, 0.0));
	loader->clear();

	Asteroid* asteroide4 = new Asteroid(asteroidModel3);


	//CREACIÓN DE ESCENAS
	//Scene* titleScene = new(nothrow) TitleScene(/*this*/);
	Scene* gameScene = new(nothrow) GameScene(player);

	
	//INSERCIÓN DE OBJETOS EN LA ESCENA
	gameScene->AddGameObject(naveModel);

	gameScene->AddGameObject(textoPoints);

	gameScene->AddGameObject(asteroidModel1); 
	gameScene->AddGameObject(asteroidModel2); 
	gameScene->AddGameObject(asteroidModel3); 

	//AÑADIR LA ESCENA AL JUEGO
	this->scenes.push_back(gameScene);

	//COLOCAR COMO ESCENA ACTIVA
	this->activeScene = gameScene;
	activeScene->Init();
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