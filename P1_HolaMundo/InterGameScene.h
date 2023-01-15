#pragma once
#include "Scene.h"
#include "Player.h"
#include "Text.h"

class InterGameScene : public Scene {
private:
	////////////////ATRIBUTOS///////////////////
	Player* player;
	int gameLevel;

	/////////////////////////////MÉTODOS PRIVADOS QUE GESTIONAN LA ESCENA ENTRE NIVELES//////////////////////////////////////
	void Finalizar();
public:
	//CONSTRUCTOR DE INTERGAMESCENE
	InterGameScene(SceneManager* scMgr, int level, Player* player): Scene(scMgr) , gameLevel(level), player(player){};

	//INICIALIZACIÓN Y ACTUALIZACIÓN DE LA ESCENA
	void Init();
	void Update(const float& time);

	//PROCESAMIENTO DE TECLAS
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón

	
};

