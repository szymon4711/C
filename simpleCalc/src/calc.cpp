#include <iostream>
#include "../include/Calc.h"
using namespace std;

void add(int x, int y)
{
    cout << "Wynik dodawania: " << x + y << endl;
}

void subtract(int x, int y)
{
    cout << "Wynik odejmowania: " << x - y << endl;
}

void volume(int x, int y, int h, int H)
{
    double Pole = (double (x + y) / 2) * h * H;
    cout << "Pole graniastoslupa: " << Pole << endl;
}

void help()
{
    cout <<

    "\nSimple calculator\n\n"
    "simpleCalc [nazwa dzialania]\n\n"

    "Dzialania:\n\n"

        "\tadd [x] [y]\n"
            "\t\tDodawanie dwoch liczb ([x] i [y]) calkowitych.\n\n"

        "\tsubtract [x] [y]\n"
            "\t\tOdejmowanie dwoch liczb ([x] i [y]) calkowitych.\n\n"

        "\tvolume [x] [y] [h] [H]\n"
            "\t\tObliczanie objetosci graniastoslupa prostego o podstawie trapezu.\n"
            "\t\t(x,y - dlugosc podstaw trapezu;\n"
            "\t\t h - wysokosc trapezu;\n"
            "\t\t H - wysokosc graniastoslupa;)\n\n"

    "Pomoc:\n\n"

        "\thelp\n"
            "\t\twyswietlenie dokumentacji\n\n"
    ;
}

void error()
{
    cout<< endl << "Error! Cos poszlo nie tak. Sprawdz, czy argumenty zostaly przekazane poprawnie. Aby zobaczyc dokumentacje wpisz \"help\"." << endl;

    string HELP;
    cin >> HELP;

    if(HELP == "help")
        help();

    exit(1);
}