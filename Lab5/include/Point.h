#ifndef CHECKER_POINT_H
#define CHECKER_POINT_H

#include <iostream>

using namespace std;

class Pojazd {
private:
    string numer;
    string nazwa;
    int ilosc;
    string * pasazerowie;
    string marka;
    string typ;

public:
    Pojazd(string nr, string nazwa, int miejsca, string marka, string typ);

    Pojazd(Pojazd &pojazd);

    void dodaj(string info, int miejsce);

    void print();

    string getName();

    string getLic();

    string getBrand();

    string getType();

    void setName(string name);

    void setLic(string license);
};



#endif //CHECKER_POINT_H