#include <iostream>
#include <math.h>
using namespace std;

class Punkt{
public:

    double x1, y1, x2, y2;
    Punkt();

    double odl(){
        return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    }
};

Punkt::Punkt()
    :x1(1),
    y1(2),
    x2(6),
    y2(11)
{
}

int main()
{
    Punkt odleglosc;
    cout << odleglosc.odl();
    return 0;
}