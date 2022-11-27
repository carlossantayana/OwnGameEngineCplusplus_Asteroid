#pragma once
#include <vector>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
using namespace std;
class Scene
{
private:
	Camera camera;
	vector <Solid*> gameObjects;
	Teapot* teapot1;
	Teapot* teapot2;
	Sphere* sphere;
	Cube* cube;
	Vector3D boundary;
	ModelLoader* loader;
	Model* heart;


	void CheckBoundary();
public:
	Scene() : boundary(Vector3D(8.0, 6.0, 4.0)) {}

	void Init();
	void Render();
	void Update();

	inline Teapot getTeapot1() { return *teapot1; }
	inline Teapot getTeapot2() { return *teapot2; }
	inline Cube getCube() { return *cube; }
	inline Sphere getSphere() { return *sphere; }

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n
};

