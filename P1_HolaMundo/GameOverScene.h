#pragma once
#include "TextScene.h"

class GameOverScene : public TextScene
{
protected:
#pragma region TextScene
	void Finalizar();
#pragma endregion
public:
	GameOverScene(SceneManager* scMgr) :TextScene(scMgr, "Estas Muerto") {}
};