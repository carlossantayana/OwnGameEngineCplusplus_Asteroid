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
	Vector3D boundary;

	//Game* game;

protected:
	void CheckBoundary();

public:
	Scene(/*Game* gameArgument*/) : boundary(Vector3D(19.0, 13.0, 4.0))/*, game(gameArgument)*/ {}

    void Init();
	void Render();
	virtual void Update(const float& time);
	
	virtual void ProcessKeyPressed(unsigned char key, int px, int py) = 0; //Recoger info de pulsación de teclas
	virtual void ProcessKeyUp(unsigned char key, int px, int py) = 0;
	virtual void ProcessMouseMovement(int x, int y) = 0; //Recoger info de movimiento del ratón
	virtual void ProcessMouseClick(int button, int state, int x, int y)= 0; //Recoger info de pulsación del ratón

	void AddGameObject(Solid* gameObject);

	inline Vector3D getBoundary() const { return this->boundary; }
	inline Camera getCamera() const { return this->camera; }
	inline vector<Solid*> getGameObjects() { return this->gameObjects; }

	inline void setBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
	inline void setCamera(const Camera& cameraToSet) { this->camera = cameraToSet; }
	inline void setGameObjects(const vector<Solid*>& gameObjectsToSet) { this->gameObjects = gameObjectsToSet; }
};