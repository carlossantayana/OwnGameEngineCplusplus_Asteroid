#include "InterGameScene.h"

void InterGameScene::Finalizar() 
{
	//el primer game
	sceneManager->SetNextScene();
}

void InterGameScene::Render() {
	Scene::Render();
	textLevel->Render();
}

void InterGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void InterGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void InterGameScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));

	textLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), text);
}

void InterGameScene::Update(const float& time) {
}

void InterGameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void InterGameScene::ProcessMouseMovement(int x, int y) {
}