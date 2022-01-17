#ifndef CHECKER_POINT_H
#define CHECKER_POINT_H
#include <iostream>
#include <math.h>
using namespace std;

class Node {
private:
    double x, y;

public:

    Node(double x = 0, double y = 0);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node a, Node b);
};

double pointsDistance(Node a, Node b);



#endif //CHECKER_POINT_H