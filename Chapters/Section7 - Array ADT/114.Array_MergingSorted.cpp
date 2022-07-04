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

/*This function merges 2 sorted arrays while keeping the sorting okay.*/
void Merge(struct Array arr1, struct Array arr2, struct Array *arr3)
{
    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length) 
    {
        if (arr1.A[i] < arr2.A[j]) 
        { 
            arr3->A[k++] = arr1.A[i++]; // find smallest value, add it and increment index of the array1
        }
        else 
        {
            arr3->A[k++] = arr2.A[j++]; // find smallest value, add it and increment index of the array2
        }
    }

    //if one of the arrays have elements unadded in the arr3, then loop trough them from remainder i&j and add them.
    for (; i < arr1.length; i++)    
    {
        arr3->A[k++] = arr1.A[i];   //for i if the arr1 has leftovers
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];   //for j if the arr2 has leftovers
    }
    arr3->length = arr1.length + arr2.length;   //update length value of arr3, depending on arr1 and 2 lengths
}

int main(void)
{   
    struct Array arr1 = {{2,6,10,15,25,30},6};//sorted array
    struct Array arr2 = {{1,3,7,18,20},5};//sorted array
    struct Array arr3 = {{0},1};

    Merge(arr1, arr2, &arr3);
    Display(arr3);
    return 0;
}