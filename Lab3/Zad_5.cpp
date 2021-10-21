#include <iostream>
using namespace std;

double sr(int *x, int *y)
{
    double sred;
    sred = (double)(*x + *y) / 2;
    return sred;
}

int main()
{
    int x, y;
    cout << "Wprowadz dwie liczby aby obliczyc srednia\n";
    cin >> x;
    cin >> y;
    int *wsk_x = &x;
    int *wsk_y = &y;
    cout << "Srednia = " << sr(wsk_x, wsk_y);
    
    return 0;
}