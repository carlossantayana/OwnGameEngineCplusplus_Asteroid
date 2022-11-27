#include "Scene.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {


	cout << "Tecla pulsada: " << key << endl;
}

void Scene::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	
	if (button == 0)
	{
		teapot1->SetSize(teapot1->GetSize() + 0.1);
	}
	if (button == 2)
	{
		teapot1->SetSize(teapot1->GetSize() - 0.1);
	}
	cout << "Click"<< endl;

}

void Scene::Init() {

	this->gameObjects.push_back(teapot2);
	this->gameObjects.push_back(teapot1);
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
	CheckBoundary();
}

void Scene::CheckBoundary() {
	for (int i = 0; i < gameObjects.size(); i++) {

		if (gameObjects[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX() || gameObjects[i]->GetPos().GetCoordinateX() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX() * -1.0f, gameObjects[i]->GetSpeed().GetCoordinateY(), gameObjects[i]->GetSpeed().GetCoordinateZ()));
		}

		if (gameObjects[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY() || gameObjects[i]->GetPos().GetCoordinateY() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX(), gameObjects[i]->GetSpeed().GetCoordinateY() * -1.0f, gameObjects[i]->GetSpeed().GetCoordinateZ()));
		}

		if (gameObjects[i]->GetPos().GetCoordinateZ() > boundary.GetCoordinateZ() || gameObjects[i]->GetPos().GetCoordinateZ() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX(), gameObjects[i]->GetSpeed().GetCoordinateY(), gameObjects[i]->GetSpeed().GetCoordinateZ() * -1.0f));
		}
	}
}
