#include <iostream>
using namespace std;

class prostopadloscian{
public:

    double a;
    double b;
    double h;

    double wynik(){
        double Pp = 2 * a * b + 2 * a * h + 2 * b * h;
        return Pp;
    }
};

int main()
{
    prostopadloscian pole = {4.0, 5.0, 11.1,};
    double polePow = pole.wynik();
    cout << polePow;

    return 0;
}
