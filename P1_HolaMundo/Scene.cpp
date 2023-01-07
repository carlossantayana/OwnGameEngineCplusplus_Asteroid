#include "Scene.h"
#include "Cuboid.h"

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	cout << "Tecla pulsada: " << key << endl;
}

void Scene::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {
	/*if (button == 0)
	{
		teapot1->SetSize(teapot1->GetSize() + 0.1);
	}
	if (button == 2)
	{
		teapot1->SetSize(teapot1->GetSize() - 0.1);
	}*/
	cout << "Click"<< endl;
}

void Scene::AddGameObject(Solid* gameObject) {
	this->gameObjects.push_back(gameObject);
}

void Scene::Init() {
	camera = Camera(Vector3D(4.0, 3.0, 12.0));
	
	/*if (this->getDrawVertexes())
	{
		Cube* point1 = new Cube();
		point1->SetColor(Color(0, 0, 1));
		point1->SetPos(Vector3D(0, 0, 0));
		point1->SetSize(0.2);
		this->gameObjects.push_back(point1);

		Cube* point2 = new Cube();
		point2->SetColor(Color(0, 0, 1));
		point2->SetPos(Vector3D(this->getBoundary().GetCoordinateX(), 0, 0));
		point2->SetSize(0.2);
		this->gameObjects.push_back(point2);

		Cube* point3 = new Cube();
		point3->SetColor(Color(0, 0, 1));
		point3->SetPos(Vector3D(this->getBoundary().GetCoordinateX(), this->getBoundary().GetCoordinateY(), 0));
		point3->SetSize(0.2);
		this->gameObjects.push_back(point3);

		Cube* point4 = new Cube();
		point4->SetColor(Color(0, 0, 1));
		point4->SetPos(Vector3D(0, this->getBoundary().GetCoordinateY(), 0));
		point4->SetSize(0.2);
		this->gameObjects.push_back(point4);

		Cube* point5 = new Cube();
		point5->SetColor(Color(0, 0, 1));
		point5->SetPos(Vector3D(0, this->getBoundary().GetCoordinateY(), this->getBoundary().GetCoordinateZ()));
		point5->SetSize(0.2);
		this->gameObjects.push_back(point5);

		Cube* point6 = new Cube();
		point6->SetColor(Color(0, 0, 1));
		point6->SetPos(Vector3D(this->getBoundary().GetCoordinateX(), this->getBoundary().GetCoordinateY(), this->getBoundary().GetCoordinateZ()));
		point6->SetSize(0.2);
		this->gameObjects.push_back(point6);

		Cube* point7 = new Cube();
		point7->SetColor(Color(0, 0, 1));
		point7->SetPos(Vector3D(this->getBoundary().GetCoordinateX(), 0, this->getBoundary().GetCoordinateZ()));
		point7->SetSize(0.2);
		this->gameObjects.push_back(point7);

		Cube* point8 = new Cube();
		point8->SetColor(Color(0, 0, 1));
		point8->SetPos(Vector3D(0, 0, this->getBoundary().GetCoordinateZ()));
		point8->SetSize(0.2);
		this->gameObjects.push_back(point8);
	}

	if (this->drawBox)
	{
		Cuboid* floor = new Cuboid();
		floor->SetHight(0.01);
		floor->SetWidth(this->getBoundary().GetCoordinateZ());
		floor->SetLenght(this->getBoundary().GetCoordinateX());
		floor->SetColor(Color(0.5, 0.8, 1));
		floor->SetPos(Vector3D(this->getBoundary().GetCoordinateX() / 2, 0, this->getBoundary().GetCoordinateZ() / 2));
		floor->SetIsTransparent(true);
		this->gameObjects.push_back(floor);

		Cuboid* ceil = new Cuboid();
		ceil->SetHight(0.01);
		ceil->SetWidth(this->getBoundary().GetCoordinateZ());
		ceil->SetLenght(this->getBoundary().GetCoordinateX());
		ceil->SetColor(Color(0.5, 0.8, 1));
		ceil->SetPos(Vector3D(this->getBoundary().GetCoordinateX() / 2, this->getBoundary().GetCoordinateY(), this->getBoundary().GetCoordinateZ() / 2));
		ceil->SetIsTransparent(true);
		this->gameObjects.push_back(ceil);

		Cuboid* back = new Cuboid();
		back->SetHight(this->getBoundary().GetCoordinateY());
		back->SetWidth(0.01);
		back->SetLenght(this->getBoundary().GetCoordinateX());
		back->SetColor(Color(0.6, 0.2, 0.2));
		back->SetPos(Vector3D(this->getBoundary().GetCoordinateX() / 2, this->getBoundary().GetCoordinateY() / 2, 0));
		back->SetIsTransparent(true);
		this->gameObjects.push_back(back);

		Cuboid* left = new Cuboid();
		left->SetHight(this->getBoundary().GetCoordinateY());
		left->SetWidth(this->getBoundary().GetCoordinateZ());
		left->SetLenght(0.01);
		left->SetColor(Color(0.2, 0.2, 0.6));
		left->SetPos(Vector3D(0, this->getBoundary().GetCoordinateY() / 2, this->getBoundary().GetCoordinateZ() / 2));
		left->SetIsTransparent(true);
		this->gameObjects.push_back(left);

		Cuboid* right = new Cuboid();
		right->SetHight(this->getBoundary().GetCoordinateY());
		right->SetWidth(this->getBoundary().GetCoordinateZ());
		right->SetLenght(0.01);
		right->SetColor(Color(0.7, 0.9, 0.5));
		right->SetPos(Vector3D(this->getBoundary().GetCoordinateX(), this->getBoundary().GetCoordinateY() / 2, this->getBoundary().GetCoordinateZ() / 2));
		right->SetIsTransparent(true);
		this->gameObjects.push_back(right);
	}*/
}

void Scene::Render() {
	this->camera.Render();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}

void Scene::Update(const float& time) {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update(time);
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
