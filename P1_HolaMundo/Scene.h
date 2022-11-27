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
	Teapot* teapot1;
	Teapot* teapot2;
	Sphere* sphere;
	Cube* cube;
	Vector3D boundary;


public:
	Scene() : boundary(Vector3D(8.0, 6.0, 4.0))
	{
		teapot1 = new Teapot(Vector3D(3.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.001, 0.002, 0.003), 0.4);
		teapot2 = new Teapot(Vector3D(2.5, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(90.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.001), 0.4);
		cube = new Cube(Vector3D(4.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.002), 0.4);
		sphere = new Sphere(Vector3D(5.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.008, 0.002, 0.001), 0.4, 20, 20);
	}

	void Init();
	void Render();
	void Update();
	void CheckBoundary();


	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
};

