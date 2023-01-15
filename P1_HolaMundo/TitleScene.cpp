#include "TitleScene.h"
#include <mmsystem.h>

void TitleScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'p') {

		//Paramos el sonido
		//sndPlaySound(NULL, SND_FILENAME);

		sceneManager->SetNextScene();
	}
	else if (key == 'q') {

		//Paramos el sonido
		//sndPlaySound(NULL, SND_FILENAME);

		exit(0);
	}
}

void TitleScene::ProcessMouseClick(int button, int state, int x, int y) {
}

void TitleScene::Update(const float& time) {
}

void TitleScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 14.0)));

	Text* opcion1 = new Text(Vector3D(-1.8, 1, 0), Color(0, 255.0, 0), "Asteroids Returns");
	Text* opcion2 = new Text(Vector3D(-2.2, 0, 0), Color(255.0, 255.0, 0), "Pulsa P para Comenzar");
	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa Q para Salir");
	Text* opcion4 = new Text(Vector3D(-1.7, -2, 0), Color(255.0, 255.0, 255.0), "Practica 3-2022");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
	AddGameObject(opcion4);

	//string file = "..\\MenuInicio.wav";

	//std::wstring stemp = std::wstring(file.begin(), file.end());
	//LPCWSTR sw = stemp.c_str();

	//sndPlaySound(sw, SND_ASYNC | SND_FILENAME | SND_LOOP);

}

