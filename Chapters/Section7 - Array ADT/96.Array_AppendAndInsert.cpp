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

void Append(struct Array * arr_local, int x)
{
    if (arr_local->length < arr_local->size)
    {
        arr_local->A[arr_local->length++] = x;
        //arr_local->length++;
    }
}

void Insert(struct Array *arra, int index, int value)
{
    if ((index > 0) && (index <= arra->size))
    {
        if (index <= arra->length)
        {
            for (int i = arra->length; i > index; i--)
            {
                arra->A[i] = arra->A[i - 1];
            }
            arra->length++;
            arra->A[index] = value;
        }
        else
        {
            arra->length = index+1;
            arra->A[index] = value;
        }
        
        
    }
    else
    {
        cout << "Insert function: argument 'index' is invalid." << endl;
    }
}

void Delete(struct Array *arra, int index)
{
    if (index <= arra->length)
    {
        for (int i = index; i < arra->length; i++)
        {
            arra->A[i] = arra->A[i + 1];
        }
        arra->length--;
    }
    
}

int main()
{   
    //struct Array arr = AddElements();
    struct Array arr = {{2,3,4,5,6},10,5};
    Display(arr);
    Insert(&arr, 4, 1);
    Display(arr);
    Delete(&arr, 2);
    Display(arr);
    return 0;
}