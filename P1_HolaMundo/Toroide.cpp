#include "Toroide.h"

void Toroide::Render() {

	glPushMatrix();
	glTranslatef(this->GetVectorCoordinate().GetX(), this->GetVectorCoordinate().GetY(), this->GetVectorCoordinate().GetZ());
	glColor3f(this->GetVectorColor().GetR(), this->GetVectorColor().GetG(), this->GetVectorColor().GetB());
	glRotatef(this->GetVectorOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetZ(), 0.0, 0.0, 1.0);
	glutSolidTorus(GetRadioI(), GetRadioE(), GetFaces(), GetRings());
	glPopMatrix();
}