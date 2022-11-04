#pragma once
#include"Vector3D.h"
#include"Color.h"
class Solid
{
private:
	Vector3D pos;
	Color color;
	Vector3D orientation;

public:
	Solid(Vector3D posArgument = Vector3D(), Color colorArgument = Color(), Vector3D orientationArgument = Vector3D()) :pos(posArgument), color(colorArgument), orientation(orientationArgument) {};

	//Getters
	inline Vector3D GetPos() const { return this->pos; }
	inline Color GetColor() const { return this->color; }
	inline Vector3D GetOrientation() const { return this->orientation; }

	//Setters
	inline void SetPos(const Vector3D& posToSet) { this->pos = posToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }

	virtual void Render() = 0;


};

