#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "Vector3D.h"
#include "Color.h"

using namespace std;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	ChangeProperties();

	cout << "Tecla pulsada: " << key << endl;
}

void Game::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Game::ProcessMouseClick(int button, int state, int x, int y) {
	ChangeProperties();

	cout << "Click: " << button << endl;
}

void Game::Init() {

}

void Game::Render() {
	this->GetTeapot1().Render();
	this->GetCube1().Render();
	this->GetSphere1().Render();

	this->GetTeapot2().Render();
	this->GetCube2().Render();
	this->GetSphere2().Render();
}

void Game::Update() {

}

void Game::ChangeProperties() {
	int randomNumber = rand() % 4 + 1;
	Vector3D v(0.1, 0.1, 0.1);
	Color c(0.1, 0.1, 0.1);

	switch (randomNumber) {
	case 1:
		this->teapot1.SetPos(teapot1.GetPos() + v);
		this->teapot2.SetPos(teapot2.GetPos() + v);
		this->cube1.SetPos(cube1.GetPos() + v);
		this->cube2.SetPos(cube2.GetPos() + v);
		this->sphere1.SetPos(sphere1.GetPos() + v);
		this->sphere2.SetPos(sphere2.GetPos() + v);
		break;
	case 2:
		this->teapot1.SetColor(this->teapot1.GetColor() + c);
		this->teapot2.SetColor(this->teapot2.GetColor() + c);
		this->cube1.SetColor(this->cube1.GetColor() + c);
		this->cube2.SetColor(this->cube2.GetColor() + c);
		this->sphere1.SetColor(this->sphere1.GetColor() + c);
		this->sphere2.SetColor(this->sphere2.GetColor() + c);
		break;
	case 3:
		this->teapot1.SetOrientation(this->teapot1.GetOrientation() + v);
		this->teapot2.SetOrientation(this->teapot2.GetOrientation() + v);
		this->cube1.SetOrientation(this->cube1.GetOrientation() + v);
		this->cube2.SetOrientation(this->cube2.GetOrientation() + v);
		this->sphere1.SetOrientation(this->sphere1.GetOrientation() + v);
		this->sphere2.SetOrientation(this->sphere2.GetOrientation() + v);
		break;
	case 4:
		this->teapot1.SetSize(this->teapot1.GetSize() + 0.1);
		this->teapot2.SetSize(this->teapot2.GetSize() + 0.1);
		this->cube1.SetSize(this->cube1.GetSize() + 0.1);
		this->cube2.SetSize(this->cube2.GetSize() + 0.1);
		this->sphere1.SetRadius(this->sphere1.GetRadius() + 0.1);
		this->sphere2.SetRadius(this->sphere2.GetRadius() + 0.1);
	}
}