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

void Display(struct Array arra)
{
    printf("Elements of array are: \n");

    for (int i = 0; i < arra.length; i++)
    {
        printf("%d ", arra.A[i]);
    }
    printf("\n");
}

void Insert(struct Array *arr, int n)
{
    //4 8 13 16 18 20 25 28 33
    for (int i = arr->length - 1; i >= 0; i--)
    {
        if (n < arr->A[i])
        {            
            arr->A[i + 1] = arr->A[i];
            
        }
        else
        {
            arr->A[i] = n;
            break;
        }
    }
    arr->length++;

    /* While loop also
    int i = arr->length - 1;
    while (n < arr->A[i])
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = n;
    arr->length++;
    */
}

int IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void SortNegativePositive(struct Array* arr)
{
    int i = 0, temp = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0) { i++; }
        while (arr->A[j] >= 0) { j--; }

        if (i < j) 
        {
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

int main(void)
{   
    struct Array arr = {{4,8,13,16,20,25,28,33},8};
    struct Array arrN = { {-1,4,-8,0,13,-16},6 };

    Insert(&arr, 18);
    Display(arr);   

    cout << endl << IsSorted(arr) << endl;

    SortNegativePositive(&arrN);
    Display(arrN);

    return 0;
}