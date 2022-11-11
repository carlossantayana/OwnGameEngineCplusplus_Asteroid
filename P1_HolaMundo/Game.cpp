#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"
#include<time.h>

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	

	cout << "Tecla pulsada: " << key << endl;
}

void Game::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	

	cout << "Click: " << button << endl;
}

void Game::Init() {
	Teapot* teapot = new Teapot(Vector3D(-1.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), 0.4);
	Cube* cube = new Cube(Vector3D(0.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), 0.4);
	Sphere* sphere = new Sphere(Vector3D(1.0, 0.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), 0.4, 20, 20);
	Cuboid* cuboid = new Cuboid(Vector3D(-1.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), 0.4, 0.4, 0.4);
	Torus* torus = new Torus(Vector3D(0.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), 0.2, 0.4, 20.0, 20.0);
	Cylinder* cylinder = new Cylinder(Vector3D(1.0, 1.0, -2.0), Color(1.0, 0.5, 0.6), Vector3D(180, 180, 90), 0.4, 0.4, 0.5, 20, 20);

	this->gameObjects.push_back(teapot);
	this->gameObjects.push_back(cuboid);
	this->gameObjects.push_back(cube);
	this->gameObjects.push_back(torus);
	this->gameObjects.push_back(sphere);
	this->gameObjects.push_back(cylinder);
}

void Game::Render() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Game::Update() {

}

