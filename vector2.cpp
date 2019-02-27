#include "vector2.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Vector2::Vector2(){
    arraySize = 5;
    maxSize = arraySize;
    vectorArray = new Vertices[arraySize];
    combinedSize = 0;
}

Vector2::Vector2(const Vector2& v){
    maxSize = v.maxSize;
    arraySize = v.arraySize;
    combinedSize = arraySize;
    vectorArray = new Vertices[maxSize];
    for (int i = 0; i < arraySize; i++){
        vectorArray[i] = v.vectorArray[i];
    }
}

Vector2::~Vector2(){
    if (vectorArray) {
        delete[] vectorArray;
        vectorArray = nullptr;
    }
}

Vertices* Vector2::getArrPointer(){
    return vectorArray;
}

void Vector2::expandVectorArray(){
    int oldSize = maxSize;
    maxSize *= 2;
    Vertices *tempArray = new Vertices[maxSize];
    memcpy(tempArray, vectorArray, sizeof(Vertices) * oldSize);
    delete [] vectorArray;
    vectorArray = tempArray;
}

Vector2 Vector2::operator+(const Vector2 &v) {
    combinedSize = this->arraySize + v.arraySize;
    int firstVerticeLength = this->arraySize;
    while(combinedSize >= maxSize){
        this->expandVectorArray();
    }

    int j = 0;

    for (int i = firstVerticeLength; i < combinedSize; i++) {
        this->vectorArray[i] = v.vectorArray[j];
        j++;
    }
    this->arraySize = combinedSize;
    return *this;
}

//Resets size for + operator overload to properly index
void Vector2::resetSize(){
    this->arraySize = 0;
}

Vector2& Vector2::operator=(const Vector2 &v){
    if (!(this == &v)) {
        delete[] vectorArray;
        vectorArray = nullptr;
        maxSize = v.maxSize;
        arraySize = v.arraySize;
        combinedSize = arraySize;
        vectorArray = new Vertices[v.combinedSize];
        for (int i = 0; i < v.combinedSize; i++) {
            this->vectorArray[i] = v.vectorArray[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out,const Vector2& v){
	for (int i = 0; i < v.arraySize; i++){
		out << v.vectorArray[i].x << " " << v.vectorArray[i].y << std::endl;
	}
	return out;
}

int Vector2::getSize(){
    return arraySize;
}

//Reads values and checks validity

bool Vector2::readVertices(std::stringstream &ss) {
    int iteration = 0;
    bool readValid = true;
    while (!(ss.fail() || ss.eof())) {;
        ss >> this->vectorArray[iteration].x >> this->vectorArray[iteration].y;
        if (this->arraySize >= this->maxSize) {
            //expands maxsize
            this->expandVectorArray();
        }
        iteration++;
        
    }
    if(ss.fail()){
        readValid = false;
    }
    this->arraySize = iteration;
    return readValid;
}