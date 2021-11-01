#include <iostream>
#include <math.h>
using namespace std;

class Figura
{
public:
    int Lwierz;
    int *x, *y;

    Figura(int wierz);
};

Figura::Figura(int wierz)
        :Lwierz(wierz),
        x(new int[Lwierz]),
        y(new int[Lwierz])
{
    for (int i = 0; i < Lwierz; ++i)
    {
        cout << "Wprowadz wspolrzedne wierzcholka.\n";
        cin >> x[i];
        cin >> y[i];
    }
}

int main()
{
    int licz;
    cout << "Wprowadz ilosc wieszcholkow\n";
    cin >> licz;
    Figura fig(licz);

    for(int j = 0; j < licz; j++)
    {
        cout << "Wspolrzedne " << j + 1 << " punktu";
        cout << "(" << fig.x[j] << "," << fig.y[j] << ")" << endl;
    }
    return 0;
}