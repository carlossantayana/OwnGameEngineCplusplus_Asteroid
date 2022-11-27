#include "Scene.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {


	cout << "Tecla pulsada: " << key << endl;
}

void Scene::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	
	if (button == 0)
	{
		teapot1->SetSize(teapot1->GetSize() + 0.1);
	}
	if (button == 2)
	{
		teapot1->SetSize(teapot1->GetSize() - 0.1);
	}
	cout << "Click"<< endl;

}

void Scene::Init() {
	camera = Camera(Vector3D(4.0, 3.0, 12.0));

	teapot1 = new Teapot(Vector3D(3.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(180.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.001, 0.002, 0.003), 0.4);
	teapot2 = new Teapot(Vector3D(2.5, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(90.0, 180.0, 90.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.001), 0.4);
	cube = new Cube(Vector3D(4.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(45.0, 45.0, 45.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.005, 0.002, 0.002), 0.4);
	sphere = new Sphere(Vector3D(5.0, 2.5, 2.0), Color(1.0, 0.5, 0.6), Vector3D(0.0, 45.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.008, 0.002, 0.001), 0.4, 20, 20);
	
	loader = new ModelLoader();
	heart = new Model();

	loader->setScale(1.0);
	loader->loadModel("..\\Heart.obj");
	*heart = loader->getModel();

	heart->SetPos(Vector3D(2.0, 2.5, 2.0));
	heart->paintColor(Color(1.0, 0.5, 0.6));
	heart->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	heart->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	heart->SetSpeed(Vector3D(0.001, 0.002, 0.003));
	loader->clear();

	this->gameObjects.push_back(teapot2);
	this->gameObjects.push_back(teapot1);
	this->gameObjects.push_back(cube);
	this->gameObjects.push_back(sphere);
	this->gameObjects.push_back(heart);
	
}

void Scene::Render() {
	this->camera.Render();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
	}
	CheckBoundary();
}

void Scene::CheckBoundary() {
	for (int i = 0; i < gameObjects.size(); i++) {

		if (gameObjects[i]->GetPos().GetCoordinateX() > boundary.GetCoordinateX() || gameObjects[i]->GetPos().GetCoordinateX() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX() * -1.0f, gameObjects[i]->GetSpeed().GetCoordinateY(), gameObjects[i]->GetSpeed().GetCoordinateZ()));
		}

		if (gameObjects[i]->GetPos().GetCoordinateY() > boundary.GetCoordinateY() || gameObjects[i]->GetPos().GetCoordinateY() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX(), gameObjects[i]->GetSpeed().GetCoordinateY() * -1.0f, gameObjects[i]->GetSpeed().GetCoordinateZ()));
		}

		if (gameObjects[i]->GetPos().GetCoordinateZ() > boundary.GetCoordinateZ() || gameObjects[i]->GetPos().GetCoordinateZ() < 0) {
			gameObjects[i]->SetSpeed(Vector3D(gameObjects[i]->GetSpeed().GetCoordinateX(), gameObjects[i]->GetSpeed().GetCoordinateY(), gameObjects[i]->GetSpeed().GetCoordinateZ() * -1.0f));
		}
	}
}
