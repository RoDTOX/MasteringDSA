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
    int A[15];
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

int BinarySearch(struct Array arr, int key)
{
    /*Binary search prerequisite - to be an ordered array
    * 
    */
    int index_low = 0;
    int index_high = arr.length-1;
    int index_mid;
   
    while (index_low <= index_high)
    {
        index_mid = (index_low + index_high) / 2;
        if (key == arr.A[index_mid])
        {
            return index_mid;
        }
        else if (key < arr.A[index_mid])
        {
            index_high = index_mid-1;
        }
        else  
        {
            index_low = index_mid+1;
        }
    }
    return -1;
}

int RecursiveBinarySearch(int a[], int l, int h, int key)
{
    int index_mid;

    if (l <= h)
    {
        index_mid = (l + h) / 2;
        if (a[index_mid] == key)
        {
            return index_mid;
        }
        else if (a[index_mid] < key) //left side
        {
            RecursiveBinarySearch(a, index_mid + 1, h, key);
        }
        else if (a[index_mid] > key) //right side
        {
            RecursiveBinarySearch(a, l, index_mid -1, key);
        }
    }
    else
    {
        return -1;
    }
    
}

int main()
{   
    //struct Array arr = AddElements();
    struct Array arr = {{4,8,10,15,21,25,28,31,36,40,44,48,50,52,56},15,15}; 
    //cout << BinarySearch(arr, 45) << endl;

    cout << RecursiveBinarySearch(arr.A, 0,14,4) << endl;
        

    return 0;
}