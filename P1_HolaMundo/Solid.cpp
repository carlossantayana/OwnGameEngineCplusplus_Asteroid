#include "Solid.h"

void Solid::Update() {
	float timeIncrement = 1;

	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * timeIncrement);
	this->SetPos(this->GetPos() + this->GetSpeed() * timeIncrement);
}