#pragma once
#include "Scene.h"
#include "Text.h"
#include "Player.h"
class EndGameScene : public Scene
{
private:
	///////////////////ATRIBUTOS DE LA CLASE ENDGAMESCENE///////////////////////////////
	Player* player;
	
	/////////////////////////////M�TODOS PRIVADOS QUE GESTIONAN LA ESCENA FIN DEL JUEGO//////////////////////////////////////
	void Finalizar();
public:
	//CONSTRUCTOR DE LA CLASE ENDGAMESCENE
	EndGameScene(SceneManager* scMgr, Player* player): Scene(scMgr), player(player) {};

	//INICIALIZACI�N Y ACTUALIZACI�N DE LA ESCENA
	void Init();
	void Update(const float& time);

	//PROCESAMIENTO DE TECLAS
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};