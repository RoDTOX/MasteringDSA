#include <stdio.h>
#include <iostream>
using namespace std;

//Lesson 15. Functions - parameter passing
/*
    Pass by value       (uses return to get the result eg. int sum(a,b))
    Pass by address     (does not use return, it uses pointers eg. void swap(x,y)
    Pass by reference   (only in C++) (similar to pass by address in C, but simpler, 
                        using "&" in the formal parameters and only simple variables 
                        in the actual parameters)
*/


//Pass by address
void swap_pba(int* x, int* y) //pass by address
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_pbr(int &x, int &y) //pass by reference (c++)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 12;
    int b = 34;
    cout << a << b << endl; //1234

    swap_pba(&a, &b);       //pass by address
    cout << a << b << endl; //3412

    swap_pbr(a,b);          //pass by reference (c++)
    cout << a << b << endl; //1234

    return 0;
}