#include "GameScene.h"
#include "Text.h"
#include "Asteroid.h"
#include <string>

void GameScene::Create() 
{
	//switch (gameLevel) {
		//case 1:
			//CREACIÓN DE OBJETOS
			ModelLoader* loader = new ModelLoader();

			//Modelos Importados
			Model* naveModel = new Model();
			Model* asteroidModel1 = new Model();
			Model* asteroidModel2 = new Model();
			Model* asteroidModel3 = new Model();

			Text* textLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "LEVEL 1");

			//Configuracion Texto
			this->textScore = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "----");
			this->textLifes = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "----");

			//Configuracion Nave Espacial
			loader->setScale(0.25);
			loader->loadModel("..\\SpaceShip2.obj");
			*naveModel = loader->getModel();

			naveModel->SetPos(Vector3D(1.0, 1.0, 1));
			naveModel->paintColor(Color(1.0, 0.5, 0.6));
			naveModel->SetOrientation(Vector3D(0, 0, 0));
			naveModel->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
			naveModel->SetSpeed(Vector3D(0.0, 0.0, 0.0));
			loader->clear();

			this->player = new Player(naveModel, Vector3D(1, 0, 0));

			//Configuracion Asteroides
			loader->setScale(0.05);
			loader->loadModel("..\\AsteroidModel1.obj");
			*asteroidModel1 = loader->getModel();

			asteroidModel1->SetPos(Vector3D(-3.0, -2.0, 1.0));
			asteroidModel1->paintColor(Color(0.8, 0.8, 0.9));
			asteroidModel1->SetOrientation(Vector3D(rand(), rand(), rand()));
			asteroidModel1->SetOrientationSpeed(Vector3D(0.1, 0.15, 0.2));
			asteroidModel1->SetSpeed(Vector3D(0.01, 0.02, 0.0));
			loader->clear();

			Asteroid* asteroide1 = new Asteroid(asteroidModel1);

			loader->setScale(0.05);
			loader->loadModel("..\\AsteroidModel2.obj");
			*asteroidModel2 = loader->getModel();

			asteroidModel2->SetPos(Vector3D(15.0, 11.0, 1.0));
			asteroidModel2->paintColor(Color(0.8, 0.8, 0.9));
			asteroidModel2->SetOrientation(Vector3D(rand(), rand(), rand()));
			asteroidModel2->SetOrientationSpeed(Vector3D(0.1, 0.2, 0.15));
			asteroidModel2->SetSpeed(Vector3D(0.02, 0.01, 0.0));
			loader->clear();

			Asteroid* asteroide2 = new Asteroid(asteroidModel2);

			loader->setScale(0.05);
			loader->loadModel("..\\AsteroidModel3.obj");
			*asteroidModel3 = loader->getModel();

			asteroidModel3->SetPos(Vector3D(2.0, 2.0, 1.0));
			asteroidModel3->paintColor(Color(0.8, 0.8, 0.9));
			asteroidModel3->SetOrientation(Vector3D(rand(), rand(), rand()));
			asteroidModel3->SetOrientationSpeed(Vector3D(0.2, 0.15, 0.1));
			asteroidModel3->SetSpeed(Vector3D(0.01, 0.01, 0.0));
			loader->clear();

			Asteroid* asteroide3 = new Asteroid(asteroidModel3);

			loader->setScale(0.05);
			loader->loadModel("..\\AsteroidModel3.obj");
			*asteroidModel3 = loader->getModel();

			asteroidModel3->SetPos(Vector3D(13, 2.0, 1.0));
			asteroidModel3->paintColor(Color(0.8, 0.8, 0.9));
			asteroidModel3->SetOrientation(Vector3D(rand(), rand(), rand()));
			asteroidModel3->SetOrientationSpeed(Vector3D(0.2, 0.15, 0.1));
			asteroidModel3->SetSpeed(Vector3D(0.01, 0.01, 0.0));
			loader->clear();

			Asteroid* asteroide4 = new Asteroid(asteroidModel3);

			//INSERCIÓN DE OBJETOS EN LA ESCENA
			AddGameObject(this->player->GetPlayerModel());

			AddGameObject(this->textLifes);
			AddGameObject(this->textScore);
			AddGameObject(textLevel);

			AddGameObject(asteroidModel1);
			AddGameObject(asteroidModel2);
			AddGameObject(asteroidModel3);
	//}
}


