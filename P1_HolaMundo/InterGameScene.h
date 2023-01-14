#pragma once
#include "TextScene.h"
#include "Player.h"

class InterGameScene : public TextScene
{
protected:
#pragma region TextScene
	void Finalizar();
#pragma endregion
public:
	InterGameScene(SceneManager* scMgr, Player* player, int level);
};

