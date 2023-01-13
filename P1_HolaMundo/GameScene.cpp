#include "GameScene.h"

void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->player->ProcessKeyPressed(key, px, py);
	cout << "Tecla pulsada: " << key << endl;
}

void GameScene::ProcessKeyUp(unsigned char key, int px, int py) {
    this->player->ProcessKeyUp(key, px, py);
	cout << "Tecla soltada: " << key << endl;
}

void GameScene::ProcessMouseMovement(int x, int y) {
	this->player->ProcessMouseMovement(x, y);
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void GameScene::ProcessMouseClick(int button, int state, int x, int y) {
	this->player->ProcessMouseClick(button, state, x, y);
	cout << "Click" << endl;
}

void GameScene::Update(const float& time) {
    player->UpdatePlayer();
	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
		collisions();
	}
	CheckBoundary();
}

bool GameScene::collisions() {
	float distancia;
	float sumaRadios;

	////Compruebo la colision de los objetos  
	//for (Solid* p : gameObjects) {
	//	for (Solid* p2 : gameObjects) {
	//		//Calculo la suma de sus radios
	//		sumaRadios = 0.5; //ejemplo

	//		//Calculo la distancia entre los centros.
	//		distancia = p->GetPos().distance2D(p2->GetPos());

	//		if (distancia < sumaRadios) {
	//			cout << "Colision" << endl;
	//			return true;
	//		}
	//	}
	//}

	//return false;

	//Nave objeto 4 y asteroide el 6

	sumaRadios = 1.43; //ejemplo
	distancia = getGameObjects()[0]->GetPos().distance2D(getGameObjects()[2]->GetPos());
	cout << "DISTANCIA ACTUAL:" << distancia << endl;
	if (distancia < sumaRadios) {
		cout << "Colision" << endl;
		return true;
	}
}