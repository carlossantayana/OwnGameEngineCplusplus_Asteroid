#pragma once
#include "Scene.h"

class TitleScene : public Scene 
{
protected:
	bool pulsado = FALSE;
public:
	TitleScene(SceneManager* scMgr) :Scene(scMgr) {}
#pragma region Scene
	void Update(const float& time);
	void Init();
	void Render();

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
#pragma endregion
};