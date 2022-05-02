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
    int element[50];    
    int length;
    int size = (sizeof(element) / sizeof(element[0]));
};

void Display(const char message[], struct Array arra)
{
    printf(message);

    for (int i = 0; i < arra.length; i++)
    {
        printf("%d ", arra.element[i]);
    }
    printf("\n");
}


void Union_Sorted(struct Array A, struct Array B, struct Array *C)
{
    int i=0, j=0, k=0;
    while (i < A.length && j < B.length)
    {
        if (A.element[i] < B.element[j])
        {
            C->element[k++] = A.element[i++];
        }
        else if (A.element[i] > B.element[j])
        {
            C->element[k++] = B.element[j++];
        }
        else if (A.element[i] == B.element[j])
        {
            C->element[k++] = B.element[j++];
            i++;    //avoid adding both simmilar numbers from A and B
        }
    }
    for (; i < A.length; i++)
    {
        C->element[k++] = A.element[i];
    }
    for (; j < B.length; j++)
    {
        C->element[k++] = B.element[j];
    }

    C->length = k;
}


void Union_Unsorted(struct Array A, struct Array B, struct Array* C)
{
    for (int i = 0; i < A.length; i++)
    {
        C->element[i] = A.element[i];
        C->length = i+1;
    }

    for (int j = 0; j < B.length; j++)
    {
        for (int k = 0; k < C->length; k++)
        {
            if (B.element[j] == C->element[k])
            {
                break;
            }
            else if ((k == C->length - 1) && (B.element[j] != C->element[k]))
            {
                C->element[k + 1] = B.element[j];
                C->length++;
            }
        }
    }
    
}

void Intersection_Sorted(struct Array A, struct Array B, struct Array* C)
{
    int i = 0, j = 0, k = 0;

    while (i < A.length && j < B.length)
    {
        if (A.element[i] < B.element[j])
        {
            i++;
        }
        else if (A.element[i] > B.element[j])
        {
            j++;
        }
        else if(A.element[i] == B.element[j])
        {
            C->element[k] = A.element[i];
            i++, j++, k++;
        }
    }
    C->length = k;
}

void Intersection_Unsorted(struct Array A, struct Array B, struct Array* C)
{
    int k = 0;
    for (int i = 0; i < A.length; i++)
    {
        for (int j = 0; j < B.length; j++)
        {
            if (A.element[i] == B.element[j])
            {
                C->element[k++] = A.element[i];
               
            }
        }
    }
    C->length = k;
}

void Difference_Sorted(struct Array A, struct Array B, struct Array* C)
{
    int i = 0, j = 0, k = 0;

    while (i < A.length && j < B.length)
    {
        if (A.element[i] < B.element[j])
        {
            C->element[k] = A.element[i];
            i++, k++;
        }
        else if (A.element[i] > B.element[j])
        {
            j++;
        }
        else if (A.element[i] == B.element[j])
        {
            
            i++, j++;
        }
    }
    for (; i < A.length; i++)
    {
        C->element[k++] = A.element[i];
    }
    for (; j < B.length; j++)
    {
        C->element[k++] = B.element[j];
    }
    C->length = k;
}

void Difference_Unsorted(struct Array A, struct Array B, struct Array* C)
{
    int k = 0;
    for (int i = 0; i < A.length; i++)
    {
        for (int j = 0; j < B.length; j++)
        {
            if(A.element[i]==B.element[j])
            {
                break;
            }
            else if (j == B.length - 1 && A.element[i] != B.element[j])
            {
                C->element[k] = A.element[i];
                k++;
            }
        }
    }
    C->length = k;
}

int main(void)
{   
    struct Array arr1_S = { {2,6,10,15,25,30},6 };  //sorted array
    struct Array arr2_S = { {1,3,6,18,25},5 };      //sorted array
    struct Array arr1   = { {15,8,21,30,7,11},6 };  //unsorted array
    struct Array arr2   = { {9,1,21,6,11},5 };    //unsorted array
    struct Array arr3   = { {0},1 };

    Union_Sorted(arr1_S, arr2_S, &arr3);
    Display("Union_Sorted:\n", arr3);  //1 2 3 6 10 15 18 25 30

    cout << endl;

    arr3 = { {0},1 };
    Union_Unsorted(arr1, arr2, &arr3);
    Display("Union_Unsorted:\n", arr3);  //15 8 21 30 7 11 9 1 6

    cout << endl;

    arr3 = { {0},1 };
    Intersection_Sorted(arr1_S, arr2_S, &arr3); //O(n);
    Display("Intersection_Sorted:\n", arr3);  //6 25

    cout << endl;

    arr3 = { {0},1 };
    Intersection_Unsorted(arr1, arr2, &arr3); //O(n^2);
    Display("Intersection_Unsorted:\n", arr3);  //21 11

    cout << endl;

    arr3 = { {0},1 };
    Difference_Sorted(arr1_S, arr2_S, &arr3); //O(n);
    Display("Difference_Sorted:\n", arr3);  //2 10 15 30

    cout << endl;

    arr3 = { {0},1 };
    Difference_Unsorted(arr1, arr2, &arr3); //O(n);
    Display("Difference_Unsorted:\n", arr3);  //15 8 30 7

    return 0;
}