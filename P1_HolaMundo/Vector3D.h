#pragma once
class Vector3D
{
private:
	float coordinateX;
	float coordinateY;
	float coordinateZ;
public:
	Vector3D() : coordinateX(0.0), coordinateY(0.0), coordinateZ(0.0) {} //Constructor por defecto

	Vector3D(float x, float y, float z) : coordinateX(x), coordinateY(y), coordinateZ(z) {} //Constructor

	//Getters

	inline float GetCoordinateX() const {
		return this->coordinateX;
	}
	inline float GetCoordinateY() const {
		return this->coordinateY;
	}
	inline float GetCoordinateZ() const {
		return this->coordinateZ;
	}

	//Setters

	inline void SetCoordinateX(const float& coordinateXToSet) {
		this->coordinateX = coordinateXToSet;
	}
	inline void SetCoordinateY(const float& coordinateYToSet) {
		this->coordinateY = coordinateYToSet;
	}
	inline void SetCoordinateZ(const float& coordinateZToSet) {
		this->coordinateZ = coordinateZToSet;
	}

	//Metodos para las operaciones

	Vector3D Add(const Vector3D& vector);
	Vector3D Substract(const Vector3D& vector);
	Vector3D Product(const float& value);
	Vector3D Division(const float& value);
	float DotProduct(const Vector3D& vector);

	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const float& value);
	Vector3D operator/(const float& value);
	float operator*(const Vector3D& vector);
};

