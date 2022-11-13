#pragma once
#include"Vector3D.h"
#include"Color.h"
class Solid
{
private:
	Vector3D pos;
	Color color;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;

public:
	Solid(Vector3D posArgument = Vector3D(), Color colorArgument = Color(), Vector3D orientationArgument = Vector3D(), Vector3D orientationSpeedArgument = Vector3D(), Vector3D speedArgument = Vector3D()) :pos(posArgument), color(colorArgument), orientation(orientationArgument), orientationSpeed(orientationSpeedArgument), speed(speedArgument) {};

	//Getters
	inline Vector3D GetPos() const { return this->pos; }
	inline Color GetColor() const { return this->color; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetOrientationSpeed() const { return this->orientationSpeed; }
	inline Vector3D GetSpeed() const { return this->speed; }

	//Setters
	inline void SetPos(const Vector3D& posToSet) { this->pos = posToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	inline void SetSpeed(const Vector3D speedArgument) { this->speed = speedArgument; }

	//Metodos
	virtual void Render() = 0;
	virtual void Update() = 0;
};

