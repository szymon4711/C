#include "../include/Samochod.h"

Samochod::Samochod(const string &name, const string &model, int year, int price)
    : Pojazd(name, model, year, price, "Samochod") {}

void Samochod::printAll() {
    cout << "Marka : "   << name << endl
         << "Model : "   << model << endl
         << "Rok pr. : " << year << endl
         << "Cena : "    << price << endl
         << "Typ : "     << type << endl
         << "Salon : "   << salon << endl;
}

string Samochod::tofile() {
    return ("Marka : " + name + "\n"
            "Model : " + model + "\n"
            "Rok pr. : " + to_string(year) + "\n"
            "Cena : " + to_string(price) + "\n"
            "Typ : " + type + "\n"
            "Salon : " + salon + "\n\n");
}

void Samochod::set_salon(const string salon) {
    this->salon = salon;
}

string Samochod::get_salon() {
    return salon;
}

int Samochod::operator+(const Samochod &rhs) {
    return price + rhs.price;
}

void Samochod::multiply(int number) {
    cout << "Po " << number << " zakupach, samochod " << name << " " << model << " przyniesie przychod "
         << price * number << endl;
}

void Samochod::steal(double sale) {
    cout << "Przy promocji o " << sale << " samochod " << name << " " << model << " bedzie kosztowal "
         << price * (1 - sale/100) << endl;
}

Samochod::~Samochod() {
    delete tmp;
}