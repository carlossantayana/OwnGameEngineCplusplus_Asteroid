#include "PauseScene.h"
#include "Text.h"

void PauseScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'm') {

		//Paramos el sonido
		//sndPlaySound(NULL, SND_FILENAME);

		sceneManager->SetTitleScene();
	}
	else 
	{
		sceneManager->SetNoPause();
	}
}

void PauseScene::ProcessMouseClick(int button, int state, int x, int y) {
	sceneManager->SetNoPause();
}

void PauseScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* textLabel1 = new Text(Vector3D(-2.0, 1, 0), Color(255.0, 255.0, 255.0), "JUEGO PAUSADO");
	Text* textLabel2 = new Text(Vector3D(-3.2, -1, 0), Color(255.0, 255.0, 255.0), "PULSA M PARA FINALIZAR PARTIDA");
	AddGameObject(textLabel1);
	AddGameObject(textLabel2);
}

void PauseScene::Update(const float& time) {
}
