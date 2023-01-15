#pragma once
#include "Scene.h"
#include "Text.h"
#include "Player.h"

class GameOverScene : public Scene {
private:
	Player* player;
	void Finalizar();

public:
	GameOverScene(SceneManager* scMgr, Player* player):Scene(scMgr), player(player){};

#pragma region Scene
	void Init();
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
	void Update(const float& time);
	void ProcessKeyUp(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
#pragma endregion
};