#include "Torus.h"

void Torus::Render() {

	glPushMatrix();
	glTranslatef(this->GetPos().GetCoordinateX(), this->GetPos().GetCoordinateY(), this->GetPos().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());
	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	this->GetIsTransparent() ?
		glutWireTorus(this->GetRadiusI(), this->GetRadiusE(), this->GetFaces(), this->GetRings()) :
		glutSolidTorus(this->GetRadiusI(), this->GetRadiusE(), this->GetFaces(), this->GetRings());
	glPopMatrix();
}