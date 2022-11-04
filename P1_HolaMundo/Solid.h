#pragma once
#include"Vector3D.h"
#include"Color.h"
class Solid
{
private:
	Vector3D vectorPosition;
	Vector3D vectorRotation;
	Color vectorColor;

public:
	Solid(Vector3D vectorPos = Vector3D(), Vector3D vectorRot = Vector3D(), Color vectorCol = Color()) :vectorPosition(vectorPos), vectorRotation(vectorRot), vectorColor(vectorCol) {};

	//Getters
	inline Vector3D GetVectorCoordinate() const { return this->vectorPosition; }
	inline Color GetVectorColor() const { return this->vectorColor; }
	inline Vector3D GetVectorOrientation() const { return this->vectorRotation; }

	//Setters
	inline void SetVectorCoordinate(const Vector3D& vectorToSet) { this->vectorPosition = vectorToSet; }
	inline void SetVectorColor(const Color& colorToSet) { this->vectorColor = colorToSet; }
	inline void SetVectorOrientation(const Vector3D& orientationToSet) { this->vectorRotation = orientationToSet; }

	virtual void Render() = 0;


};

