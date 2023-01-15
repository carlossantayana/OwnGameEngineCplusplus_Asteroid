#include "Scene.h"

//MÉTODO DE RENDERIZADO COMPARTIDO POR TODAS LAS ESCENAS
void Scene::Render() {
	this->camera.Render();

	for (int i = 0; i < getGameObjects().size(); i++) {
		this->getGameObjects()[i]->Render();
	}
}

//PERMITE AÑADRIR OBJETOS A LA ESCENA
void Scene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

//BORRA UN OBJETO DE LA ESCENA
void Scene::DeleteGameObject(Solid* object) {
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
}

//REESTABLECE LA ESCENA, ELIMINANDO TODOS SUS OBJETOS Y LIMPIANDO EL VECTOR GAMEOBJECTS
void Scene::RestoreScene(){
	for(Solid* gameObject:this->gameObjects){
		delete gameObject;
	}
	gameObjects.clear();
}