#include <iostream>
using namespace std;

class FunkcjaKwadratowa{
public:

    double a;
    double b;
    double c;

    void wynik(){
        cout << "f(x)=" << a << "x^2+" << b << "x+" << c ;
    }

};

int main()
{
    FunkcjaKwadratowa obj = {5.5, 4.1, 11};
    obj.wynik();

    return 0;
}
