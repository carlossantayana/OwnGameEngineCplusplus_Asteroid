#pragma once
#include "Model.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ModelLoader{
private:
	//Atributos para llevar a cabo la carga de un modelo 3D desde un archivo.obj
	float scale;

	Model model;

	vector <Vector3D> readVertex;
	vector <Vector3D> readNormals;

	float maxX;
	float minX;
	float maxY;
	float minY;
	float maxZ;
	float minZ;

	//Metodos
	inline float getWidth() { return maxX - minX; }
	inline float getHeight() { return maxY - minY; }
	inline float getLength() { return maxZ - minZ; }

    void calcBoundaries(Vector3D lastVertex);
	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjTriangle(const string& line);

public:

	inline Model getModel() { return model; }
	inline float getScale() { return scale; }

	inline void setScale(float scaleToSet) { scale = scaleToSet; }

	void loadModel(const string& filePath);
	void clear();

	
};

