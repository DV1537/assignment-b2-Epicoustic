#include "vld.h"
#include "vector2.h"
#include "shape.h"
#include "line.h"
#include "point.h"
#include "triangle.h"
#include "polygon.h"
#include "figure.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>

float roundedNumber(float n);

int main(int argc, const char *argv[]){
	std::ifstream myReadFile(argv[1]);
	std::string line = "";
	Vector2 coords;
	Figure figures;
	while (!(myReadFile.eof())){
		//reads line by line
		while (getline(myReadFile,line)){
			std::stringstream ss(line);
			if(!(coords.readVertices(ss))){
				std::cout << "Invalid input!";
				return 1;
			}
			Vertices *arrPtr;
			arrPtr = coords.getArrPointer();
			int verticeAmount = coords.getSize();
			Shape* shape;

			if(verticeAmount == 1){
				shape = new Point(arrPtr,verticeAmount);
			}

			if(verticeAmount == 2){
				shape = new Line(arrPtr,verticeAmount);
			}

			if(verticeAmount == 3){
				shape = new Triangle(arrPtr,verticeAmount);
			}
			
			if(verticeAmount >= 4){
				shape = new Polygon(arrPtr,verticeAmount);
			}
			//Saves shape into a "shapearray" and adds position
			figures.addShape(shape);
			//Adds vertices to vectorarray and pointer to respective shape array
			figures.addArr(coords);
		}
	}
	figures.printClosest();
	myReadFile.close();
	std::cin.get();
}

float roundedNumber(float n){
	float roundedNumber = roundf(n * 1000) / 1000;
	return roundedNumber;
}