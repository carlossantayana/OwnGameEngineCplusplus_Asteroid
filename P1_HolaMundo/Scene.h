#pragma once
#include <vector>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Camera.h"
using namespace std;
class Scene
{
private:
	Camera camera;
	vector <Solid*> gameObjects;

public:
	Scene(){}

	void Init();
	void Render();
	void Update();

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};

