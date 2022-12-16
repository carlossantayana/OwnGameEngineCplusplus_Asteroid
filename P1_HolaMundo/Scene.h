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

	//agregado
	//bool drawVertexes;
	//bool drawBox;
	//agregado

	void CheckBoundary();
public:
	Scene() : boundary(Vector3D(8.0, 6.0, 4.0)) /*, drawVertexes(false), drawBox(false)*/ {}

	void Init();
	void Render();
	void Update();

	void AddGameObject(Solid* gameObject);

	inline Vector3D getBoundary() const { return this->boundary; }
	inline void setBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }

	/*inline bool getDrawVertexes() const { return this->drawVertexes; }
	inline void setDrawVertexes(const bool& drawVertexesToSet) { this->drawVertexes = drawVertexesToSet; }
	inline bool getDrawBox() const { return this->drawBox; }
	inline void setDrawBox(const bool& drawBoxToSet) { this->drawBox = drawBoxToSet; }*/
	
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
};

