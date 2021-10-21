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

void find(int x, int tab[])
{
    for(int i = 1; i < x ; ++i)
        if(tab[0] < tab[i])
            tab[0] = tab[i];
    cout << "Najwieksza wartosc = " << tab[0]<<endl;
}


int main()
{
    srand(time(NULL));
    int x;
    cout << "wprowadz rozmiar tablicy\n";
    cin >> x;
    int *tab = new int[x];
    gen(x,tab);
    find(x,tab);
    delete [] tab;
    return 0;
}
