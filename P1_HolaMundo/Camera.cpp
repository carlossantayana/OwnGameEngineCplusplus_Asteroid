#include "Camera.h"
#include <GL/glut.h>

//Implementaci�n del renderizado de la c�mara
void Camera::Render() 
{
	glTranslatef(-1 * this->GetPos().GetCoordinateX(), -1 * this->GetPos().GetCoordinateY(), -1 * this->GetPos().GetCoordinateZ());
	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);

}