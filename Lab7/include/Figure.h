#ifndef CHECKER_POINT_H
#define CHECKER_POINT_H
#include <iostream>
#include <math.h>
using namespace std;

class Figure {

public:

    virtual double getArea() = 0;
};



class Circle : public Figure{
protected:
    double r;

public:
    Circle(double r);

    double getArea();
};


#endif //CHECKER_POINT_H