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
    int* A;
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
}

int main()
{   
    struct Array arr = {};

    cout << "Enter size of array: " << endl;
    cin >> arr.size;
    arr.A = (int*)malloc(sizeof(int) * arr.size);

    cout << "Enter how many elements to use out of " << arr.size << ": " << endl;
    cin >> arr.length;
    while (arr.length > arr.size)    {
        

        cout << "Length of array elements bigger than the declared array size." << endl;
        cout << "Enter how many elements to use out of " << arr.size << ": " << endl;
        cin >> arr.length;
        if (arr.length < arr.size) break;
    }
    
    cout << "Enter value for each desired element: " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cin >> arr.A[i];
    }
    Display(arr);
    

    

    
    
    arr.A = NULL;
    free(arr.A);

    return 0;
}