#include "point.h"
#include <iostream>

Point::Point(Vertices *sentCoord,const int size)
{
    arrSize = size;
    tempVector = new Vertices[arrSize];
    for(int i = 0; i < arrSize; i++)
        tempVector[i] = sentCoord[i];
}

Point::~Point() {
	delete[] tempVector;
}

const char* Point::getType(){
	return "Point";
}

float Point::area(){
	return -1;
}

float Point::circumference(){
	return 0;
}

Vertices Point::position(){
	Vertices centroid;
	centroid.x = tempVector[0].x;
	centroid.y = tempVector[0].y;
	return centroid;
}

bool Point::isConvex(){
	return false;
}

Vertices* Point::getArrPointer(){
    return tempVector;
}

int Point::getSize(){
	return arrSize;
}