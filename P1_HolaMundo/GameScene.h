#pragma once
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Text.h"

class GameScene : public Scene
{
private:
	////////////////ATRIBUTOS///////////////////
	Player* player;
	vector <Bullet*> bullets;
	vector <Asteroid*> asteroids;
	
	Vector3D boundary;

	int gameLevel;

	Text* textScore;
	Text* textLifes;
	///////////////////////////////////////////

	/////////////////////////////MÉTODOS PRIVADOS QUE GESTIONAN LA ESCENA DEL JUEGO//////////////////////////////////////

	//Comprobación de límites del escenario de juego
	void CheckBoundary();
	
	//Chequeamos la intersecci�n de las bullets con los enemigos
	void CheckBulletsCollisions();
	bool CheckBulletCollision(Bullet*, Asteroid*);

	//Chequeamos la intersecci�n del juagador con los enemigos
	void CheckPlayerCollisions();
	bool CheckPlayerCollision(Asteroid* asteroid);

	//Creación de los asteroides
	Model* AsteroidModel1(ModelLoader* loader);
	Model* AsteroidModel2(ModelLoader* loader);
	Model* AsteroidModel3(ModelLoader* loader);
	void CreateAsteroids();

	//Métodos de control de vida y puntuación
	void DecLifePlayer();
	void IncScorePlayer(int inc);

public:
	//CONSTRUCTOR DE ESCENAS DE NIVELES DEL JUEGO
	GameScene(SceneManager* scMgr, Player* player, int level) :boundary(Vector3D(20, 10, 10)), gameLevel(level), player(player), Scene(scMgr) {}

	//INICIALIZACIÓN, ACTUALIZACIÓN Y BORRADO DE LA ESCENA
	void Init();
	void Update(const float& time);
	void Clean();

	//PROCESAMIENTO DE TECLAS
	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsaci�n de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del rat�n
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsaci�n del rat�n

	//GETTERS
	inline Player* getPlayer() { return player; }
	inline Vector3D getBoundary() const { return this->boundary; }

	//SETTERS
	inline void setPlayer(Player* playerArgument) { player = playerArgument; }
	inline void setBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }
};

