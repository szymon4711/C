#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void gen(int x,int tab[])
{
    for (int i = 0; i < x; i++)
        tab[i] = rand() % 100 + 1;
    for (int i = 0; i < x; i++)
        cout << tab[i] << endl;
    cout<<endl;
}

void odw(int x, int tab[])
{
    int temp;
    for (int i = 0; i < x / 2; i++)
    {
        temp = tab[x - i - 1];
        tab[x - i - 1] = tab[i];
        tab[i] = temp;
    }

    for (int i = 0; i < x; i++)
        cout << tab[i] << endl;
    cout<<endl;
}


int main()
{
    srand(time(NULL));
    int x;
    cout << "Wprowadz rozmiar tablicy\n";
    cin >> x;
    int *tab = new int[x];
    gen(x,tab);
    odw(x,tab);
    delete [] tab;
    return 0;
}
