#include "Vector3D.h"
Vector3D Vector3D :: Add(const Vector3D& vector) {
	Vector3D r;

	r.coordinateX = coordinateX + vector.coordinateX;
	r.coordinateY = coordinateY + vector.coordinateY;
	r.coordinateZ = coordinateZ + vector.coordinateZ;

	return r;
}

Vector3D Vector3D::Substract(const Vector3D& vector) {
	Vector3D r;

	r.coordinateX = coordinateX - vector.coordinateX;
	r.coordinateY = coordinateY - vector.coordinateY;
	r.coordinateZ = coordinateZ - vector.coordinateZ;

	return r;
}

Vector3D Vector3D::Product(const float& value) {
	Vector3D r;

	r.coordinateX = coordinateX * value;
	r.coordinateY = coordinateY * value;
	r.coordinateZ = coordinateZ * value;

	return r;
}

Vector3D Vector3D::Division(const float& value) {
	Vector3D r;

	r.coordinateX = coordinateX / value;
	r.coordinateY = coordinateY / value;
	r.coordinateZ = coordinateZ / value;

	return r;
}

float Vector3D::DotProduct(const Vector3D& vector) {
	float r;

	r = coordinateX * vector.coordinateX + coordinateY * vector.coordinateY + coordinateZ * vector.coordinateZ;

	return r;
}

Vector3D Vector3D :: operator+(const Vector3D& vector) {
	return this->Add(vector);
}

Vector3D Vector3D :: operator-(const Vector3D& vector) {
	return this->Substract(vector);
}

Vector3D Vector3D :: operator*(const float& value) {
	return this->Product(value);
}

Vector3D Vector3D :: operator/(const float& value) {
	return this->Division(value);
}

float Vector3D :: operator*(const Vector3D& vector) {
	return this->DotProduct(vector);
}
