#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"
#include "Scene.h"
#include<time.h>

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->mainScene.ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y) {
	this->mainScene.ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	this->mainScene.ProcessMouseClick(button,state,x,y);
}

void Game::Init() {
	this->mainScene.Init();
}

void Game::Render() {
	this->mainScene.Render();
}

void Game::Update() {
	this->mainScene.Update();
}


