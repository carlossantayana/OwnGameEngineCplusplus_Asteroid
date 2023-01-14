#pragma once
#include "TextScene.h"
class PauseScene : public TextScene
{
protected:
#pragma region TextScene
	void Finalizar();
#pragma endregion
public:
	PauseScene(SceneManager* scMgr) :TextScene(scMgr, "Pausa") {}
};

