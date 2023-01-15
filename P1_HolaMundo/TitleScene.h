#pragma once
#include "Scene.h"
#include "Text.h"

class TitleScene : public Scene 
{
public:
	//CONSTRUCTOR DE TITLESCENE
	TitleScene(SceneManager* scMgr) :Scene(scMgr) {}

	//INICIALIZACI�N Y ACTUALIZACI�N DE LA ESCENA
	void Init();
	void Update(const float& time);
	
	//PROCESAMIENTO DE TECLAS
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};