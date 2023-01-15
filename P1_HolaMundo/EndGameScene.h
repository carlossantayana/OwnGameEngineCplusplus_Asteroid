#pragma once
#include "Scene.h"
#include "Text.h"
class EndGameScene : public Scene
{
private:
	string text;
	Text* textLevel;
	
public:
	EndGameScene(SceneManager* scMgr, string text): text(text), Scene(scMgr){};

	void Init();
	void Render();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n

	void Finalizar();

	void setText(const string& textToSet) { text = textToSet; }

	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
};

