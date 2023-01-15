#pragma once
#include "Scene.h"
#include "Player.h"
#include "Text.h"

class GameScene : public Scene
{
private:
	Player* player;
	Vector3D boundary;
	int gameLevel;

	Text* textScore;
	Text* textLifes;


	void Create();
	void CheckBoundary();

public:
	GameScene(SceneManager* scMgr, int level) :boundary(Vector3D(19.0, 13.0, 4.0)), gameLevel(level), player(player), Scene(scMgr) {}

#pragma region Scene
	void Update(const float& time);
	void Init();
	void Render();

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
	void deleteObject(Solid* object);
};

