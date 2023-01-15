#pragma once
#include "Scene.h"
#include "Text.h"

class PauseScene : public Scene
{
public:
	PauseScene(SceneManager* scMgr) : Scene(scMgr) {}

	void Init();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n

	void Update(const float& time);
};

