#pragma once
#include "Scene.h"
#include "Text.h"
#include "Player.h"
class EndGameScene : public Scene
{
private:
	Player* player;
	
	void Finalizar();
public:
	EndGameScene(SceneManager* scMgr, Player* player): Scene(scMgr), player(player) {};

	void Init();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón


	void Update(const float& time);
};

