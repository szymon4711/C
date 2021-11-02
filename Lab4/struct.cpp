#include <iostream>
#include "string"
using namespace std;

struct samochod{
    string marka;
    string model;
    int rok;
    string kolor;
    int dni;
};

struct cos{
    string marka;
    int ilosc;
};


void fun_1(samochod *sam ,cos *licz, int liczba_sam)
{
    cout << "\nIlosc samochodow danej marki\n";

    for(int j=0; j < liczba_sam; j++)
    {
        int licznik = 0;
        licz[0].marka = sam[j].marka;

        for (int i = 0; i < liczba_sam; i++)
            if (sam[i].marka == licz[0].marka)
                licznik++;


            int count = 0;
        for(int k=0; k < j; k++)
            if (licz[0].marka==sam[k].marka)
                count++;
            if(count>0)
                continue;

        cout << sam[j].marka << " - ";
        cout << licznik << endl;
    }
}


int fun_2(samochod *sam ,cos *licz, int liczba_sam)
{
    licz[0].ilosc = sam[0].rok;
    int licznik;

    for(int i=0; i < liczba_sam; i++)
        if (sam[i].rok < licz[0].ilosc)
        {
            licz[0].ilosc = sam[i].rok;
            licznik = i;
        }

    return licznik;
}

int main()
{
     samochod sam[] = {{"Renault","Captur",2015,"brazowy",300},
                        {"Ford","Focus",2003,"srebrny",360},
                        {"Opel","Corsa",2020,"czarny",50},
                        {"Ford","Fiesta",2010,"bialy",11},
     };

    cos nazwa[] = {{"", }};

    int liczba_sam = (sizeof (sam) / (2 * sizeof (int ) + 3 * sizeof(string)));


    cout << "Marka\tModel \tRok pr \tKolor \tDni do przegladu" << endl << endl;
    for (int i = 0; i < liczba_sam; i++)
       cout << sam[i].marka << "\t" << sam[i].model << "\t" << sam[i].rok << "\t" << sam[i].kolor << "\t" << sam[i].dni << endl;


    cout << "\nNajstarsze auto:\n";
    int indeks = fun_2(sam,nazwa ,liczba_sam);
    cout << sam[indeks].marka << "\t" << sam[indeks].model << "\t" << sam[indeks].rok <<endl;

    fun_1(sam, nazwa, liczba_sam);


    return 0;
}
