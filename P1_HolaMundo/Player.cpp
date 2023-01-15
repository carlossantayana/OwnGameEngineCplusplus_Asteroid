#include "Player.h"
#include <cmath>
#define M_PI 3.14159

/////////////////////////////////RECIBE UN VECTOR Y UN ÁNGULO Y DEVUELVE EL VECTOR ROTADO CON ESE ÁNGULO////////////////////////////////////////////
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

///////////////////////////////////////SE MODIFICA LA VELOCIDAD DEL JUGADOR SI HAY UNA TECLA PULSADA////////////////////////////////////////
/////////////////////////////////////////ACTUALIZA EL PERSONAJE DEL JUGADOR, MOVIÉNDOLO Y ROTÁNDOLO////////////////////////////////////////
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
		//cout << "Angulo rotado en X: " << this->playerModel->GetOrientation().GetCoordinateX() << " Angulo rotado en Y: " << this->playerModel->GetOrientation().GetCoordinateY() << " Angulo rotado en Z: " << this->playerModel->GetOrientation().GetCoordinateZ() << endl;
	}

	if(dPressed){
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, -1));
		this->playerModel->SetOrientation(this->playerModel->GetOrientation() + this->playerModel->GetOrientationSpeed() * this->rotationSpeed);
		this->playerModel->SetOrientationSpeed(Vector3D(0, 0, 0));
		//cout << "Angulo rotado en X: " << this->playerModel->GetOrientation().GetCoordinateX() << " Angulo rotado en Y: " << this->playerModel->GetOrientation().GetCoordinateY() << " Angulo rotado en Z: " << this->playerModel->GetOrientation().GetCoordinateZ() << endl;
	}
}

/////////////////////////////////////////////SE LLAMA SOBRE EL JUGADOR CUANDO DEBA DISPARAR/////////////////////////////////////////////
Bullet* Player::Shoot() {

	Bullet* bullet = new Bullet();
	bullet->SetPos(Vector3D(this->playerModel->GetPos().GetCoordinateX(), this->playerModel->GetPos().GetCoordinateY(), this->playerModel->GetPos().GetCoordinateZ()));

	Vector3D v = RotateVector(Vector3D(0, 1, 0), this->playerModel->GetOrientation().GetCoordinateZ());
	v = v * 0.02;
	bullet->SetSpeed(v);
	return bullet;
}

///////////////////////////////////////////////////////PROCESAMIENTO DE TECLAS//////////////////////////////////////////////////////////
void Player::ProcessKeyPressed(unsigned char key, int px, int py) {
	if (key == 'w'|| key == '8') {
		wPressed = true;
	}

	if (key == 'a'|| key == '4') {
		aPressed = true;
	}
	
	if (key == 'd'|| key == '6') {
		dPressed = true;
	}

	//cout << "Tecla pulsada: " << key << endl;
}

void Player::ProcessKeyUp(unsigned char key, int px, int py) {
	if (key == 'w' || key == '8') {
		wPressed = false;
	}

	if (key == 'a' || key == '4') {
		aPressed = false;
	}
	
	if (key == 'd' || key == '6') {
		dPressed = false;
	}

	//cout << "Tecla soltada: " << key << endl;
}

void Player::ProcessMouseMovement(int x, int y) {
	//cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Player::ProcessMouseClick(int button, int state, int x, int y) {
	//cout << "Click" << endl;
}