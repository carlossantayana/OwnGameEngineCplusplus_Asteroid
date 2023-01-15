#include "Scene.h"

void Scene::Render() {
	this->camera.Render();
}

void Scene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

void Scene::restoreScene(){
	for(Solid* gameObject:this->gameObjects){
		delete gameObject;
	}
	gameObjects.clear();
}