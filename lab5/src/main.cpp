#include <iostream>
#include "Point.h"

using namespace std;


int main()
{

    Pojazd car("KOS 4710", "Samochod", 5, "Ford", "Sedan");
    car.dodaj("szymon",3);
    car.print();

    Pojazd car2(car);
    car2.setName("Samochod2");
    car2.setLic("KOS 2707");
    car2.print();

    cout << car2.getBrand() << " | " << car2.getLic() << " | " << car2.getName() << " | " << car2.getType() << endl;




    return 0;
}
