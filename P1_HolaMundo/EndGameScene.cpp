#include "EndGameScene.h"

//ESTE METODO REALIZA EL CAMBIO DE ESCENA PARA VOLVER A LA PANTALLA DE TITULO
void EndGameScene::Finalizar()
{
	sceneManager->SetTitleScene();
}

////////////////////////////////////INICIALIZA LA ESCENA Y LOS OBJETOS QUE TENDRÁ///////////////////////////////////////////////
void EndGameScene::Init() {
	setCamera(Camera(Vector3D(0, 0, 12.0)));

	Text* opcion1 = new Text(Vector3D(-1.4, 1, 0), Color(0, 255.0, 0), "Victoria");
	Text* opcion2 = new Text(Vector3D(-2.0, 0, 0), Color(255.0, 255.0, 255.0), "Puntuacion: " + to_string((this->player->GetScore())));
	Text* opcion3 = new Text(Vector3D(-1.8, -1, 0), Color(255.0, 255.0, 0), "Pulsa P para Salir");
	AddGameObject(opcion1);
	AddGameObject(opcion2);
	AddGameObject(opcion3);
}

void EndGameScene::Update(const float& time) {
}

//////////////////////////////////LIMPIADO DE LA ESCENA//////////////////////////////////////////////////////////////
void EndGameScene::Clean()
{
	RestoreScene();
}

//////////////////////GESTIÓN DE EVENTOS DE TECLADO Y RATÓN PARA LA ESCENA FIN DEL JUEGO////////////////////////////////
//METODO QUE PROCESA EL TECLADO PARA LLAMAR AL CAMBIO DE ESCENA
void EndGameScene::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'p') {
		Finalizar();
	}
}

//METODO QUE PROCESA EL MOUSE PARA LLAMAR AL CAMBIO DE ESCENA
void EndGameScene::ProcessMouseClick(int button, int state, int x, int y) {
	if (button == 2)
	{
		Finalizar();
	}
}