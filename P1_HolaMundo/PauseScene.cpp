#include "PauseScene.h"
#include "Text.h"

////////////////////////////////////INICIALIZA LA ESCENA Y LOS OBJETOS QUE TENDRÁ///////////////////////////////////////////////
void PauseScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* textLabel1 = new Text(Vector3D(-2.0, 1, 0), Color(255.0, 255.0, 255.0), "JUEGO PAUSADO");
	Text* textLabel2 = new Text(Vector3D(-3.2, -1, 0), Color(255.0, 255.0, 255.0), "PULSA M PARA FINALIZAR PARTIDA");
	AddGameObject(textLabel1);
	AddGameObject(textLabel2);
}

void PauseScene::Update(const float& time) {
}

//////////////////////GESTIÓN DE EVENTOS DE TECLADO Y RATÓN PARA LA ESCENA DE PAUSA////////////////////////////////
/////ESTE METODO REALIZA EL CAMBIO DE ESCENA PARA VOLVER A LA ESCENA DEL JUEGO O VOLVER A LA ESCENA DEL TÍTULO////
void PauseScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'm') {

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




