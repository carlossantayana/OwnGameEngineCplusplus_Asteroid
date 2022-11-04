#include "Prisma.h"

void Prisma::Render() {

	glPushMatrix();
	glTranslatef(this->GetVectorCoordinate().GetX(), this->GetVectorCoordinate().GetY(), this->GetVectorCoordinate().GetZ());
	glColor3f(this->GetVectorColor().GetR(), this->GetVectorColor().GetG(), this->GetVectorColor().GetB());
	glRotatef(this->GetVectorOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetZ(), 0.0, 0.0, 1.0);
	glScalef(this->GetLongitude(), this->GetHigh(), this->GetWidht());
	glutSolidCube(1);
	glPopMatrix();
}
