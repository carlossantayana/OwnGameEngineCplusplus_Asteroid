#pragma once
#include"Solid.h"
#include <GL/glut.h>
#include<string>

using namespace std;

class Text:public Solid
{
private:
	//Atributo con el texto a renderizar
	string text;

public:
	//Constructor
	Text(Vector3D posArgument, Color colorArgument, string textArgument) :Solid(posArgument, colorArgument), text(textArgument) {}
	
	//Método de renderizado
	void Render();

	//SETTER
	void setText(const string& textToSet) { text = textToSet; }
};

