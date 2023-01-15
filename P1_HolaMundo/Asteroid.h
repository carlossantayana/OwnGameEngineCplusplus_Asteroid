#pragma once
#include "Solid.h"
#include "Model.h"

class Asteroid {
private:
	Model* model;
	int score;
public:

	Asteroid(Model* model, int score) : model(model), score(score){}
	void setModel(Model* modelToSet) { model = modelToSet; }

	inline int getScore() const { return this->score; }
	inline Model* getModel() const { return this->model; }

};

