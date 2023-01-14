#include "GameScene.h"
#include "Text.h"
#include "Asteroid.h"

void GameScene::Create() 
{
	//TODO: Tendriamos que crear los datos del juego en función del nivel

	//CREACIÓN DE OBJETOS
	ModelLoader* loader = new ModelLoader();

	//Modelos Importados
	Model* asteroidModel1 = new Model();
	Model* asteroidModel2 = new Model();
	Model* asteroidModel3 = new Model();

	//TODO:
	//Text textoLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "LEVEL " + levelGame);
	Text *textoLevel = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "LEVEL 1");

	//Configuracion Texto
	this->textoPoints = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "----");
	this->textoVidas = new Text(Vector3D(-6.0, 8.4, 2.0), Color(255.0, 255.0, 255.0), "----");

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
	AddGameObject(player->GetPlayerModel());

	AddGameObject(this->textoVidas);
	AddGameObject(this->textoPoints);
	AddGameObject(textoLevel);

	AddGameObject(asteroidModel1);
	AddGameObject(asteroidModel2);
	AddGameObject(asteroidModel3);

	delete loader;
}

void GameScene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

void GameScene::CheckBoundary() {
	for (int i = 0; i < gameObjects.size(); i++) {
		//SI SE PASA EN LA X POR LA DERECHA
		if (gameObjects[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX()) {
			gameObjects[i]->SetPos(Vector3D(-11.0, gameObjects[i]->GetPos().GetCoordinateY(), gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA X POR LA IZQUIERDA
		if (gameObjects[i]->GetPos().GetCoordinateX() < -11.0) {
			gameObjects[i]->SetPos(Vector3D(boundary.GetCoordinateX() - 0.01, gameObjects[i]->GetPos().GetCoordinateY(), gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ARRIBA
		if (gameObjects[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY()) {
			gameObjects[i]->SetPos(Vector3D(gameObjects[i]->GetPos().GetCoordinateX(), -6.5, gameObjects[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ABAJO
		if (gameObjects[i]->GetPos().GetCoordinateY() < -6.5) {
			gameObjects[i]->SetPos(Vector3D(gameObjects[i]->GetPos().GetCoordinateX(), boundary.GetCoordinateY() - 0.01, gameObjects[i]->GetPos().GetCoordinateZ()));
		}
	}
}

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

	//Actualizas puntuación
	//TODO: this->textoPoints->setText(this->player->puntuacion);

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
}

void GameScene::Render() {

	Scene::Render();
	//this->camera.Render();

	for (int i = 0; i < getGameObjects().size(); i++) {
		gameObjects[i]->Render();
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

	//Nave objeto 4 y asteroide el 6

	sumaRadios = 1.43; //ejemplo
	distancia = getGameObjects()[0]->GetPos().distance2D(getGameObjects()[2]->GetPos());
	cout << "DISTANCIA ACTUAL:" << distancia << endl;
	if (distancia < sumaRadios) {
		cout << "Colision" << endl;
		return true;
	}
}