#include "TextScene.h"
void TextScene::ProcessKeyPressed(unsigned char key, int px, int py) {
}

void TextScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

void TextScene::ProcessMouseMovement(int x, int y) {
}

void TextScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}

void TextScene::Update(const float& time) {
}

void TextScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));

	textoLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), text);
}

void TextScene::Render() {
	Scene::Render();
	textoLevel->Render();
}
