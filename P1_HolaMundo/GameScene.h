#pragma once
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Text.h"

class GameScene : public Scene
{
private:
	bool kk=false;



	Player* player;
	vector <Bullet*> bullets;
	vector <Asteroid*> asteroids;
	

	Vector3D boundary;
	int gameLevel;

	Text* textScore;
	Text* textLifes;


	void CreateAsteroids();
	void CheckBoundary();
	
	//Chequeamos la intersección de las bullets con los enemigos
	void CheckBulletsCollisions();
	bool CheckBulletCollision(Bullet*, Asteroid*);

	//Chequeamos la intersección del juagador con los enemigos
	void CheckPlayerCollisions();
	bool CheckPlayerCollision(Asteroid* asteroid);


	Model* AsteroidModel1(ModelLoader* loader);
	Model* AsteroidModel2(ModelLoader* loader);
	Model* AsteroidModel3(ModelLoader* loader);

	void DecLifePlayer();
	void IncScorePlayer(int inc);

public:
	GameScene(SceneManager* scMgr, Player* player, int level) :boundary(Vector3D(20, 10, 10)), gameLevel(level), player(player), Scene(scMgr) {}

#pragma region Scene
	void Update(const float& time);
	void Init();
	void Clean();

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
	void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón
#pragma endregion


	inline Player* getPlayer() { return player; }
	inline void setPlayer(Player* playerArgument) { player = playerArgument; }
	inline Vector3D getBoundary() const { return this->boundary; }
	inline void setBoundary(const Vector3D& boundaryToSet) { this->boundary = boundaryToSet; }

	bool Collisions();
	//void CleanScene();
};

