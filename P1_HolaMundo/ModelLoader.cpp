#include "ModelLoader.h"
#include <fstream>
#include <sstream>

void ModelLoader::loadModel(const string& filePath) {
	try {

		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			int count = 0;

			while (getline(objFile, line)) { //mientras siga habiendo lineas que leer

				if (line[0] == 'v' && line[1] == 'n') {					    //ejemplo: vn 0.0 0.36 -0.93 -> normal
					Vector3D normal = this->parseObjLineToVector3D(line);	//convierte la linea en un vector3D
					readNormals.push_back(normal);                          //agregamos el vector de normales a la lista
				}
				else if (line[0] == 'v') {                                  //ejemplo v 0.5 0.34 1.5 -> vertice
					Vector3D vertex = this->parseObjLineToVector3D(line);   
					this->calcBoundaries(vertex);                           //calculamos los limites 
					readVertex.push_back(vertex);                           //agrega el vector a los vertices de la lista
				}
				else if (line[0] == 'f') {                                  //es un triangulo
					Triangle triangle = this->parseObjTriangle(line);       //convierte la linea en un triangulo
					this->model.addTriangle(this->center(triangle));
					//this->model.addTriangle(triangle);                      
				}
			}

			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}

	}
	catch(exception& ex) {
		cout << "Excepcion al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

void ModelLoader::clear() {
	readNormals.clear();
	readVertex.clear();
	model.clear();
}

Vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	string typeOfPoint;
	float coordinateX, coordinateY, coordinateZ;
	
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> coordinateX >> coordinateY >> coordinateZ; 
	Vector3D vectorPoint(coordinateX, coordinateY, coordinateZ);
	return vectorPoint * getScale();	
}

Triangle ModelLoader::parseObjTriangle(const string& line) {
	char c;
	int idxVertex1, idxVertex2, idxVertex3, idxNormal1, idxNormal2, idxNormal3;
	istringstream stringStream(line);

	stringStream >> c; //f
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;
	stringStream >> idxVertex3 >> c >> c >> idxNormal3;

	Vector3D vertex1, vertex2, vertex3, normal;
	vertex1 = readVertex[idxVertex1 - 1]; 
	vertex2 = readVertex[idxVertex2 - 1];
	vertex3 = readVertex[idxVertex3 - 1];
	normal = readNormals[idxNormal1 - 1];

	Triangle triangle(vertex1, vertex2, vertex3, normal, normal, normal);

	return triangle;
}

void ModelLoader::calcBoundaries(Vector3D lastVector){
	maxX = fmax(maxX, lastVector.GetCoordinateX());
	maxY = fmax(maxY, lastVector.GetCoordinateY());
	maxZ = fmax(maxZ, lastVector.GetCoordinateZ());

	minX = fmin(minX, lastVector.GetCoordinateX());
	minY = fmin(minY, lastVector.GetCoordinateY());
	minZ = fmin(minZ, lastVector.GetCoordinateZ());
}

Triangle ModelLoader::center(Triangle triangle) {
	Vector3D modelCenter((minX + getWidth()) / 2, (minY + getHeight()) / 2, (minZ + getLength()) / 2);
	Triangle centeredTriangle(triangle.getVertex1() - modelCenter, triangle.getVertex2() - modelCenter, triangle.getVertex3() - modelCenter, triangle.getNormal1(), triangle.getNormal2(), triangle.getNormal3());

	return centeredTriangle;
}