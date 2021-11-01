#include <iostream>
#include <math.h>
using namespace std;

class Kula{
public:

    double r;

    double wynik(){
        double V = (pow(r,3) * M_PI) * 4/3;
        return V;
    }

};

int main()
{
    Kula obj = {5.0};
    double objetosc = obj.wynik();
    cout << objetosc;

    return 0;
}
