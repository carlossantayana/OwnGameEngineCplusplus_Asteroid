#pragma once
#include "Model.h"

class Player 
{
private:
	Model* playerModel;
	Vector3D Orientation;
	float speed;
	float rotationSpeed;

	bool wPressed;
	bool aPressed;
	bool dPressed;

public:
	Player(Model* playerModelArgument, Vector3D orientationToSet) : playerModel(playerModelArgument), speed(0.0), rotationSpeed(10.0) , Orientation(orientationToSet), wPressed(false), aPressed(false), dPressed(false) {}

	//Getters
	inline Model* GetPlayerModel() const {
		return this->playerModel;
	}

	//Setters
	inline void SetPlayerModel(Model* playerModelToSet) {
		this->playerModel = playerModelToSet;
	}

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	Vector3D RotateVector(Vector3D vector, float angle);
	void UpdatePlayer();


	//Datos de partida
	void InicializarDatosPartida();
	int puntuacion;
	int vidas;

};

