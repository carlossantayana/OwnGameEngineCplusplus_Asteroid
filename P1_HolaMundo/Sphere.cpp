#include "Sphere.h"

//Implementaci�n del m�todo de renderizado de la esfera
void Sphere::Render() {
	glPushMatrix();
	glTranslatef(this->GetPos().GetCoordinateX(), this->GetPos().GetCoordinateY(), this->GetPos().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetBlueComponent());

	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);

	this->GetIsTransparent() ? glutWireSphere(GetRadius(), GetSlices(), GetSlacks()) : glutSolidSphere(GetRadius(), GetSlices(), GetSlacks());
	glPopMatrix();
}