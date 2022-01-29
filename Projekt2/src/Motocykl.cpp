#include "../include/Motocykl.h"

Motocykl::Motocykl(const string &name, const string &model, int year, int price)
    : Pojazd(name, model, year, price, "Motocykl") {}

void Motocykl::printAll() {
    cout << "Marka : "   << name << endl
         << "Model : "   << model << endl
         << "Rok pr. : " << year << endl
         << "Cena : "    << price << endl
         << "Typ : "     << type << endl
         << "Salon : "   << salon << endl;
}

string Motocykl::tofile() {
    return ("Marka : " + name + "\n"
            "Model : " + model + "\n"
            "Rok pr. : " + to_string(year) + "\n"
            "Cena : " + to_string(price) + "\nTyp : " + type + "\n"
            "Salon : " + salon + "\n\n");
}

void Motocykl::set_salon(const string salon) {
    this->salon = salon;
}

string Motocykl::get_salon() {
    return salon;
}

int Motocykl::operator+(const Motocykl &rhs) {
    return price + rhs.price;
}

void Motocykl::multiply(int number) {
    cout << "Po " << number << " zakupach, motocykl " << name << " " << model << " przyniesie przychod " << price * number << endl;
}

void Motocykl::steal(double sale) {
    cout << "Przy promocji o " << sale << " motocykl " << name << " " << model << " bedzie kosztowal "
         << price * (1 - sale/100) << endl;
}

Motocykl::~Motocykl() {
    delete tmp;
}