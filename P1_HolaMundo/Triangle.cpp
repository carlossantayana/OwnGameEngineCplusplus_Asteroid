#include "Triangle.h"

void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(this->getColor1().GetRedComponent(), this->getColor1().GetGreenComponent(), this->getColor1().GetBlueComponent());
	glNormal3f(this->getNormal1().GetCoordinateX(), this->getNormal1().GetCoordinateY(), this->getNormal1().GetCoordinateZ());
	glVertex3f(this->getVertex1().GetCoordinateX(), this->getVertex1().GetCoordinateY(), this->getVertex1().GetCoordinateZ());
	//vértice 2
	glColor3f(this->getColor2().GetRedComponent(), this->getColor2().GetGreenComponent(), this->getColor2().GetBlueComponent());
	glNormal3f(this->getNormal2().GetCoordinateX(), this->getNormal2().GetCoordinateY(), this->getNormal2().GetCoordinateZ());
	glVertex3f(this->getVertex2().GetCoordinateX(), this->getVertex2().GetCoordinateY(), this->getVertex2().GetCoordinateZ());
	//vértice 3
	glColor3f(this->getColor3().GetRedComponent(), this->getColor3().GetGreenComponent(), this->getColor3().GetBlueComponent());
	glNormal3f(this->getNormal3().GetCoordinateX(), this->getNormal3().GetCoordinateY(), this->getNormal3().GetCoordinateZ());
	glVertex3f(this->getVertex3().GetCoordinateX(), this->getVertex3().GetCoordinateY(), this->getVertex3().GetCoordinateZ());
	glEnd();
}