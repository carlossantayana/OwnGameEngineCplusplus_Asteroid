#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"
#include "Scene.h"
#include<time.h>

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	this->activeScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	this->activeScene->ProcessMouseClick(button,state,x,y);
}

void Game::Init() {
	//agregado
	//this->mainScene.setDrawVertexes(false);
	//this->mainScene.setDrawBox(true);
	//agregado
	
	//CREACIÓN DE ESCENAS
	Scene* titleScene = new(nothrow) Scene(/*this*/);

	//CREACIÓN DE OBJETOS
	Teapot* teapot1 = new Teapot(Vector3D(3.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.001, 0.002, 0.003), 0.4);
	Teapot* teapot2 = new Teapot(Vector3D(2.5, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(90.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.001), 0.4);
	Cube* cube = new Cube(Vector3D(4.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.002), 0.4);
	Sphere* sphere = new Sphere(Vector3D(5.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.008, 0.002, 0.001), 0.4, 20, 20);

	ModelLoader* loader = new ModelLoader();
	Model* heart = new Model();

	loader->setScale(1.0);
	loader->loadModel("..\\Heart.obj");
	*heart = loader->getModel();

	heart->SetPos(Vector3D(2.0, 2.5, 2.0));
	heart->paintColor(Color(1.0, 0.5, 0.6));
	heart->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	heart->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	heart->SetSpeed(Vector3D(0.001, 0.002, 0.003));
	loader->clear();
	

	//INSERCIÓN DE OBJETOS EN LA ESCENA
	titleScene->AddGameObject(teapot1);
	titleScene->AddGameObject(teapot2);
	titleScene->AddGameObject(cube);
	titleScene->AddGameObject(sphere);
	titleScene->AddGameObject(heart);

	//AÑADIR LA ESCENA AL JUEGO
	this->scenes.push_back(titleScene);

	//COLOCAR COMO ESCENA ACTIVA
	this->activeScene = titleScene;
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