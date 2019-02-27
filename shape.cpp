#include "shape.h"
#include <cmath>
#include "vector2.h"
#include <iostream>

Shape::~Shape(){
}

float Shape::distance(Shape* s){
    Vertices firstShapePos = this->position();
    Vertices secondShapePos = s->position();

    float distance = sqrt((pow((firstShapePos.x - secondShapePos.x), 2)) +
        (pow((firstShapePos.y - secondShapePos.y), 2)));
    return distance;
}

const char* Shape::getType(){
    return "";
}

float Shape::area(){
    return -1;
}

float Shape::circumference(){
    return 0;
}

Vertices Shape::position(){
    Vertices centroid;
    centroid.x = 0;
    centroid.y = 0;
    return centroid;
}

bool Shape::isConvex(){
    return false;
}

Vertices* Shape::getArrPointer(){
    Vertices* tempVector = nullptr;
    return tempVector;
}

int Shape::getSize(){
    return 0;
}