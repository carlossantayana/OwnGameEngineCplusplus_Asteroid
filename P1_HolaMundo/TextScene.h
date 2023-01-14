#pragma once
#include "Scene.h"
#include "Text.h"

class TextScene : public Scene
{
private:
	string text;
	Text* textoLevel;
protected:
	virtual void Finalizar() = 0;
	void setText(const string& textToSet) { text = textToSet; }
public:
	TextScene(SceneManager* scMgr, string text) : text(text), Scene(scMgr) {}
	TextScene(SceneManager* scMgr) : Scene(scMgr) {}
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