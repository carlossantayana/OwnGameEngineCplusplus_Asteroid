#pragma once
#include "Scene.h"
#include "Text.h"
#include "Player.h"

class GameOverScene : public Scene {
private:
	//Atributos de la clase GameOverScene
	Player* player;

	//M�TODO PRIVADO QUE GESTIONA EL FINAL DE LA ESCENA PERDER EL JUEGO
	void Finalizar();

public:
	//Constructor de la clase GameOverScene
	GameOverScene(SceneManager* scMgr, Player* player):Scene(scMgr), player(player){};

	//M�TODOS DE GESTI�N DE LA INICIALIZACI�N Y ACTUALIZACI�N DE LA ESCENA
	void Init();
	void Update(const float& time);
	void Clean();

	//M�TODOS DE PROCESAMIENTO DE TECLAS
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
	void ProcessKeyUp(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
};