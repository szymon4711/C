#include <iostream>

double fun(int x, int y)
{
    double wynik = (double) (x*y);
    return wynik;
}

double fun(double r)
{
    double wynik = r*r*3.14;
    return wynik;
}

int main()
{
    int x, y;
    double r;
    std::cout << "Wprowadz boki prostokata:\n";
    std::cin >> x;
    std::cin >> y;
    std::cout << "Pole prostokata = " << fun(x,y) << std::endl;
    std::cout << "Wprowadz promien kola:\n";
    std::cin >> r;
    std::cout << "Pole kola = " << fun(r) << std::endl;

    return 0;
}
