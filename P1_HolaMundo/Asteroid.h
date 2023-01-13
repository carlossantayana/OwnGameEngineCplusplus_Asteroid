#pragma once
#include "Solid.h"
#include "Model.h"

class Asteroid {
private:

	Model* model;
	//float radio;
	bool separado;

public:

	Asteroid(Model* model) : model(model) {}
	void setModel(Model* modelToSet) { model = modelToSet; }

};

