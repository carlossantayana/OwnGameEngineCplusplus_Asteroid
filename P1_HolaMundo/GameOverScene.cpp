#include "GameOverScene.h"

//ESTE METODO REALIZA EL CAMBIO DE ESCENA PARA PASAR A LA SIGUIENTE ESCENA DE LA LISTA
void GameOverScene::Finalizar() 
{
	sceneManager->SetTitleScene();
}

////////////////////////////////////INICIALIZA LA ESCENA Y LOS OBJETOS QUE TENDRÁ///////////////////////////////////////////////
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

//////////////////////GESTIÓN DE EVENTOS DE TECLADO Y RATÓN PARA LA ESCENA PERDER LA PARTIDA////////////////////////////////
//METODO QUE PROCESA EL TECLADO PARA LLAMAR AL CAMBIO DE ESCENA//////////////////////////////////
void GameOverScene::ProcessKeyUp(unsigned char key, int px, int py) {
	Finalizar();
}

//METODO QUE PROCESA EL MOUSE PARA LLAMAR AL CAMBIO DE ESCENA///////////////////////////////////
void GameOverScene::ProcessMouseClick(int button, int state, int x, int y) {
	Finalizar();
}