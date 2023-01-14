#pragma once
#include "TextScene.h"
class EndGameScene : public TextScene
{
protected:
#pragma region TextScene
	void Finalizar();
#pragma endregion
public:
	EndGameScene(SceneManager* scMgr) :TextScene(scMgr, "Fin de Partida") {}
};

