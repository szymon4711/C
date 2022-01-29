#include "../include/Pojazd.h"

Pojazd::Pojazd(const string &name, const string &model, int year, int price, const string &type)
    : name(name) ,
      model(model) ,
      year(year) ,
      price(price) ,
      type(type)
    {}

string Pojazd::get_model() {
    return model;
}

string Pojazd::get_name() {
    return name;
}