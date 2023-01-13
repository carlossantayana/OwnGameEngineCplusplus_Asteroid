#include "Scene.h"
#include "Cuboid.h"

void Scene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

void Scene::CheckBoundary() {
	for (int i = 0; i < gameObjects.size(); i++) {
		//SI SE PASA EN LA X POR LA DERECHA
		if (gameObjects[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX()) {
			gameObjects[i]->SetPos(Vector3D(-11.0,gameObjects[i]->GetPos().GetCoordinateY(),gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA X POR LA IZQUIERDA
		if (gameObjects[i]->GetPos().GetCoordinateX() < -11.0) {
			gameObjects[i]->SetPos(Vector3D(boundary.GetCoordinateX()-0.01,gameObjects[i]->GetPos().GetCoordinateY(),gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ARRIBA
		if (gameObjects[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY()) {
			gameObjects[i]->SetPos(Vector3D(gameObjects[i]->GetPos().GetCoordinateX(),-6.5,gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ABAJO
		if (gameObjects[i]->GetPos().GetCoordinateY() < -6.5) {
			gameObjects[i]->SetPos(Vector3D(gameObjects[i]->GetPos().GetCoordinateX(),boundary.GetCoordinateY()-0.01,gameObjects[i]->GetPos().GetCoordinateZ()));
		}
	}
}

void Scene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));
}

void Scene::Render() {
	this->camera.Render();

	for (int i = 0; i < getGameObjects().size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
	}
	CheckBoundary();
}