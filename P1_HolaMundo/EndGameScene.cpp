#include "EndGameScene.h"

void EndGameScene::Finalizar()
{
	sceneManager->SetTitleScene();
}

void EndGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void EndGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void EndGameScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* opcion1 = new Text(Vector3D(-1.4, 1, 0), Color(0, 255.0, 0), "Victoria");
	Text* opcion2 = new Text(Vector3D(-2.0, 0, 0), Color(255.0, 255.0, 255.0), "Puntuacion: " + to_string((this->player->GetScore())));
	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa para Salir");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
}

void EndGameScene::Update(const float& time) {
}
