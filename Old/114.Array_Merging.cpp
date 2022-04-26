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
    int A[50];    
    int length;
    int size = (sizeof(A) / sizeof(A[0]));
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

void Merge(struct Array arr1, struct Array arr2, struct Array *arr3)
{
    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j]) 
        { 
            arr3->A[k++] = arr1.A[i++]; 
        }
        else 
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }

    for (; i < arr1.length; i++)
    {
        arr3->A[k++] = arr1.A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = arr1.length + arr2.length;
}

int main(void)
{   
    struct Array arr1 = {{2,6,10,15,25},5};//sorted array
    struct Array arr2 = {{3,4,7,18,20},5};//sorted array
    struct Array arr3 = {{0},1};

    Merge(arr1, arr2, &arr3);
    Display(arr3);
    return 0;
}