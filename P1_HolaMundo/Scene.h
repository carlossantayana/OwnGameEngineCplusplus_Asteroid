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
	vector <Solid*> gameObjects;

protected:
	SceneManager* sceneManager;

public:
	Scene(SceneManager* scMgr) : sceneManager(scMgr) {}

    virtual void Init() = 0;
	virtual void Render();
	virtual void Update(const float& time) = 0;
	
	//Nuevo método para permitir a las escenas limmpiar objetos
	virtual void Clean() {};
	
	virtual void ProcessKeyPressed(unsigned char key, int px, int py) {} //Recoger info de pulsación de teclas
	virtual void ProcessKeyUp(unsigned char key, int px, int py) {};
	virtual void ProcessMouseMovement(int x, int y) {}; //Recoger info de movimiento del ratón
	virtual void ProcessMouseClick(int button, int state, int x, int y) {}; //Recoger info de pulsación del ratón

	void AddGameObject(Solid* gameObject);
	void DeleteGameObject(Solid* object);
	void RestoreScene();

	inline Camera getCamera() const { return this->camera; }
	inline vector<Solid*> getGameObjects() { return this->gameObjects; }

	inline void setCamera(const Camera& cameraToSet) { this->camera = cameraToSet; }
	inline void setGameObjects(const vector<Solid*>& gameObjectsToSet) { this->gameObjects = gameObjectsToSet; }

};