#pragma once
#include "Scene.h"
#include "Player.h"
class GameScene : public Scene
{
private:
	Player* player;

public:
	GameScene(Player* playerArgument/*, Game* gameArgument*/) :Scene(/*gameArgument*/), player(playerArgument) {}

	void Update(const float& time);

	void ProcessKeyPressed(unsigned char key, int px, int py); //Recoger info de pulsación de teclas
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y); //Recoger info de movimiento del ratón
    void ProcessMouseClick(int button, int state, int x, int y); //Recoger info de pulsación del ratón

	inline Player* getPlayer() { return player; }
	inline void setPlayer(Player* playerArgument) { player = playerArgument; }

	bool collisions();
};

