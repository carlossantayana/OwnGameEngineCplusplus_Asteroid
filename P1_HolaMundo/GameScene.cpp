#include "GameScene.h"
#include "Text.h"
#include "Asteroid.h"
#include <math.h>
#include <string>
#include <mmsystem.h>

# define M_PI           3.14159265358979323846

Model* GameScene::AsteroidModel1(ModelLoader* loader)
{
	Model* asteroidModel = new Model();
	loader->setScale(0.02);
	loader->loadModel("..\\AsteroidModel1.obj");
	*asteroidModel = loader->getModel();
	loader->clear();

	double x = rand();
	x /= RAND_MAX;
	x *= boundary.GetCoordinateX();
	double y = rand();
	y /= RAND_MAX;
	y *= boundary.GetCoordinateY();

	asteroidModel->SetPos(Vector3D(x, y, 1.0));
	asteroidModel->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel->SetOrientationSpeed(Vector3D(0.1, 0.15, 0.2));

	float radio = 0.2;
	asteroidModel->SetHitBoxRadius(radio);

	double ang = rand();
	ang /= RAND_MAX;

	ang *= 2 * M_PI;
	//ang = 0;
	double v = 0.005;
	double vx = v * cos(ang);
	double vy = v * sin(ang);
	asteroidModel->SetSpeed(Vector3D(vx, vy, 0.0));

	return asteroidModel;
}
Model* GameScene::AsteroidModel2(ModelLoader* loader)
{
	Model* asteroidModel = new Model();
	loader->setScale(0.01);
	loader->loadModel("..\\AsteroidModel2.obj");
	*asteroidModel = loader->getModel();
	loader->clear();

	float radio = 0.1;
	asteroidModel->SetHitBoxRadius(radio);

	double x = rand();
	x /= RAND_MAX;
	x *= boundary.GetCoordinateX();
	double y = rand();
	y /= RAND_MAX;
	y *= boundary.GetCoordinateY();

	asteroidModel->SetPos(Vector3D(x, y, 1.0));
	asteroidModel->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel->SetOrientationSpeed(Vector3D(0.05, 0.18, 0.22));

	double ang = rand();
	ang /= RAND_MAX;

	ang *= 2 * M_PI;
	//ang = 0;
	double v = 0.006;
	double vx = v * cos(ang);
	double vy = v * sin(ang);
	asteroidModel->SetSpeed(Vector3D(vx, vy, 0.0));

	return asteroidModel;
}
Model* GameScene::AsteroidModel3(ModelLoader* loader)
{
	Model* asteroidModel = new Model();
	loader->setScale(0.02);
	loader->loadModel("..\\AsteroidModel3.obj");
	*asteroidModel = loader->getModel();
	loader->clear();

	double x = rand();
	x /= RAND_MAX;
	x *= boundary.GetCoordinateX();
	double y = rand();
	y /= RAND_MAX;
	y *= boundary.GetCoordinateY();

	asteroidModel->SetPos(Vector3D(x, y, 1.0));
	asteroidModel->paintColor(Color(0.8, 0.8, 0.9));
	asteroidModel->SetOrientation(Vector3D(rand(), rand(), rand()));
	asteroidModel->SetOrientationSpeed(Vector3D(0.02, 0.11, 0.1));

	float radio = 0.2;
	asteroidModel->SetHitBoxRadius(radio);

	double ang = rand();
	ang /= RAND_MAX;

	ang *= 2 * M_PI;
	//ang = 0;
	double v = 0.004;
	double vx = v * cos(ang);
	double vy = v * sin(ang);
	asteroidModel->SetSpeed(Vector3D(vx, vy, 0.0));

	return asteroidModel;
}


void GameScene::CreateAsteroids()
{
	//Inicializamos números aleatorios
	std::srand(std::time(nullptr));



	ModelLoader* loader = new ModelLoader();
	for (int i = 0;i < 2* gameLevel;i++)
	{
		Model* asteroidModel = AsteroidModel1(loader);
		Asteroid* asteroide = new Asteroid(asteroidModel, 10);
		asteroids.push_back(asteroide);
		AddGameObject(asteroidModel);
	}	
	
	for (int i = 0;i < 2* gameLevel;i++)
	{
		Model* asteroidModel = AsteroidModel2(loader);
		Asteroid* asteroide = new Asteroid(asteroidModel, 15);
		asteroids.push_back(asteroide);
		AddGameObject(asteroidModel);
	}	
	
	for (int i = 0;i < 2* gameLevel;i++)
	{
		Model* asteroidModel = AsteroidModel3(loader);
		Asteroid* asteroide = new Asteroid(asteroidModel, 20);
		asteroids.push_back(asteroide);
		AddGameObject(asteroidModel);
	}

	delete loader;
}

