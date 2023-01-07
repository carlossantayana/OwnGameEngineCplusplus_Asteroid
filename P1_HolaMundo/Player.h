#pragma once
#include "Model.h"

class Player 
{
private:
	Model* playerModel;
	Vector3D Orientation;
	float speed;
	float rotationSpeed;

public:
	Player(Model* playerModelArgument, Vector3D orientationToSet) : playerModel(playerModelArgument), speed(0.1), rotationSpeed(10) , Orientation(orientationToSet) {}

	//Getters
	inline Model* GetPlayerModel() const {
		return this->playerModel;
	}

	//Setters
	inline void SetPlayerModel(Model* playerModelToSet) {
		this->playerModel = playerModelToSet;
	}

	void ProcessKeyPressed(unsigned char key, unsigned char keyState[], int px, int py);
	void ProcessKeyUp(unsigned char key, unsigned char keyState[], int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	Vector3D RotateVector(Vector3D vector, float angle);
};

