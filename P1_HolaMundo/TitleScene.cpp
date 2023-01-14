#include "TitleScene.h"

void TitleScene::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (key == 'p') {
		this->pulsado = TRUE;
	}
}

void TitleScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (pulsado) {
		pulsado = FALSE;
		sceneManager->SetNextScene();
	}
}

void TitleScene::ProcessMouseMovement(int x, int y) {
}

void TitleScene::ProcessMouseClick(int button, int state, int x, int y) {
}

void TitleScene::Update(const float& time) {
}

void TitleScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));
}

void TitleScene::Render() {
	Scene::Render();

	//Renderizamos la propia
}


