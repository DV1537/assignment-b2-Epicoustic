#include "triangle.h"
#include <cmath>
#include <iostream>
#include "vector2.h"

Triangle::Triangle(Vertices *sentCoord,const int size){
    arrSize = size;
    tempVector = new Vertices[arrSize];
    for(int i = 0; i < arrSize; i++)
        tempVector[i] = sentCoord[i];
}

Triangle::~Triangle() {
	delete[] tempVector;
}

const char* Triangle::getType(){
    return "Triangle";
}

float Triangle::area(){
    float area = ((tempVector[1].x - tempVector[0].x)
    *(tempVector[2].y - tempVector[0].y)
    - (tempVector[2].x - tempVector[0].x)
    * (tempVector[1].y - tempVector[0].y))/2.0;
    return fabs(area);
}

//Calculates 6perimeter with distance formula

float Triangle::circumference(){
    float circum = 0;
    int j = 1;
    for(int i = 0; i < arrSize; i++){
        circum += sqrt(pow(tempVector[j].x - tempVector[i].x,2.0)
        + (pow(tempVector[j].y - tempVector[i].y,2.0)));
        j++;
    }
    j--;
    circum += sqrt(pow(tempVector[j-1].x - tempVector[0].x,2.0)
        + (pow(tempVector[j].y - tempVector[0].y,2.0)));
    return fabs(circum); 
}

int Triangle::getSize(){
	return arrSize;
}

Vertices Triangle::position(){
    Vertices centroid;
    float centerX = 0;
    float centerY = 0;
    for(int i= 0; i < arrSize;i++){
        centerX += tempVector[i].x;
        centerY += tempVector[i].y;
    }
    centroid.x = centerX/arrSize;
    centroid.y = centerY/arrSize;
    return centroid;
}

bool Triangle::isConvex(){
    return true;
}

Vertices* Triangle::getArrPointer(){
    return tempVector;
}