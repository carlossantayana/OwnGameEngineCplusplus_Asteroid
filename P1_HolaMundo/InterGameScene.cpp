#include "InterGameScene.h"

void InterGameScene::Finalizar() 
{
	//el primer game
	sceneManager->SetNextScene();
}

void InterGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void InterGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void InterGameScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* opcion1 = new Text(Vector3D(-1.4, 1, 0), Color(0, 255.0, 0), "NIVEL: " + to_string(gameLevel));
	Text* opcion2 = new Text(Vector3D(-2.0, 0, 0), Color(255.0, 255.0, 255.0), "Puntuacion: " + to_string((this->player->GetScore())));

	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa para Continuar");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
}

void InterGameScene::Update(const float& time) {
}

