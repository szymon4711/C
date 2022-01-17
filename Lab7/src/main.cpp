#include <iostream>
#include "Figure.h"

using namespace std;


int main()
{
    Figure *circle = new Circle(10);
    cout << "Circle area: " << circle->getArea() << endl;

    return 0;
}
