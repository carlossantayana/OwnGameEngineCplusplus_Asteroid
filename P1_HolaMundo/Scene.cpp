#include "Scene.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {


	cout << "Tecla pulsada: " << key << endl;
}

void Scene::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {


	cout << "Click: " << button << endl;
}

void Scene::Init() {
	Teapot* teapot = new Teapot(Vector3D(3.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.001, 0.002, 0.003), 0.4);
	Teapot* teapot2 = new Teapot(Vector3D(3.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.001, 0.002, 0.003), 0.4);
	Cube* cube = new Cube(Vector3D(4.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.002), 0.4);
	Sphere* sphere = new Sphere(Vector3D(5.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.008, 0.002, 0.001), 0.4, 20, 20);

	this->gameObjects.push_back(teapot2);
	this->gameObjects.push_back(teapot);
	this->gameObjects.push_back(cube);
	this->gameObjects.push_back(sphere);
}

void Scene::Render() {

	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
	}
}
