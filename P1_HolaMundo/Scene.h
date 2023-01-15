#pragma once
#include <vector>
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
	///////////////////ATRIBUTOS DE LA CLASE SCENE///////////////////////////////
	Camera camera;
	vector <Solid*> gameObjects;

protected:
	//////////////////ESTE ATRIBUTO PERMITE GESTIONAR LOS CAMBIOS DE LA ESCENA ACTIVA//////////////////////////////
	SceneManager* sceneManager;

public:
	//CONSTRUCTOR DE LA CLASE SCENE
	Scene(SceneManager* scMgr) : sceneManager(scMgr) {}

	//GESTIÓN DE ESCENAS
    virtual void Init() = 0;
	virtual void Render();
	virtual void Update(const float& time) = 0;
	//Nuevo método para permitir a las escenas limpiar objetos
	virtual void Clean(){};
	
	//MÉTODOS DE CONTROL DE LOS OBJETOS DE UNA ESCENA
	void AddGameObject(Solid* gameObject);
	void DeleteGameObject(Solid* object);
	void RestoreScene();

	//PROCESAMIENTO DE TECLAS
	virtual void ProcessKeyPressed(unsigned char key, int px, int py) {} //Recoger info de pulsación de teclas
	virtual void ProcessKeyUp(unsigned char key, int px, int py) {};
	virtual void ProcessMouseMovement(int x, int y) {}; //Recoger info de movimiento del ratón
	virtual void ProcessMouseClick(int button, int state, int x, int y) {}; //Recoger info de pulsación del ratón

	//GETTERS
	inline Camera getCamera() const { return this->camera; }
	inline vector<Solid*> getGameObjects() { return this->gameObjects; }

	//SETTERS
	inline void setCamera(const Camera& cameraToSet) { this->camera = cameraToSet; }
	inline void setGameObjects(const vector<Solid*>& gameObjectsToSet) { this->gameObjects = gameObjectsToSet; }
};