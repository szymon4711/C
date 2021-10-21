#include<iostream>
using namespace std;

void dz(int a, int b)
{
    int result;
    if (b == 0)
        throw "Nie dzieli sie przez zero!";

    result = a / b;

    if (a % b != 0)
        throw "W tym zadaniu dzieimy bez ulamkow!";
    cout << "Wynik = " << result;
}

int main()
{
    int a, b;
    cout << "Wprowadz liczby ktore chcesz podzielic ";
    cin >> a;
    cin >> b;

    try
    {
        dz(a, b);
    }

    catch (const char *msg)
    {
        cout << msg;
    }

    return 0;
}