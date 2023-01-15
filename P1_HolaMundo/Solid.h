#pragma once
#include"Vector3D.h"
#include"Color.h"
class Solid
{
private:
	//ATRIBUTOS DE UN CUERPO SOLIDO
	Vector3D pos;
	Color color;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;
	float hitBoxRadius;

	//quitar más tarde
	bool isTransparent;

public:
	//Constructor de sólidos
	Solid(Vector3D posArgument = Vector3D(), Color colorArgument = Color(), Vector3D orientationArgument = Vector3D(), Vector3D orientationSpeedArgument = Vector3D(), Vector3D speedArgument = Vector3D()) :pos(posArgument), color(colorArgument), orientation(orientationArgument), orientationSpeed(orientationSpeedArgument), speed(speedArgument) { hitBoxRadius = 0.0; };

	//Getters
	inline Vector3D GetPos() const { return this->pos; }
	inline float GetHitBoxRadius() const { return this->hitBoxRadius; }
	inline Color GetColor() const { return this->color; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetOrientationSpeed() const { return this->orientationSpeed; }
	inline Vector3D GetSpeed() const { return this->speed; }

	//quitar más tarde
	inline bool GetIsTransparent() const { return this->isTransparent; }
	
	//Setters
	inline void SetPos(const Vector3D& posToSet) { this->pos = posToSet; }
	inline void SetHitBoxRadius(const float& hitBoxRadiusToSet) { hitBoxRadius = hitBoxRadiusToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(const Vector3D& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	inline void SetSpeed(const Vector3D speedArgument) { this->speed = speedArgument; }

	//quitar más tarde
	inline void SetIsTransparent(const bool& isTransparentToSet) { this->isTransparent = isTransparentToSet; }

	//Métodos de renderizado y actualización de sólidos
	virtual void Render() = 0;
	virtual void Update(const float& time);
};

