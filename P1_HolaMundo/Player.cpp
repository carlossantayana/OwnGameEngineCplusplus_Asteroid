#include "Player.h"
#include <cmath>
#define M_PI 3.14159

void Player::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (key == 'w') {
		wPressed = true;
	}

	if (key == 'a') {
		aPressed = true;
	}
	
	if (key == 'd') {
		dPressed = true;
	}

	cout << "Tecla pulsada: " << key << endl;
}

void Player::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'w') {
		wPressed = false;
	}

	if (key == 'a') {
		aPressed = false;
	}
	
	if (key == 'd') {
		dPressed = false;
	}

	cout << "Tecla soltada: " << key << endl;
}

void Player::ProcessMouseMovement(int x, int y) {
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Player::ProcessMouseClick(int button, int state, int x, int y) {
	cout << "Click" << endl;
}

Vector3D Player::RotateVector(Vector3D vector, float angle)
{
	float newAngle = (angle * M_PI) / 180;
	float newX = vector.GetCoordinateX();
	float newY = vector.GetCoordinateY();
	float newZ = vector.GetCoordinateZ();
	newX=cos(newAngle)*vector.GetCoordinateX()-sin(newAngle)*vector.GetCoordinateY();
	newY=sin(newAngle)*vector.GetCoordinateX()+cos(newAngle)*vector.GetCoordinateY();

	return Vector3D(newX, newY, newZ);	
}

void Player::UpdatePlayer(){

	float x = this->playerModel->GetPos().GetCoordinateX();
	float incX = RotateVector(Vector3D(0, 1, 0), this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateX() * this->speed;

	float y = this->playerModel->GetPos().GetCoordinateY();
	float incY = RotateVector(Vector3D(0, 1, 0), this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateY() * this->speed;

	this->playerModel->SetPos(Vector3D(x + incX, y + incY, this->playerModel->GetPos().GetCoordinateZ()));

	if(wPressed){
		if(speed<0.1)
		{
			speed+=0.005;
		}
		else{
			speed = 0.1;
		}
	}
	else{

		if(speed>0)
		{
			speed-=0.001;
		}
		else {
			speed = 0;
		}

	}

	if(aPressed){
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 1));
		this->playerModel->SetOrientation(this->playerModel->GetOrientation() + this->playerModel->GetOrientationSpeed() * this->rotationSpeed);
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 0));
		cout << "Angulo rotado en X: " << this->playerModel->GetOrientation().GetCoordinateX() << " Angulo rotado en Y: " << this->playerModel->GetOrientation().GetCoordinateY() << " Angulo rotado en Z: " << this->playerModel->GetOrientation().GetCoordinateZ() << endl;
	}

	if(dPressed){
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, -1));
		this->playerModel->SetOrientation(this->playerModel->GetOrientation() + this->playerModel->GetOrientationSpeed() * this->rotationSpeed);
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 0));
		cout << "Angulo rotado en X: " << this->playerModel->GetOrientation().GetCoordinateX() << " Angulo rotado en Y: " << this->playerModel->GetOrientation().GetCoordinateY() << " Angulo rotado en Z: " << this->playerModel->GetOrientation().GetCoordinateZ() << endl;
	}
}

void Player::UpdateBullet() {
	if (shooting) {
		float x = this->playerModel->GetPos().GetCoordinateX();
		float incX = RotateVector(Vector3D(0, 1, 0), this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateX() * 0.25;
		bulletOrientationX = incX;
		

		float y = this->playerModel->GetPos().GetCoordinateY();
		float incY = RotateVector(Vector3D(0, 1, 0), this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateY() * 0.25;
		bulletOrientationY = incY;

		this->bullet->SetPos(Vector3D(x + incX, y + incY, this->playerModel->GetPos().GetCoordinateZ()));
		shooting = false;
	}
	else if (activeBullets > 0) {
		this->bullet->SetPos(Vector3D(bullet->GetPos().GetCoordinateX() + bulletOrientationX, bullet->GetPos().GetCoordinateY() + bulletOrientationY, this->playerModel->GetPos().GetCoordinateZ()));
		if (bullet->GetPos().GetCoordinateX() > 18) {
			deleteBullet = true;
		}
	}
}

void Player::Shoot() {
	bullet = new Sphere();
	bullet->SetColor(Color(255.0, 255.0, 255.0));
	bullet->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	bullet->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	bullet->SetRadius(0.05);
	bullet->SetSlacks(12.0);
	bullet->SetSlices(12.0);
	bullet->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	shooting = true;
	activeBullets++;

	bullet->SetPos(playerModel->GetPos());
}