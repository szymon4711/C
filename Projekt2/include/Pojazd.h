#ifndef JIPP2_POJAZD_H
#define JIPP2_POJAZD_H
#include <iostream>
using namespace std;


class Pojazd {
protected:
    /**
     * Pole typu string przechowujace nazwe
     */
    string name;
    /**
     * Pole typu string przechowujace model
     */
    string model;
    /**
     * Pole typu int przechowujace rok produkcji
     */
    int year;
    /**
     * Pole typu int przechowujace cene
     */
    int price = 0;
    /**
     * Pole typu string przechowujace typ
     */
    string type = "Brak";
    /**
    * pole typu string, ktore przechowuje informacje, do jakiego salonu dany obiekt klasy Samochod nalezy
    */
    string salon = "Brak";
public:
    /**
     * Funkcja umozliwiajaca polimorfizm
     */
    virtual void printAll() = 0;

    /**
     * Getter dla pola name
     * @return pole name typu string
     */
    string get_name();

    /**
     * Getter dla pola model
     * @return pole model typu string
     */
    string get_model();

    /**
     * Konstruktor dla klasy Pojazd
     * @param name      nazwa pojazdu
     * @param model     model
     * @param year      rok produkcji
     * @param price     cena
     * @param typ       type
     */
    Pojazd(const string &name, const string &model, int year, int price, const string &type);
};

/**
 * Szablon T, ktory zawiera funkcje sum_fun, wypisujaca sume parametrow wywolywania programu
 * @tparam T typename, ustalony przy wywolywaniu funkcji
 * @param x pierwszy parametr wywolywania programu
 * @param y drugi parametr wywolywania programu
 * @return suma parametrow wywolywania programu typu T
 */
template<typename T>
T sum_fun(T x, T y) {
    return x + y;
}

#endif //JIPP2_POJAZD_H
