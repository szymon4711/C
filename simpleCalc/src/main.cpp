#include <iostream>
#include <cstring>
#include "../include/Calc.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (strcmp(argv[1],"add") == 0)
    {
        if (argc != 4)
            error();

        int x,y;
        x = stoi(argv[2]);
        y = stoi(argv[3]);

        add(x,y);
    }

    else if (strcmp(argv[1],"subtract") == 0)
    {
        if (argc != 4)
            error();

        int x,y;
        x = stoi(argv[2]);
        y = stoi(argv[3]);

        subtract(x,y);
    }

    else if (strcmp(argv[1] ,"volume") == 0)
    {
        if (argc != 6)
            error();

        int x,y,h,H;
        x = stoi(argv[2]);
        y = stoi(argv[3]);
        h = stoi(argv[4]);
        H = stoi(argv[5]);

        volume(x,y,h,H);
    }

    else if (strcmp(argv[1],"help") == 0)
        help();

    else
        error();

    return 0;
}