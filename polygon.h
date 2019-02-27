#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector2.h"


class Polygon : public Shape
{
    public:
        Polygon(Vertices *sentCoord,const int size);
		~Polygon();
        const char* getType();
        float area();
        float circumference();
        bool isConvex();
        Vertices position();
        float distance(Shape &s);
        Vertices* getArrPointer();
        int getSize();
    private:
        Vertices centroid;
        void initializeMinMax(float& miX,float& miY,float& maX,float& maY);
        Vertices* tempVector;
        int arrSize;
        float crossProduct(int index);
        Vertices boundingBoxCenter();
        bool convex;
};

#endif