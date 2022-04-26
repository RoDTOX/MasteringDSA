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

void Set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int Average(struct Array arr)
{
    int sum = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum / arr.length;
}

int main()
{   
    struct Array arr = {{23,12,10,15,45,32},6};

    cout << Get(arr, 1) << endl << endl;    // 12
    
    Set(&arr, 5, 9);                    // 23,12,10,15,45,9
    Display(arr);

    cout << endl << Max(arr) << endl;   // 45

    cout << endl << Min(arr) << endl;   // 9 (added value 9 from above Set function)

    cout << endl << Sum(arr) << endl;   // 114

    cout << endl << Average(arr) << endl;   // 19

    return 0;
}