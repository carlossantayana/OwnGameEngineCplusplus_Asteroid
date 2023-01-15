#pragma once
#include <iostream>

class Color
{
private:
	//Atributos del color
	float redComponent;
	float greenComponent;
	float blueComponent;

public:
	//Constructores
	Color() : redComponent(0.0), greenComponent(0.0), blueComponent(0.0) {} //Constructor por defecto
	Color(float r, float g, float b) : redComponent(r), greenComponent(g), blueComponent(b) {} //Constructor

	//Redefinimos el operador suma para poder hacer sumas de colores
	Color operator+(Color b) {
		Color r;

		r.redComponent = redComponent + b.redComponent;
		r.greenComponent = greenComponent+ b.greenComponent;
		r.blueComponent = blueComponent + b.blueComponent;

		//Controlamos que los valores tras realizar la suma no sobrepasen el número 1 ni queden por debajo de 0.

		if (r.redComponent < 0 || r.redComponent > 1) {
			std::cout << "La componente roja no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			r.redComponent = 0.0f;
		}
		if (r.greenComponent < 0 || r.greenComponent > 1) {
			std::cout << "La componente verde no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			r.greenComponent = 0.0f;
		}
		if (r.blueComponent < 0 || r.blueComponent > 1) {
			std::cout << "La componente azul no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			r.blueComponent = 0.0f;
		}
		return r;
	}

	//Getters
	inline float GetRedComponent() const {
		return this->redComponent;
	}
	inline float GetGreenComponent() const {
		return this->greenComponent;
	}
	inline float GetBlueComponent() const {
		return this->blueComponent;
	}

	//Setters
	inline void SetRedComponent(const float& redComponentToSet) {
		if (redComponentToSet < 0 || redComponentToSet > 1) {
			std::cout << "La componente roja no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			this->redComponent = 0.0f;
		}
		else {
			this->redComponent = redComponentToSet;
		}
	}
	inline void SetGreenComponent(const float& greenComponentToSet) {
		if (greenComponentToSet < 0 || greenComponentToSet > 1) {
			std::cout << "La componente verde no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			this->greenComponent = 0.0f;
		}
		else {
			this->greenComponent = greenComponentToSet;
		}
	}
	inline void SetBlueComponent(const float& blueComponentToSet) {
		if (blueComponentToSet < 0 || blueComponentToSet > 1) {
			std::cout << "La componente azul no puede tomar un valor menor que 0 o mayor que 1, se pondrá el valor por defecto 0" << std::endl;
			this->blueComponent = 0.0f;
		}
		else {
			this->blueComponent = blueComponentToSet;
		}
	}
};

