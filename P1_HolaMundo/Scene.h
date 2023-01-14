#pragma once
#include <vector>
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "SceneManager.h"

using namespace std;
class Scene
{
private:
	Camera camera;

protected:
	SceneManager* sceneManager;

public:
	Scene(SceneManager* scMgr) : sceneManager(scMgr) {}

    virtual void Init() = 0;
	virtual void Render();
	virtual void Update(const float& time) = 0;
	
	virtual void ProcessKeyPressed(unsigned char key, int px, int py) = 0; //Recoger info de pulsación de teclas
	virtual void ProcessKeyUp(unsigned char key, int px, int py) = 0;
	virtual void ProcessMouseMovement(int x, int y) = 0; //Recoger info de movimiento del ratón
	virtual void ProcessMouseClick(int button, int state, int x, int y)= 0; //Recoger info de pulsación del ratón

	inline Camera getCamera() const { return this->camera; }

	inline void setCamera(const Camera& cameraToSet) { this->camera = cameraToSet; }
};