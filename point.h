#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include "vector2.h"

class Point : public Shape
{
    public:
        Point(Vertices *sentCoord,const int size);
		~Point();
        float area();
        const char* getType();
        float circumference();
        bool isConvex();
        Vertices position();
        Vertices* getArrPointer();
        int getSize();
    private:
        Vertices* tempVector;
        int arrSize;
};

#endif