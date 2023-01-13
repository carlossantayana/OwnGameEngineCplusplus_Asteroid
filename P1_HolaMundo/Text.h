#pragma once
#include"Solid.h"
#include <GL/glut.h>
#include<string>

using namespace std;

class Text:public Solid
{
private:
	string text;
public:
	Text(Vector3D posArgument, Color colorArgument, string textArgument) :Solid(posArgument, colorArgument), text(textArgument) {}
	
	void setText(const string& textToSet) { text = textToSet; }
	void Render();
};

