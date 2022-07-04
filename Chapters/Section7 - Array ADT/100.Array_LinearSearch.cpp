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
    int length;
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

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            /*
            * Linear Search Optimisation: 
            * translocate found value at the beginning of the array
            * Eg. if value is found, move it at the beginning of array (bad is that is time complex)
            * Swap found value at A[0] would NOT be better since 
            * the same value being searched consecutively is very less probable.
            */
            for (int j = i; j > 0; j--)
            {
                arr->A[j] = arr->A[j-1];
            }
            arr->A[0] = key;
            return i;
        }
    }
    return -1;
}

int main()
{   
    //struct Array arr = AddElements();
    struct Array arr = {{2,3,4,5,6},10,5}; 
    Display(arr);

    LinearSearch(&arr, 6);//test translocation
    Display(arr);

    LinearSearch(&arr, 4);//test translocation
    Display(arr);
        

    return 0;
}