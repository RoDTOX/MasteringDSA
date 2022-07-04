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
    int length;
    int size = (sizeof(A) / sizeof(A[0]));
};

void Display(struct Array arra) noexcept
{
    printf("Elements of array are: \n");

    for (int i = 0; i < arra.length; i++)
    {
        printf("%d ", arra.A[i]);
    }
    printf("\n");
}

void Reverse(struct Array *arr)
{
    int temp;
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Reverse2(struct Array* arr)
{
    //23,12,10,15,45,32
    //32 45 15 10 12 23
    int* B = (int*)malloc(arr->length+1 * sizeof(int));
    for (int i = 0, j = arr->length - 1; j>=0; i++, j--)
    {
        B[i] = arr->A[j];
    }
    for (int i = 0; i <= arr->length-1; i++)
    {
        arr->A[i] = B[i];
    }
}

void RotateLeft(struct Array* arr)
{
    //23,12,10,15,45,32
    //12,10,15,45,32,23

    int temp=arr->A[0];
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

int main()
{   
    struct Array arr = {{23,12,10,15,45,32},6};

    Reverse2(&arr);
    Display(arr);   //32 45 15 10 12 23

    RotateLeft(&arr);
    Display(arr);   //45 15 10 12 23 32
    return 0;
}