void GameScene::CheckBoundary() {
	for (int i = 0; i < getGameObjects().size(); i++) {
		//SI SE PASA EN LA X POR LA DERECHA
		if (getGameObjects()[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX()) {
			getGameObjects()[i]->SetPos(Vector3D(-11.0, getGameObjects()[i]->GetPos().GetCoordinateY(), getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA X POR LA IZQUIERDA
		if (getGameObjects()[i]->GetPos().GetCoordinateX() < -11.0) {
			getGameObjects()[i]->SetPos(Vector3D(boundary.GetCoordinateX() - 0.01, getGameObjects()[i]->GetPos().GetCoordinateY(), getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ARRIBA
		if (getGameObjects()[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY()) {
			getGameObjects()[i]->SetPos(Vector3D(getGameObjects()[i]->GetPos().GetCoordinateX(), -6.5, getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ABAJO
		if (getGameObjects()[i]->GetPos().GetCoordinateY() < -6.5) {
			getGameObjects()[i]->SetPos(Vector3D(getGameObjects()[i]->GetPos().GetCoordinateX(), boundary.GetCoordinateY() - 0.01, getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
	}
}

void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->player->ProcessKeyPressed(key, px, py);
	cout << "Tecla pulsada: " << key << endl;
}

void GameScene::ProcessKeyUp(unsigned char key, int px, int py) {

	if (key == 0x1B)
	{
		//ESCAPE
		sceneManager->SetPause();
		return;
	}

	if (key == 'o') {
		//como si hubiese ganado
		this->restoreScene();
		sceneManager->SetNextScene();
	}
	if (key == 'p') {

		//como si hubiese perdido
		this->restoreScene();
		sceneManager->SetGameOverScene();
	}

	if (key == '4') {
		player->Shoot();
		AddGameObject(player->GetBullet());
	}

	
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
	player->UpdateBullet();

	if (player->GetDeleteBullet()) {
		deleteObject(player->GetBullet());
	}

	this->textScore->setText(to_string((this->player->GetScore())));

	for (int i = 0; i < getGameObjects().size(); i++) {
		getGameObjects()[i]->Update(time);
		Collisions();
	}
	CheckBoundary();
}

void GameScene::Init() {
	setCamera(Camera(Vector3D(4.0, 3.0, 12.0)));
	Create();

	//TODO: Actualizar los datos iniciales del player ... coordenadas
	//TODO: arreglar la creación devarios asteroides. 
}

void GameScene::Render() {
	Scene::Render();
	
	for (int i = 0; i < getGameObjects().size(); i++) {
		this->getGameObjects()[i]->Render();
	}
}


bool GameScene::Collisions() {
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

	//Nave objeto 0 y asteroide el 2

	sumaRadios = 1.43; //ejemplo
	distancia = getGameObjects()[0]->GetPos().distance2D(getGameObjects()[2]->GetPos());
	cout << "DISTANCIA ACTUAL:" << distancia << endl;
	if (distancia < sumaRadios) {
		cout << "Colision" << endl;
		return true;
	}
}

void GameScene::deleteObject(Solid* object) {
	player->SetDeleteBullet(false);
	//it se igualara con el puntero que coincida con el buscado
	vector<Solid*>::iterator it = find(this->getGameObjects().begin(), this->getGameObjects().end(), object);
	//elimina de la lista el objeto encontrado
	if (it != getGameObjects().end()) {
		getGameObjects().erase(it);
		//elimina el puntero;
		delete* it;
	}
	else {
		cout << "No se puede eliminar el objeto." << endl;
	}

}