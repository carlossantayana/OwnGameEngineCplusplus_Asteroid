#include "TitleScene.h"

void TitleScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void TitleScene::ProcessKeyUp(unsigned char key, int px, int py) {
	//primera pre escena
	if (key == 'p') {
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

	opcion1 = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "Ejemplo 1");
	opcion2 = new Text(Vector3D(-6.0, 7.4, 2.0), Color(255.0, 255.0, 255.0), "Pulsa P");

}

void TitleScene::Render() {
	Scene::Render();


	//Renderizamos la propia
	opcion1->Render();
	opcion2->Render();


}


