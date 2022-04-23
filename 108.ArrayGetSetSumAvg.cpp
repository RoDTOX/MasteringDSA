//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
    Array ADT represent methods implemented upon arrays data structure:
    a. Space, size and length is implemented in compiler
    b. Operations as display, add, insert, delete, search, delete, are ADT.

*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length= (sizeof(A) / sizeof(A[0])) - 1;
};

void Display(struct Array arra)
{
    printf("Elements of array are: \n");

    for (int i = 0; i < arra.length; i++)
    {
        printf("%d ", arra.A[i]);
    }
    printf("\n");
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length)
    {
        return arr.A[index];
    }
    else
    {
        return -1;
    }
}

int main()
{   
    //struct Array arr = AddElements();
    struct Array arr = {{4,8,10,15,21,32},6};
    //cout << BinarySearch(arr, 45) << endl;

    cout << Get(arr, 9) << endl; // 8
        

    return 0;
}