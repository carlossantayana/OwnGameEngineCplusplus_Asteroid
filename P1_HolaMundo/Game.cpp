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
	//CREACIÓN DE ESCENAS
	this->titleScene = new(nothrow) TitleScene(this);

	this->gameOverScene = new(nothrow) GameOverScene(this, "Perdiste");

	this->endGameScene = new(nothrow) EndGameScene(this, "Ganaste Paco");

	this->pauseScene = new(nothrow) PauseScene(this, "Has pausado el juego Paco");

	//Scene* kk = new(nothrow) InterGameScene(this, this->player, 1);
	//this->activeScene = kk;
	//activeScene->Init();


	for (int lv = 1;lv < 5;lv++) 
	{
		Scene* preGameScene1 = new(nothrow) InterGameScene(this, lv,"nivel");
		Scene* gameScene1 = new(nothrow) GameScene(this, lv);

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

void Game::SetTitleScene() 
{
	//Inicializamos la primera Scena
	this->indexScene = -1;
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