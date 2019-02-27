#ifndef VECTOR2_H
#define VECTOR2_H
#include <fstream>
#include <sstream>

struct Vertices{
    float x,y;
};

struct Vector2
{
    Vector2();
    Vector2(const Vector2& v);
    ~Vector2();
    int getSize();
    Vertices* getArrPointer();
    void expandVectorArray();
    Vector2 operator+(const Vector2 &v);
    Vector2& operator=(const Vector2 &v);
    friend std::ostream &operator<<(std::ostream &out,const Vector2& v);
    bool readVertices(std::stringstream &ss);
    void resetSize();
    private:
        Vertices* vectorArray;
        int arraySize;
        int maxSize;
        int combinedSize;
}; 

#endif