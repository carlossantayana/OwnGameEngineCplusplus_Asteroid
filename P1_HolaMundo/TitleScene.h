#pragma once
#include "Scene.h"
#include "Text.h"

class TitleScene : public Scene 
{
protected:
	//TODO: Mirar si poner en un Vector
	Text* opcion1;
	Text* opcion2;


public:
	TitleScene(SceneManager* scMgr) :Scene(scMgr) {}
#pragma region Scene
	void Update(const float& time);
	void Init();
	void Render();

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
#pragma endregion
};