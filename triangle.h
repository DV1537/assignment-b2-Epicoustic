#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector2.h"
#include "shape.h"

class Triangle : public Shape
{
    public:
        Triangle(Vertices *sentCoord,const int size);
		~Triangle();
        const char* getType();
        float area();
        float circumference();
        Vertices position();
        bool isConvex();
        Vertices* getArrPointer();
        int getSize();
    private:
        Vertices* tempVector;
        int arrSize;
};

#endif