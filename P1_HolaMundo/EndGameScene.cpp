#include "EndGameScene.h"

void EndGameScene::Finalizar()
{
	sceneManager->SetTitleScene();
}

void EndGameScene::Render() {
	Scene::Render();
	textLevel->Render();
}

void EndGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void EndGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void EndGameScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));

	textLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), text);
}

void EndGameScene::Update(const float& time) {
}

void EndGameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void EndGameScene::ProcessMouseMovement(int x, int y) {
}