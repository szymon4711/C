#include "Figure.h"



Circle::Circle( double r) : r(r){

}

double Circle::getArea() {
    return r*r*3.14;
}