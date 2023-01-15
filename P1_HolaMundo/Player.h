#pragma once
#include "Model.h"
#include "Sphere.h"
#include "Bullet.h"

class Player 
{
private:
	//Atributos del jugador
	Model* playerModel; //Modelo 3D que lo representa

	Vector3D Orientation; //Orientación del personaje del jugador en el espacio. Se usará para determinar la dirección de movimiento.

	float speed; //Velocidad con la que se mueve
	float rotationSpeed; //Velocidad con la que rota

	//Booleanos que permiten un movimiento fluido del jugador
	//Se mueve cuando se activan y no cuando se detectan las pulsaciones
	//Se evita el delay inicial al mantener una tecla provocado por el S.O.
	bool wPressed;
	bool aPressed;
	bool dPressed;
	
	int score=0; //Puntuación obtenida, se inicializa a 0.
	int lifesNum=0; //Número de vidas, se inicialiaz a 0.
	

public:
	//Constructor de jugadores
	Player(Model* playerModelArgument, Vector3D orientationToSet) : 
		playerModel(playerModelArgument), speed(0.0), rotationSpeed(10.0), Orientation(orientationToSet), wPressed(false), aPressed(false), dPressed(false) 
	{}

	//Método de rotación de vectores. Permite cambiar la orientación del jugador y moverlo en esa dirección.
	Vector3D RotateVector(Vector3D vector, float angle);

	//Actualiza al jugador cuando estén presionados las teclas w, a o d. Mueve y rota al jugador cuando deba hacerlo.
	void UpdatePlayer();

	//Pedimos al Jugador que construya un nuevo bullet para incluirlo en la escena
	Bullet* Shoot();

	//Procesamiento de teclas para el movimiento del jugador
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

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
	inline void SetAPressed(bool boolArgument) {
		this->aPressed = boolArgument;
	}
	inline void SetDPressed(bool boolArgument) {
		this->dPressed = boolArgument;
	}
	inline void SetWPressed(bool boolArgument) {
		this->wPressed = boolArgument;
	}
	inline void SetSpeed(float speedArgument) {
		this->speed = speedArgument;
	}
};