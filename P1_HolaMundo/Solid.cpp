#include "Solid.h"

void Solid::Update(const float& time) {
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
	this->SetPos(this->GetPos() + this->GetSpeed() * time);
}