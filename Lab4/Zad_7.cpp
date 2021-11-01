#include <iostream>
using namespace std;

class Pauza{
public:
    int *tab;

    Pauza();
    ~Pauza();

    void pause(){
        system("PAUSE");
    };
};

Pauza::Pauza()
{
    tab = new int [1024];
}

Pauza::~Pauza()
{
    cout << "\n !Tekst! \n";
    delete [] tab;
}


int main() {
    Pauza cos;
    cos.pause();
    cout << sizeof(cos);

    return 0;
}