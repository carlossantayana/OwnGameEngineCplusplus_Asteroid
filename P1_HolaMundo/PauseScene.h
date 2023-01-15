#pragma once
#include "Scene.h"
#include "Text.h"

class PauseScene : public Scene
{
private:
	string text;
	Text* textLevel;

public:
	PauseScene(SceneManager* scMgr, string text) : Scene(scMgr), text(text) {}

	void Init();
	void Render();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón

	void Finalizar();

	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
};

