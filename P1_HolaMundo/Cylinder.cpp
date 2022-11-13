#include "Cylinder.h"
void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(this->GetPos().GetCoordinateX(), this->GetPos().GetCoordinateY(), this->GetPos().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());

	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);

	gluCylinder(quadricTemp, this->GetRadiusB(), this->GetRadiusT(), this->GetHight(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();

	gluDeleteQuadric(quadricTemp);
}

void Cylinder::Update() {
	float timeIncrement = 1;

	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * timeIncrement);
	this->SetPos(this->GetPos() + this->GetSpeed() * timeIncrement);
}