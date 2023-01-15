#pragma once
#include "Scene.h"
#include "Text.h"

class TitleScene : public Scene 
{
public:
	TitleScene(SceneManager* scMgr) :Scene(scMgr) {}
#pragma region Scene
	void Update(const float& time);
	void Init();

	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
#pragma endregion
};