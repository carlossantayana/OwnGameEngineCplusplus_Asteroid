#include "GameOverScene.h"

void GameOverScene::Finalizar() 
{
	sceneManager->SetTitleScene();
}

void GameOverScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void GameOverScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void GameOverScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* opcion1 = new Text(Vector3D(-1.8, 1, 0), Color(0, 255.0, 0), "Fin de Partida");
	Text* opcion2 = new Text(Vector3D(-2.0, 0, 0), Color(255.0, 255.0, 255.0), "Puntuacion: " + to_string((this->player->GetScore())));

	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa para Salir");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
}

void GameOverScene::Update(const float& time) {
}

