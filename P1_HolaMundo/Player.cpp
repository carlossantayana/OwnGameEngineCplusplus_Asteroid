#include "Player.h"
#include <cmath>
#define M_PI 3.14159

void Player::ProcessKeyPressed(unsigned char key, unsigned char keyState[], int px, int py) {
	cout << "Tecla pulsada: " << key << endl;
	if (key == 'w') {
		this->playerModel->SetPos(Vector3D(this->playerModel->GetPos().GetCoordinateX() + RotateVector(Vector3D(0,1,0),this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateX()*this->speed, this->playerModel->GetPos().GetCoordinateY() +RotateVector(Vector3D(0,1,0),this->playerModel->GetOrientation().GetCoordinateZ()).GetCoordinateY()*this->speed, this->playerModel->GetPos().GetCoordinateZ()));
	}
	if (key == 'a') {
		//this->playerModel->SetPos(Vector3D(this->playerModel->GetPos().GetCoordinateX() - this->speed, this->playerModel->GetPos().GetCoordinateY(), this->playerModel->GetPos().GetCoordinateZ()));
		
		//this->playerModel->SetOrientationSpeed(Vector3D(1, 0, 0));
		//this->playerModel->SetOrientationSpeed(Vector3D(0, 1, 0));
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 1));

		
		this->playerModel->SetOrientation(this->playerModel->GetOrientation() + this->playerModel->GetOrientationSpeed() * this->rotationSpeed);
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 0));
	}
	//if (key == 's') {
	//	//this->playerModel->SetPos(Vector3D(this->playerModel->GetPos().GetCoordinateX(), this->playerModel->GetPos().GetCoordinateY() - this->speed, this->playerModel->GetPos().GetCoordinateZ()));
	//}
	if (key == 'd') {
		//this->playerModel->SetPos(Vector3D(this->playerModel->GetPos().GetCoordinateX() + this->speed, this->playerModel->GetPos().GetCoordinateY(), this->playerModel->GetPos().GetCoordinateZ()));
		
		//this->playerModel->SetOrientationSpeed(Vector3D(-1, 0, 0));
		//this->playerModel->SetOrientationSpeed(Vector3D(0, -1, 0));
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, -1));

		
		this->playerModel->SetOrientation(this->playerModel->GetOrientation() + this->playerModel->GetOrientationSpeed() * this->rotationSpeed);
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 0));
	}

	cout << "Angulo rotado en X: " << this->playerModel->GetOrientation().GetCoordinateX() << " Angulo rotado en Y: " << this->playerModel->GetOrientation().GetCoordinateY() << " Angulo rotado en Z: " << this->playerModel->GetOrientation().GetCoordinateZ() << endl;
}

void Player::ProcessKeyUp(unsigned char key, unsigned char keyState[], int px, int py) {
	//de momento no hacemos nada...
	cout << "Tecla soltada: " << key << endl;
}

void Player::ProcessMouseMovement(int x, int y) {
	//de momento no hacemos nada...
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Player::ProcessMouseClick(int button, int state, int x, int y) {
	//de momento no hacemos nada...
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