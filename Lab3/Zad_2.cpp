#include <iostream>
#include <time.h>
#include <cstdlib>

int los(int x, int y)
{
    int z = (std::rand()%(y-x+1) + x);
    return z;
}

int main()
{
    srand(time(NULL));
    int x,y;
    std::cout << "Wprowadz przedzial z jakiego zostanie wylosowana liczba\n";
    std::cin >> x;
    std::cin >> y;
    std::cout << los(x,y) << std::endl;
    return 0;
}
