#include "figure.h"
#include "shape.h"
#include "Vector2.h"
#include <iostream>
#include <string>
#include <cmath>

Figure::Figure(){
    shapeAmount = 0;
    maxAmountOfShapes = 4;
    shapeArray = new Shape*[maxAmountOfShapes];
    boundingArray = new Vertices[2];
    //Resets size for + operator overload to properly index
    figureVectors.resetSize();
}

Figure::~Figure(){
    if(shapeArray){
         for (int i = 0; i < shapeAmount; i++) {
             delete shapeArray[i];
         }
         delete[] shapeArray;
    }
	if(boundingArray) {
		delete[] boundingArray;
	}
	//if(tempArr){
	//	delete[] tempArr;
	//}
}

void Figure::printClosest(){
    int n = 3;
    Shape* firstShape = shapeArray[0];
    Shape **arrangedShapeArr;
    arrangedShapeArr = getClosest(firstShape,n);

	// //Prints between 0-3 shapes
	n = shapeAmount;
	if (shapeAmount >= 4) {
		n = 4;
	}
	//Getting the tempvector of each shape with polymorphism
	for (int i = 1; i < n; i++) {
		Vertices* tempVector = arrangedShapeArr[i]->getArrPointer();
		for (int j = 0; j < arrangedShapeArr[i]->getSize(); j++) {
			std::cout << tempVector[j].x << " " << tempVector[j].y << " ";
		}
		std::cout << "\n";
	}
	if (arrangedShapeArr)
		delete[] arrangedShapeArr;
}

Shape** Figure::getClosest(Shape *location, int n){
	Shape **tempArr = new Shape*[n+1];
    bubbleSort(location,shapeAmount); 
    for(int i = 1; i < n+1; i++){
        tempArr[i] = shapeArray[i];
    } 
    return tempArr;
}

// Bubblesorting shapearray based on distance from first shape
void Figure::bubbleSort(Shape *firstshape, int n){
    if (n == 1){
        return; 
    }

    for (int i = 0; i < n-1; i++){
        if (shapeArray[i]->distance(firstshape) > shapeArray[i+1]->distance(firstshape)){
            std::swap(shapeArray[i], shapeArray[i+1]);
        }
    }

    bubbleSort(firstshape,n-1);
}

void Figure::addArr(Vector2 v){
    figureVectors + v;
}

void Figure::addShape(Shape *s){
    shapeAmount++;
    int prevIndex = shapeAmount - 1;
    //Saves shape
    shapeArray[prevIndex] = s;

    if(shapeAmount == maxAmountOfShapes){
        extendArrays();
    }
}

void Figure::extendArrays(){
    //Extend shapeArray
    maxAmountOfShapes *= 2;
    Shape **tempshapeArray = new Shape*[maxAmountOfShapes];
    memcpy(tempshapeArray,shapeArray,sizeof(Shape) * shapeAmount);
    delete [] shapeArray;
    shapeArray = tempshapeArray;
}

void Figure::printBoundingBox(){
    if(shapeAmount == 1){
        std::cout << boundingArray[1].x << " " << boundingArray[0].y;
    }
    else{
        for(int i = 0; i < 2; i++){
            std::cout << boundingArray[i].x << " " << boundingArray[i].y << std::endl;
        }
    }
}

Vertices* Figure::getBoundingBox(){
    tempVector = figureVectors.getArrPointer();
    float minX;
    float minY;
    float maxX;
    float maxY;
    initializeMinMax(minX,minY,maxX,maxY);
    //Top left is index 0
    boundingArray[0].x = roundf(minX * 1000) / 1000;
    boundingArray[0].y = roundf(maxY * 1000) / 1000;
    //Bottom right is index 1
    boundingArray[1].x = roundf(maxX * 1000) / 1000;
    boundingArray[1].y = roundf(minY * 1000) / 1000;
    return boundingArray;
}

//Initialises min/max values

void Figure::initializeMinMax(float& miX,float& miY,float& maX,float& maY){
    miX = tempVector[1].x;
    miY = tempVector[1].y;
    maX = tempVector[1].x;
    maY = tempVector[1].y;

    for(int i = 0; i < figureVectors.getSize();i++){
        if(tempVector[i].x < miX){
            miX = tempVector[i].x;
        }
        else if (tempVector[i].x > maX){
            maX = tempVector[i].x;
        }
        else if (tempVector[i].y < miY){
            miY = tempVector[i].y;
        }
        else if (tempVector[i].y > maY){
            maY = tempVector[i].y;
        }
    }
}
