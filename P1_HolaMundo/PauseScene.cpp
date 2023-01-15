#include "PauseScene.h"
#include "Text.h"

void PauseScene::Finalizar()
{
	sceneManager->SetNoPause();
}

void PauseScene::Render() {
	Scene::Render();
	textLevel->Render();
}

void PauseScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void PauseScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void PauseScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));

	textLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), text);
}

void PauseScene::Update(const float& time) {
}

void PauseScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void PauseScene::ProcessMouseMovement(int x, int y) {
}