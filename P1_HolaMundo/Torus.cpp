#include "Torus.h"

void Torus::Render() {

	glPushMatrix();
	glTranslatef(this->GetPos().GetCoordinateX(), this->GetPos().GetCoordinateY(), this->GetPos().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	glutSolidTorus(GetRadiusI(), GetRadiusE(), GetFaces(), GetRings());
	glPopMatrix();
}

void Torus::Update() {
	float timeIncrement = 1;

	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * timeIncrement);
	this->SetPos(this->GetPos() + this->GetSpeed() * timeIncrement);
}