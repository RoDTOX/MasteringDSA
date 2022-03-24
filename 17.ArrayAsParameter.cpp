//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

//Lesson 17. Functions - array parameter passing
/*
    Pass by value       (uses return to get the result eg. int sum(a,b))
    Pass by address     (does not use return, it uses pointers eg. void swap(x,y)
    Pass by reference   (only in C++) (similar to pass by address in C, but simpler,
                        using "&" in the formal parameters and only simple variables
                        in the actual parameters)
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int * fun(int size)    //int * can be replaced by int[], diff. is that we clearly specify we return only int array ps: some compilers don`t accept that
{
    return (int*)malloc(sizeof(int) * size);
}

int main()
{
    int* A = fun(5);
    cout << A << endl;  //random address in heap 00000198C5E43FA0

    return 0;
}