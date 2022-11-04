#include "Teapot.h"

void Teapot::Render() {
	glPushMatrix();
	glTranslatef(this->GetVectorCoordinate().GetCoordinateX(), this->GetVectorCoordinate().GetCoordinateY(), this->GetVectorCoordinate().GetCoordinateZ());
	glColor3f(this->GetVectorColor().GetRedComponent(), this->GetVectorColor().GetGreenComponent(), this->GetVectorColor().GetBlueComponent());

	glRotatef(this->GetVectorOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetVectorOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);

	glutSolidTeapot(this->GetSize());
	glPopMatrix();
}