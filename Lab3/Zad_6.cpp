#include<iostream>

using namespace std;

void wpr(int tab[], int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << "Wprowadz " << i << ". element tablicy:";
        cin >> tab[i];
    }

    for (int i = 0; i < x; i++)
        cout << tab[i] << endl;

    cout<<endl;
}

void fun(int tab[],int x)
{
    for (int i = 0; i < x; i++)
        if(tab[i] < 0)
            cout << tab[i] <<endl;
}


int main()
{
    int x;
    cout << "Prosze podaj rozmiar tablicy:\n";
    cin >> x;
    int * tab = new int[x];
    wpr(tab, x);
    fun(tab, x);



    delete [] tab;
    return 0;
}