void GameScene::CheckPlayerCollisions() 
{
	for (int a = 0; a < asteroids.size(); a++)
	{
		Asteroid* asteroid = asteroids[a];
		if (CheckPlayerCollision(asteroid))
		{
			//Eliminamos asteroid
			//Quitamos del vector de visualización
			DeleteGameObject(asteroid->getModel());
			//Quitamos del vector de asteroids  
			asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), asteroid), asteroids.end());
			//ELiminamos el objeto
			delete asteroid;

			DecLifePlayer();

			break;
		}
	}
}
bool GameScene::CheckPlayerCollision(Asteroid* asteroid)
{
	//TODO: Falta realizar la verificación
	if (kk)
	{
		kk = false;
		return true;
	}
	return false;
}


bool GameScene::CheckBulletCollision(Bullet* bullet, Asteroid* asteroid)
{
	//TODO: Falta realizar la verificación, poner a tru para simular que siempre le damos a un asteriode
	return false;
}


void GameScene::CheckBulletsCollisions() 
{
	for (int b = 0; b < bullets.size(); b++) 
	{
		Bullet* bullet = bullets[b];
		
		for (int a = 0; a < asteroids.size(); a++) 
		{
			Asteroid* asteroid = asteroids[a];
			if (CheckBulletCollision(bullet, asteroid)) 
			{
				IncScorePlayer(asteroid->getScore());
				//Eliminamos bullet
				bullet->Destruir();

				//Eliminamos asteroid
				//Quitamos del vector de visualización
				DeleteGameObject(asteroid->getModel());
				//Quitamos del vector de asteroids  
				asteroids.erase(std::remove(asteroids.begin(), asteroids.end(), asteroid), asteroids.end());
				//ELiminamos el objeto
				delete asteroid;
				break;
			}
		}
	}

}


