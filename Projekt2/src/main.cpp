#include "../include/Pojazd.h"
#include "../include/Samochod.h"
#include "../include/Motocykl.h"

#include <vector>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3){
        cout << "Niewlasciwa liczba argumentow" << endl;
        return 0;
    }
    /**
     * Wektor dla obiektow klas Motocykl
     */
    vector<Motocykl> MotocyklVector;
    /**
     * Wektor dla obiektow klas Samochod
     */
    vector<Samochod> SamochodVector;
    /**
     * Wskaznik na obiekt klasy Pojazd
     */
    Pojazd *wsk;
    int choice;
    int choice_v2;
    int choice_v3;
    int motocykl_number = 0;
    int samochod_number = 0;
    int motocykl_limit;
    int samochod_limit;
    int year;
    int price;
    string tmp_name;
    string tmp_model;
    string tmp_salon;
    string tmp_string;
    string name;
    string model;

    try {
        motocykl_limit = stoi(argv[1]);
        samochod_limit = stoi(argv[2]);

    }
    catch (...) {
        cout << "Zle parametry uruchamiania!" << endl;
        return 0;
    }

    if (samochod_limit < 1 || motocykl_limit < 1){
        cout << "Parametry musza byc dodatnie" << endl;
        return 0;
    }

    cout << "Suma miejsc w salonach wynosi : " << sum_fun(samochod_limit, motocykl_limit) << endl
         << "Max Motocykli : " << motocykl_limit << endl
         << "Max Samochodow : " << samochod_limit <<endl;

    while (1)
    {
        cout << "[1] - Dodaj nowy Pojazd" << endl;
        cout << "[2] - Pokaz dany Pojazd" << endl;
        cout << "[3] - Zapisz do bazy danych" << endl;
        cout << "[4] - Usun Pojazd lub caly Salon" << endl;
        cout << "[5] - Koszt dwoch ostatnio dodanych Pojazdow" << endl;
        cout << "[6] - Oblicz cene po obnizce o n %" << endl;
        cout << "[7] - Oblicz przychod po sprzedazy n danych Pojazdow" << endl;
        cout << "[8] - Wyswietl wszystkie Pojazdy" << endl;
        cout << "[10]- Powieksz limit miejsc dla Pojazdow" << endl;
        cout << "[9] - Zakoncz program" << endl;

        try {
            cin >> choice;
            if (cin.fail()) throw 1;
        }
        catch (...) {
            cout << "Nie wpisales int!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1){

            cout << "Jesli chcesz dodac Motocykl, wpisz 1, jesli Samochod, wpisz 2" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {
                if (motocykl_number == motocykl_limit) {
                    cout << "Osiagnieto limit Motocykli" << endl;
                    continue;
                }

                try {
                    cout << "Podaj Marke : ";
                    cin >> name;
                    cout << "Podaj Model : ";
                    cin >> model;
                    cout << "Podaj Rok produkcji : ";
                    cin >> year;
                    cout << "Podaj Cene : ";
                    cin >> price;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales odpowiednich danych!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                MotocyklVector.push_back(Motocykl(name, model, year, price));
                cout << "Podaj, do ktorego salonu chcesz przypisac dany pojazd : ";

                try {
                    cin >> tmp_string;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Bledne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                MotocyklVector.at(motocykl_number).set_salon(tmp_string);
                wsk = &MotocyklVector.at(motocykl_number);
                wsk->printAll();
                motocykl_number++;

            }

            else if (choice_v2 == 2) {

                if (samochod_number == samochod_limit) {
                    cout << "Osiagnieto limit Samochodow" << endl;
                    continue;
                }
                try {
                    cout << "Podaj Marke : ";
                    cin >> name;
                    cout << "Podaj Model : ";
                    cin >> model;
                    cout << "Podaj Rok pordukcji : ";
                    cin >> year;
                    cout << "Podaj Cene : ";
                    cin >> price;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Niewlasciwe dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                SamochodVector.push_back(Samochod(name, model, year, price));
                cout << "Podaj, do ktorego salomu chcesz przypisac dany pojazd : ";

                try {
                    cin >> tmp_string;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Niewlasciwe dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                SamochodVector.at(samochod_number).set_salon(tmp_string);
                wsk = &SamochodVector.at(samochod_number);
                wsk->printAll();
                samochod_number++;

            }

            else {
                cout << "Wybrano niewlasciwa opcje" << endl;
            }
        }

        if (choice == 2) {

            cout << "Wpisz 1, jesli chcesz wybrac Motocykl, a 2, jesli Samochod" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {

                cout << "Ktora pozycje chcesz pokazac?" << endl;

                int which;

                try {
                    cin >> which;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (which < MotocyklVector.size()) {
                    wsk = &MotocyklVector.at(which);
                    wsk->printAll();
                }

                else {
                    cout << "Niewlasciwy element" << endl;
                }

            }

            else if (choice_v2 == 2) {

                cout << "Ktora pozycje chcesz pokazac?" << endl;

                int which;

                try {
                    cin >> which;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (which < SamochodVector.size()) {
                    wsk = &SamochodVector.at(which);
                    wsk->printAll();
                }

                else {
                    cout << "Niewlasciwy element" << endl;
                }
            }
        }

        else if (choice == 3) {

            ofstream output("motocykle.txt");

            if (output.is_open()) {
                for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                    output << i->tofile();
                }
                output.close();
            }

            else {
                cout << "Error on opening file" << endl;
                exit(1);
            }

            ofstream output2("samochody.txt");

            if (output2.is_open()) {
                for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                    output2 << i->tofile();
                }
                output2.close();
            }

            else{
                cout << "Error on opening file" << endl;
                exit(1);
            }
        }

        else if (choice == 4) {

            cout << "Wpisz 1, jesli chcesz usunac Motocykl, 2 jesli Samochod, 3 jesli caly salon" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {
                cout << "Podaj, czy chcesz usunac Motocykl o podanej :" << endl << "1. Marce" << endl << "2. Modelu" << endl;
                try {
                    cin >> choice_v3;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (choice_v3 == 1) {

                    cout << "Podaj Marke Motocykla, ktory chcesz usunac : ";

                    try {
                        cin >> tmp_name;
                        if (cin.fail()) throw 1;
                    }
                    catch (...) {
                        cout << "Niewlasciwe dane!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                        if (tmp_name == i->get_name()) {
                            MotocyklVector.erase(i);
                            motocykl_number--;
                            cout << "Usunieto Motocykl o Marce " << tmp_name << endl;
                            break;
                        }
                    }
                }

                else if (choice_v3 == 2) {

                    cout << "Podaj Model Motocykla, ktory chcesz usunac : ";

                    try {
                        cin >> tmp_model;
                        if (cin.fail()) throw 1;
                    }
                    catch (...) {
                        cout << "Niewlasciwe dane!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                        if (tmp_model == i->get_model()) {
                            MotocyklVector.erase(i);
                            motocykl_number--;
                            cout << "Usunieto Motocykl o Modelu " << tmp_model << endl;
                            break;
                        }
                    }
                }
            }

            else if (choice_v2 == 2) {

                cout << "Podaj, czy chcesz usunac Samochod o podanej :" << endl << "1. Marce" << endl << "2. Modelu" << endl;

                try {
                    cin >> choice_v3;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (choice_v3 == 1) {

                    cout << "Podaj Marke Samochodu, ktory chcesz usunac : ";

                    try {
                        cin >> tmp_name;
                        if (cin.fail()) throw 1;
                    }
                    catch (...) {
                        cout << "Niewlasciwe dane!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                        if (tmp_name == i->get_name()) {
                            SamochodVector.erase(i);
                            samochod_number--;
                            cout << "Usunieto Samochod o Marce " << tmp_name << endl;
                            break;
                        }
                    }
                }

                else if (choice_v3 == 2) {

                    cout << "Podaj Model Samochodu, ktory chcesz usunac : ";

                    try {
                        cin >> tmp_model;
                        if (cin.fail()) throw 1;
                    }
                    catch (...) {
                        cout << "Niewlasciwe dane!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                        if (tmp_model == i->get_model()) {
                            SamochodVector.erase(i);
                            samochod_number--;
                            cout << "Usunieto Samochod o Modelu " << tmp_model << endl;
                            break;
                        }
                    }
                }
            }

            else if (choice_v2 == 3) {

                cout << "Podaj, ktory salon chcesz usunac : ";

                try {
                    cin >> tmp_salon;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Niewlasciwe dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (vector<Motocykl>::iterator i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                    if (tmp_salon == i->get_salon()) {
                        cout << "Usunieto Motocykl " << i->get_name() << " " << i->get_model() << " z salonu " << tmp_salon << endl;
                        MotocyklVector.erase(i);
                        motocykl_number--;
                        i--;
                    }
                }

                for (vector<Samochod>::iterator i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                    if (tmp_salon == i->get_salon()) {
                        cout << "Usunieto Samochod " << i->get_name() << " " << i->get_model() << " z salonu " << tmp_salon << endl;
                        SamochodVector.erase(i);
                        samochod_number--;
                        i--;
                    }
                }
            }
        }

        else if (choice == 5) {

            int suma = 0;

            cout << "Wpisz 1, jesli chcesz wybrac Motocykle, a 2, jesli Samochody" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {
                if (motocykl_number < 2) {
                    cout << "Potrzeba przynajmniej dwoch Motocykli" << endl;
                    continue;
                }
                suma = MotocyklVector.at(motocykl_number - 1) + MotocyklVector.at(motocykl_number - 2);
                cout << "Suma cen dwoch najnowszych Motocykli jest rowna = " << suma << endl;
            }

            if (choice_v2 == 2) {
                if (samochod_number < 2) {
                    cout << "Potrzeba przynajmniej dwoch Samochodow" << endl;
                    continue;
                }
                suma = SamochodVector.at(samochod_number - 1) + SamochodVector.at(samochod_number - 2);
                cout << "Suma cen dwoch najnowszych Samochodow jest rowna = " << suma << endl;
            }

        }

        else if (choice == 6) {

            cout << "Wpisz 1, jesli chcesz wybrac Motocykl, a 2, jesli Samochod" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {

                double sale;

                cout << "Podaj przecene w % : ";

                try {
                    cin >> sale;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales double!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                cout << "Podaj Marke Motocykla, dla ktorego chcesz policzyc cnene po promocji" << endl;

                try {
                    cin >> tmp_name;
                }
                catch (...) {
                    cout << "Niepoprawne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                    if (tmp_name == i->get_name()) {
                        i->steal(sale);
                    }
                }
            }

            if (choice_v2 == 2) {

                double sale;

                cout << "Podaj przecene w % : ";

                try {
                    cin >> sale;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales double!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                cout << "Podaj Marke Samochodu, dla ktorego chcesz policzyc cnene po promocji" << endl;

                try {
                    cin >> tmp_name;
                }
                catch (...) {
                    cout << "Niepoprawne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                    if (tmp_name == i->get_name()) {
                        i->steal(sale);
                    }
                }
            }
        }

        else if (choice == 7) {

            cout << "Wpisz 1, jesli chcesz wybrac Motocykl, a 2, jesli Samochod" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice_v2 == 1) {

                int number;

                cout << "Podaj ilosc sprzedanych Motocykli : ";

                try {
                    cin >> number;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                cout << "Podaj Marke Motocyklu, dla ktorego chcesz policzyc przychod" << endl;

                try {
                    cin >> tmp_name;
                }
                catch (...) {
                    cout << "Niepoprawne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++) {
                    if (tmp_name == i->get_name()) {
                        i->multiply(number);
                    }
                }
            }

            if (choice_v2 == 2) {

                int number;

                cout << "Podaj ilosc sprzedanych Samochodow : ";

                try {
                    cin >> number;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                cout << "Podaj Marke Samochodu, dla ktorego chcesz policzyc przychod" << endl;

                try {
                    cin >> tmp_name;
                }
                catch (...) {
                    cout << "Niepoprawne dane!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++) {
                    if (tmp_name == i->get_name()) {
                        i->multiply(number);
                    }
                }
            }
        }

        if (choice == 8) {
            cout << endl;

            if (!MotocyklVector.empty()) {
                int j=0;
                for (auto i = MotocyklVector.begin(); i < MotocyklVector.end(); i++)
                {
                    wsk = &MotocyklVector.at(j);
                    wsk->printAll();
                    cout << endl;
                    j++;
                }
            }

            if (!SamochodVector.empty()) {
                int j=0;
                for (auto i = SamochodVector.begin(); i < SamochodVector.end(); i++)
                {
                    wsk = &SamochodVector.at(j);
                    wsk->printAll();
                    cout << endl;
                    j++;
                }
            }
        }


        if (choice == 10){

            cout << "Jesli chcesz zwiekszyc miejsce dla Motocykl, wpisz 1, jesli Samochodow, wpisz 2" << endl;

            try {
                cin >> choice_v2;
                if (cin.fail()) throw 1;
            }
            catch (...) {
                cout << "Nie wpisales int!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            int limit;

            if (choice_v2 == 1) {

                cout << "Wybierz o ile ma sie zwiekszyc liczba mijesc dla Motocykli" << endl;

                try {
                    cin >> limit;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if(limit > 0)
                    motocykl_limit += limit;
                else
                    continue;
            }


            else if (choice_v2 == 2) {

                cout << "Wybierz o ile ma sie zwiekszyc liczba mijesc dla Samochodow" << endl;

                try {
                    cin >> limit;
                    if (cin.fail()) throw 1;
                }
                catch (...) {
                    cout << "Nie wpisales int!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if(limit > 0)
                    samochod_limit += limit;
                else
                    continue;
            }

            else {
                cout << "Wybrano niewlasciwa opcje" << endl;
            }
            cout << "Suma miejsc w salonach wynosi : " << sum_fun(samochod_limit, motocykl_limit) << endl
                 << "Max Motocykli : " << motocykl_limit << endl
                 << "Max Samochodow : " << samochod_limit <<endl;
        }





        else if (choice == 9) {
            cout << "Koniec dzialania programu" << endl;
            break;
        }







    }
    delete wsk;
    return 0;
}