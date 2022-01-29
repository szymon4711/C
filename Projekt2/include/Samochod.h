#ifndef JIPP2_SAMOCHOD_H
#define JIPP2_SAMOCHOD_H

#include "Pojazd.h"

class Samochod : public Pojazd {
private :
    /**
     * Dodatkowy wskaznik, ktory bedziemy dodatkowo zwalniac w destruktorze
     */
    int *tmp = new int;
public:
    /**
     * Konstruktor dla klasy Samochod, gdzie rowniez pole type jest zmieniany na Samochod
     * @param name nazwa
     * @param model model
     * @param year rok produkcji
     */
    Samochod(const string &name, const string &model, int year, int price);

    /**
    * Destruktor dla klasy Samochod
    */
    ~Samochod();

    /**
     * Funkcja wykorzystujaca polimorfizm, wypisujaca wszystkie pola klasy
     */
    void printAll();

    /**
    * Funkcja pomagajaca przy zapisie do bazy danych
    * @return wypisane wszystkie pola klasy w zmiennej string
    */
    string tofile();

    /**
     * Setter dla pola salon
     * @param salon nowy salon, ktorym zostanie zamieniony obecny
     */
    void set_salon(const string salon);

    /**
     * Getter dla pola salon
     * @return pole salon typu string
     */
    string get_salon();

    /**
     * Funkcja wykorzystujaca przeciazenie operatorów, sumujaca pola price dwoch najnowszych obiektow klasy Samochod
     * @param rhs prawa strona operacji dodawania, drugi obiekt klasy Samochod
     * @return suma pól price dwoch obiektow klasy Samochod
     */
    int operator+(const Samochod &rhs);

    /**
     * Funkcja wykorzystujaca przeciazanie metod, sluzaca do policzenia, ile dany obiekt klasy Samochod przyniesie przychodu jesli zostanie kupiony n razy
     * @param number ile razy zostal kupiony (przeliczanie)
     */
    void multiply(int number);

    /**
     * Funkcja wykorzystujaca przeciazanie metod, sluzaca do policzenia, ile dany obiekt klasy Samochod bedzie kosztowal po obnizce
     * @param sale wysokosc znizki
     */
    void steal(double sale);
};


#endif //JIPP2_SAMOCHOD_H