void GameScene::CheckBoundary() {
	for (int i = 0; i < getGameObjects().size(); i++) {
		//SI SE PASA EN LA X POR LA DERECHA
		if (getGameObjects()[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX()) {
			getGameObjects()[i]->SetPos(Vector3D(0.01, getGameObjects()[i]->GetPos().GetCoordinateY(), getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA X POR LA IZQUIERDA
		if (getGameObjects()[i]->GetPos().GetCoordinateX() < 0) {
			getGameObjects()[i]->SetPos(Vector3D(boundary.GetCoordinateX() - 0.01, getGameObjects()[i]->GetPos().GetCoordinateY(), getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ARRIBA
		if (getGameObjects()[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY()) {
			getGameObjects()[i]->SetPos(Vector3D(getGameObjects()[i]->GetPos().GetCoordinateX(), 0.01, getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
		//SI SE PASA EN LA Y POR ABAJO
		if (getGameObjects()[i]->GetPos().GetCoordinateY() < 0) {
			getGameObjects()[i]->SetPos(Vector3D(getGameObjects()[i]->GetPos().GetCoordinateX(), boundary.GetCoordinateY() - 0.01, getGameObjects()[i]->GetPos().GetCoordinateZ()));
		}
	}
}

void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->player->ProcessKeyPressed(key, px, py);
	cout << "Tecla pulsada: " << key << endl;
}

void GameScene::Clean() 
{
	//Quitamos primero el jugador antes de limpiar el vector de objetos, ya que es compartido con todos las escenas
	DeleteGameObject(this->player->GetPlayerModel());

	RestoreScene();
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
		//CleanScene();
		sceneManager->SetNextScene();
	}
	if (key == 'p') {

		//como si hubiese perdido
		//CleanScene();
		sceneManager->SetGameOverScene();
	}

	if (key == '5') {
		Bullet* bullet = player->Shoot();
		//Añadimos a la lista de bullets para el control de las intersecciones de los disparos con los enemigos
		bullets.push_back(bullet);

		//Añadimos a la lista de Objetos para su pintado
		AddGameObject(bullet);

		string file = "..\\Disparo.wav";

		std::wstring stemp = std::wstring(file.begin(), file.end());
		LPCWSTR sw = stemp.c_str();

		//sndPlaySound(sw, SND_ASYNC | SND_FILENAME);
	}

	//Simulamos Puntuación
	if (key == '7') {
		IncScorePlayer(1);
	}

	//Simulamos perdida de vida
	if (key == '9') {
		//DecLifePlayer();
		kk = true;
	}
	
	this->player->ProcessKeyUp(key, px, py);
	cout << "Tecla soltada: " << key << endl;
}

void GameScene::IncScorePlayer(int inc) 
{
	player->SetScore(player->GetScore() + inc);
	this->textScore->setText(to_string((this->player->GetScore())));
}

void GameScene::DecLifePlayer()
{
	int vidas = player->GetLifesNum();
	vidas--;
	if (vidas == -1)
	{
		//CleanScene();
		sceneManager->SetGameOverScene();
	}
	else
	{
		player->SetLifesNum(vidas);
		this->textLifes->setText("VIDAS: " + to_string(this->player->GetLifesNum()));
	}
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
		Collisions();
	}

	//Eliminamos las balas por tiempo
	for (int i = 0; i < bullets.size(); i++) {
		Bullet* bullet = bullets[i];
		if (bullets[i]->EstaEliminado())
		{
			DeleteGameObject(bullets[i]);
			bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
			//sólo borramos una cada vez
			break;
		}
	}

	CheckBoundary();

	CheckBulletsCollisions();
	if (asteroids.size() == 0)
	{
		//Hemos destruido todos los asteroids
		player->SetLifesNum(player->GetLifesNum() + 1);
		//CleanScene();
		sceneManager->SetNextScene();
	}
	else 
	{
		CheckPlayerCollisions();
	}

}

void GameScene::Init() {

	//Inicializamos el player
	player->GetPlayerModel()->SetPos(Vector3D(boundary.GetCoordinateX() / 2, boundary.GetCoordinateY() / 2, 1));
	player->GetPlayerModel()->SetOrientation(Vector3D(0, 0, 0));
	player->GetPlayerModel()->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	player->GetPlayerModel()->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	AddGameObject(player->GetPlayerModel());


	//setCamera(Camera(Vector3D(0, 0, 12.0)));

	setCamera(Vector3D(this->boundary.GetCoordinateX() / 2, this->boundary.GetCoordinateY() / 2, this->boundary.GetCoordinateZ() * 1.2));
	//setCamera(Vector3D(this->boundary.GetCoordinateX() / 2.0, this->boundary.GetCoordinateY() / 2.0, this->boundary.GetCoordinateZ()));

	//Creamos los textos
	Text* textLevel = new Text(Vector3D(1.5, boundary.GetCoordinateY() - 1, 2.0), Color(255.0, 255.0, 255.0), "NIVEL");
	textLevel->setText("NIVEL " + to_string(gameLevel));
	this->textScore = new Text(Vector3D(1.5, boundary.GetCoordinateY() - 1.5, 2.0), Color(255.0, 255.0, 255.0), to_string((this->player->GetScore())));
	this->textLifes = new Text(Vector3D(1.5, boundary.GetCoordinateY() - 2, 2.0), Color(255.0, 255.0, 255.0), "VIDAS: " + to_string((this->player->GetLifesNum())));
	AddGameObject(this->textLifes);
	AddGameObject(this->textScore);
	AddGameObject(textLevel);

	CreateAsteroids();

	Cube* point1 = new Cube();
	point1->SetColor(Color(0, 0, 1));
	point1->SetPos(Vector3D(0, 0, 1));
	point1->SetSize(0.2);
	this->AddGameObject(point1);

	Cube* point2 = new Cube();
	point2->SetColor(Color(0, 0, 1));
	point2->SetPos(Vector3D(this->boundary.GetCoordinateX(), 0, 1));
	point2->SetSize(0.2);
	this->AddGameObject(point2);

	Cube* point3 = new Cube();
	point3->SetColor(Color(0, 0, 1));
	point3->SetPos(Vector3D(this->boundary.GetCoordinateX(), this->boundary.GetCoordinateY(), 1));
	point3->SetSize(0.2);
	this->AddGameObject(point3);

	Cube* point4 = new Cube();
	point4->SetColor(Color(0, 0, 1));
	point4->SetPos(Vector3D(0, this->boundary.GetCoordinateY(), 1));
	point4->SetSize(0.2);
	this->AddGameObject(point4);
}

//void GameScene::Render() {
//	Scene::Render();
//	
//	for (int i = 0; i < getGameObjects().size(); i++) {
//		this->getGameObjects()[i]->Render();
//	}
//}


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

