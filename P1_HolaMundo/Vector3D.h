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

	//Redefinimos el operador suma para poder hacer sumas de vectores 3D
	Vector3D operator+(Vector3D b) {
		Vector3D r;

		r.coordinateX = coordinateX + b.coordinateX;
		r.coordinateY = coordinateY + b.coordinateY;
		r.coordinateZ = coordinateZ + b.coordinateZ;

		return r;
	}

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
};

