#pragma once
#include "Solid.h"
#include "Model.h"

class Asteroid {
private:
	///////////////////ATRIBUTOS DE LA CLASE ASTEROID///////////////////////////////
	Model* model;
	int score;

public:
	//CONSTRUCTOR DE ASTEROID
	Asteroid(Model* model, int score) : model(model), score(score){}

	//SETTERS
	void setModel(Model* modelToSet) { model = modelToSet; }

	//GETTERS
	inline int getScore() const { return this->score; }
	inline Model* getModel() const { return this->model; }
};

