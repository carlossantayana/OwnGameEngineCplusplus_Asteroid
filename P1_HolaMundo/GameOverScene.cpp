#include "GameOverScene.h"

void GameOverScene::Finalizar() 
{
	sceneManager->SetTitleScene();
}

void GameOverScene::Render() {
	Scene::Render();
	textLevel->Render();
}

void GameOverScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void GameOverScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void GameOverScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));

	textLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), text);
}

void GameOverScene::Update(const float& time) {
}

void GameOverScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void GameOverScene::ProcessMouseMovement(int x, int y) {
}