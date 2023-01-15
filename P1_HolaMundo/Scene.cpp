#include "Scene.h"

void Scene::Render() {
	this->camera.Render();
}

void Scene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

void Scene::RestoreScene(){
	for(Solid* gameObject:this->gameObjects){
		delete gameObject;
	}
	gameObjects.clear();
}

void Scene::DeleteGameObject(Solid* object) {
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), object), gameObjects.end());
}