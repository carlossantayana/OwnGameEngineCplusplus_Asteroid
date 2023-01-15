#pragma once
#include "Scene.h"
#include "Text.h"
#include "Player.h"

class GameOverScene : public Scene {
private:
	//Atributos de la clase GameOverScene
	Player* player;

	//MÉTODO PRIVADO QUE GESTIONA EL FINAL DE LA ESCENA PERDER EL JUEGO
	void Finalizar();

public:
	//Constructor de la clase GameOverScene
	GameOverScene(SceneManager* scMgr, Player* player):Scene(scMgr), player(player){};

	//MÉTODOS DE GESTIÓN DE LA INICIALIZACIÓN Y ACTUALIZACIÓN DE LA ESCENA
	void Init();
	void Update(const float& time);
	void Clean();

	//MÉTODOS DE PROCESAMIENTO DE TECLAS
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
	void ProcessKeyUp(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
};