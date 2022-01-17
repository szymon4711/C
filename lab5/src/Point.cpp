#include "Point.h"

Pojazd::Pojazd(string nr, string nazwa, int miejsca, string marka, string typ)
        : numer(nr),
        nazwa(nazwa) ,
        ilosc(miejsca),
        marka(marka),
        typ(typ)

        {
    this->pasazerowie = new string [ilosc];

    for (int i = 0; i < ilosc; i++)
        dodaj("PUSTE", i);

}

void Pojazd::dodaj(string info, int miejsce) {
    this->pasazerowie[miejsce] = info;
}

void Pojazd::print() {
    cout << numer << " | " << nazwa << " | " << ilosc << " | " << marka << " | " << typ << endl;


    for(int i = 0; i < ilosc; i++)
        cout << i << ". " << pasazerowie[i] << endl;
}

Pojazd::Pojazd(Pojazd &pojazd) {
    numer = pojazd.numer;
    nazwa = pojazd.nazwa;
    ilosc = pojazd.ilosc;
    pasazerowie = pojazd.pasazerowie;
    marka = pojazd.marka;
    typ = pojazd.typ;
}

string Pojazd::getName() {
    return nazwa;
}

string Pojazd::getLic() {
    return numer;
}

string Pojazd::getBrand() {
    return marka;
}

string Pojazd::getType() {
    return typ;
}

void Pojazd::setName(string name) {
    this->nazwa = name;
}

void Pojazd::setLic(string license) {
    this->numer = license;
}