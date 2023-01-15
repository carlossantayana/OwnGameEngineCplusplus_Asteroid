#include "InterGameScene.h"

//ESTE METODO REALIZA EL CAMBIO DE ESCENA PARA PASAR A LA SIGUIENTE ESCENA DE LA LISTA
void InterGameScene::Finalizar() 
{
	sceneManager->SetNextScene();
}

////////////////////////////////////INICIALIZA LA ESCENA Y LOS OBJETOS QUE TENDRÁ///////////////////////////////////////////////
void InterGameScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* opcion1 = new Text(Vector3D(-1.4, 1, 0), Color(0, 255.0, 0), "NIVEL: " + to_string(gameLevel));
	Text* opcion2 = new Text(Vector3D(-2.0, 0, 0), Color(255.0, 255.0, 255.0), "Puntuacion: " + to_string((this->player->GetScore())));

	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa P para Continuar");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
}

void InterGameScene::Update(const float& time) {
}

//////////////////////////////////LIMPIADO DE LA ESCENA//////////////////////////////////////////////////////////////
void InterGameScene::Clean()
{
	RestoreScene();
}

//////////////////////GESTIÓN DE EVENTOS DE TECLADO Y RATÓN PARA LAS ESCENAS ENTRE NIVELES////////////////////////////////
//METODO QUE PROCESA EL TECLADO PARA LLAMAR AL CAMBIO DE ESCENA
void InterGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'p') {
		Finalizar();
	}
}

//METODO QUE PROCESA EL MOUSE PARA LLAMAR AL CAMBIO DE ESCENA
void InterGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	if (button == 2)
	{
		Finalizar();
	}
}