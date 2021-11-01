#include <iostream>
using namespace std;

class Student{
public:

    string imie;
    string nazwisko;
    int numer;
    int pytania;
    int poprawne;

    void wynik(){
        cout << imie << " " << nazwisko << " " << numer << " " << (double) poprawne / (double) pytania * 100;
    }

};

int main()
{
    Student ktos = {"Johny", "Bak", 123456, 16, 11};
    ktos.wynik();

    return 0;
}