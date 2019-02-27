#ifndef FIGURE_H
#define FIGURE_H

#include "Figure.h"
#include "shape.h"
#include "vector2.h"
#include <string>


// getClosest(Shape location, int n) - returns n closest shapes to the location. Make sure that a Shape can be x,y coordinates as well, i.e. a point.
// In the class, you must implement and use a recursive sorting algorithm of your choice
// Your program should read from a file containing multiple shapes (one per line) and return 3 closes shapes to the first one. The file may contain any number of shapes.
// The program should print the points of each shape. One shape per line.


class Figure : public Shape {
    public:
        Figure();
        ~Figure();      
        void printClosest(); 
        void addShape(Shape *s);
        void addArr(Vector2 v);
        Vertices* getBoundingBox();
        void printBoundingBox();
    private:
        void bubbleSort(Shape *firstshape, int n);
        void initializeMinMax(float& miX,float& miY,float& maX,float& maY);
        Shape** getClosest(Shape *location, int n);
        void extendArrays();
        int maxAmountOfShapes;
        //Holds all points
        Vector2 figureVectors;
        Shape **shapeArray;
        Shape **arrangedShapeArr;
        int shapeAmount;
        Vertices* boundingArray;
        Vertices* tempVector;
};

#endif