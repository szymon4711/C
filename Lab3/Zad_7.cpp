#include<iostream>
#include <algorithm>

using namespace std;

void wpr(int tab[], int *x)
{
    for (int i = 0; i < *x; i++)
    {
        cout << "Wprowadz " << i << ". liczbe: ";
        cin >> tab[i];
    }
    for (int i = 0; i < *x; i++)
        cout << tab[i] << endl;

    cout<<endl;
}

void sortowanie(int tab[], int *x)
{
    for (int i = 0; i < *x; i++)
        for (int j = 1; j < *x - i; j++)
            if (tab[j - 1] > tab[j])
                swap(tab[j - 1], tab[j]);

    for (int i = 0; i < *x; i++)
        cout << tab[i] << endl;
}

int main() {
    int x;
    cout << "Wprowadz ilosc elementow w tablicy: ";
    cin >> x;
    int *tab = new int[x];
    wpr(tab, &x);
    sortowanie(tab, &x);
    delete[] tab;
    return 0;
}