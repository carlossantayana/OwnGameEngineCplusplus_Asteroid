#pragma once
#include "Scene.h"
#include "Player.h"
#include "Text.h"

class InterGameScene : public Scene {
private:
	Player* player;
	int gameLevel;

	void Finalizar();
public:
	InterGameScene(SceneManager* scMgr, int level, Player* player): Scene(scMgr) , gameLevel(level), player(player){};

	void Init();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón

	void Update(const float& time);
};

