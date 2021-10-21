#include <iostream>
#include <string>
using namespace std;

void zamiana(string cos)
{
    int swap;
    swap = stoi(cos);
    cout << swap << endl;
}

int main()
{
    string cos;
    cout << "Wprowadz ciag znakow!";
    cin >> cos;

    try
    {
        zamiana(cos);
    }

    catch (out_of_range)
    {
        cout << "zle wprowadzone dane!";
    }

    catch (invalid_argument)
    {
        cout << "Nie wprowadziles liczby!";
    }

    return 0;
}