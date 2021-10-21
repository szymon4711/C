#include<iostream>

using namespace std;

void fun(int x, int *w)
{
    *w = x;
}


int main()
{
    int x=11, y, *wsk = &y;
    fun(x,wsk);
    cout << y;
    
    return 0;
}