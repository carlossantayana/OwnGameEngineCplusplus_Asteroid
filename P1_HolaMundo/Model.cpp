#include "Model.h"

void Model::addTriangle(Triangle triangle) {
	triangles.push_back(triangle);
}

void Model::paintColor(Color color) {
	for (Triangle& triangle : this->triangles) {
		triangle.setColor1(color);
		triangle.setColor2(color);
		triangle.setColor3(color);
	}
}

void Model::clear() {
	triangles.clear();
}

void Model::Render() {
	glPushMatrix();
	glTranslatef(this->GetPos().GetCoordinateX(), this->GetPos().GetCoordinateY(), this->GetPos().GetCoordinateZ());
	glColor3f(this->GetColor().GetRedComponent(), this->GetColor().GetGreenComponent(), this->GetColor().GetGreenComponent());
	glRotatef(this->GetOrientation().GetCoordinateX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().GetCoordinateZ(), 0.0, 0.0, 1.0);
	
	for(Triangle t : triangles) t.Render();
	glPopMatrix();

}