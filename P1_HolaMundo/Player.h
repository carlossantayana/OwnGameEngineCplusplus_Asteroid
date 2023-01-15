#pragma once
#include "Model.h"
#include "Sphere.h"
#include "Bullet.h"

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
	
	int score=0;
	int lifesNum=0;
	

public:
	Player(Model* playerModelArgument, Vector3D orientationToSet) : 
		playerModel(playerModelArgument), speed(0.0), rotationSpeed(10.0), Orientation(orientationToSet), wPressed(false), aPressed(false), dPressed(false) {}


	//Getters
	inline Model* GetPlayerModel() const {
		return this->playerModel;
	}
	inline int GetScore() const {
		return this->score;
	}
	inline int GetLifesNum() const {
		return this->lifesNum;
	}

	//Setters
	inline void SetPlayerModel(Model* playerModelToSet) {
		this->playerModel = playerModelToSet;
	}
	inline void SetScore(int scoreToSet) {
		this->score = scoreToSet;
	}
	inline void SetLifesNum(int lifesNumToSet) {
		this->lifesNum = lifesNumToSet;
	}

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

	Vector3D RotateVector(Vector3D vector, float angle);
	void UpdatePlayer();

	//Pedimos al Jugador que construya un nuevo bullet para incluir en la escena
	Bullet* Shoot();
};

