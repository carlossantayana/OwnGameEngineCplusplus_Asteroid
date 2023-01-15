#include "Solid.h"

//Actualización de todos los objetos que hereden de Solid en el tiempo
void Solid::Update(const float& time) {
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
	this->SetPos(this->GetPos() + this->GetSpeed() * time);
}