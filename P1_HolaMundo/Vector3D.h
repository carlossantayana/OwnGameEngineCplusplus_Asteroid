#pragma once
template <class T> class Vector3Dx;

using Vector3D = Vector3Dx<float>; //esto le indica ya el tipo de dato que es. Al poner Vector3D posicion, en realidad haces Vector3Dx<float> posicion. De esta manera no hay que indicar el tipo cada vez que se usa.

template <class T>
class Vector3Dx
{
private:
	T coordinateX;
	T coordinateY;
	T coordinateZ;
public:
	Vector3Dx() : coordinateX(0.0), coordinateY(0.0), coordinateZ(0.0) {} //Constructor por defecto

	Vector3Dx(T x, T y, T z) : coordinateX(x), coordinateY(y), coordinateZ(z) {} //Constructor

	//Getters

	inline T GetCoordinateX() const { return this->coordinateX; }
	inline T GetCoordinateY() const { return this->coordinateY; }
	inline T GetCoordinateZ() const { return this->coordinateZ; }

	//Setters

	inline void SetCoordinateX(const T& coordinateXToSet) { this->coordinateX = coordinateXToSet; }
	inline void SetCoordinateY(const T& coordinateYToSet) { this->coordinateY = coordinateYToSet; }
	inline void SetCoordinateZ(const T& coordinateZToSet) { this->coordinateZ = coordinateZToSet; }

	//Metodos para las operaciones

	Vector3Dx<T> Add(const Vector3Dx<T>& vector) {
		Vector3Dx<T> r;
		r.coordinateX = coordinateX + vector.coordinateX;
		r.coordinateY = coordinateY + vector.coordinateY;
		r.coordinateZ = coordinateZ + vector.coordinateZ;
		return r;
	}
	Vector3Dx<T> Substract(const Vector3Dx<T>& vector) {
		Vector3Dx<T> r;
		r.coordinateX = coordinateX - vector.coordinateX;
		r.coordinateY = coordinateY - vector.coordinateY;
		r.coordinateZ = coordinateZ - vector.coordinateZ;
		return r;
	}
	Vector3Dx<T> Product(const T& value) {
		Vector3Dx<T> r;
		r.coordinateX = coordinateX * value;
		r.coordinateY = coordinateY * value;
		r.coordinateZ = coordinateZ * value;
		return r;
	}
	Vector3Dx<T> Division(const T& value) {
		Vector3Dx<T> r;
		r.coordinateX = coordinateX / value;
		r.coordinateY = coordinateY / value;
		r.coordinateZ = coordinateZ / value;
		return r;
	}
	T DotProduct(const Vector3Dx<T>& vector) {
		T r;
		r = coordinateX * vector.coordinateX + coordinateY * vector.coordinateY + coordinateZ * vector.coordinateZ;
		return r;
	}

	T distance2D(const Vector3Dx<T>& vector) {
		Vector3Dx<T> direccion{ GetCoordinateX() - vector.GetCoordinateX(),GetCoordinateY() - vector.GetCoordinateY(), 0 };
		return sqrt((direccion.GetCoordinateX() * direccion.GetCoordinateX()) + (direccion.GetCoordinateY() * direccion.GetCoordinateY()));
	}

	Vector3Dx<T> operator+(const Vector3Dx<T>& vector) { return this->Add(vector); }
	Vector3Dx<T> operator-(const Vector3Dx<T>& vector) { return this->Substract(vector); }
	Vector3Dx<T> operator*(const T& value) { return this->Product(value); }
	Vector3Dx<T> operator/(const T& value) { return this->Division(value); }
	T operator*(const Vector3Dx<T>& vector) { return this->DotProduct(vector); }
	
};

