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

void FindMissingElements(struct Array a)
{
    //Element: 2,3,5,6,9,11
    //Index:   0,1,2,3,4,5

    int diff = a.element[0];
    for (int i = 0; i < a.length; i++)
    {
        while (a.element[i] - i > diff)
        {
            printf("Missing element: %d\n", i + diff);
            diff++;
        }
    }
}

void FindMissingElements_Unsorted(struct Array a,int lowest, int highest)
{
    int* hashTable = (int*)malloc(sizeof(int) * highest);

    for (int i = 0; i < a.length; i++)
    {
        hashTable[a.element[i]] = 1;
    }
    for (int i = lowest; i < highest; i++)
    {
        if (hashTable[i] != 1)
        {
            printf("Missing value: %d\n", i);
        }
    }
}

void FindDuplicateElements(struct Array a)
{
    int counter = 0;
    for (int i = 0; i < a.length; i++)
    {
        while (a.element[i] == a.element[i + 1])
        {
            counter++;
            i++;
        }
        if (counter > 0)
        {
            printf("duplicate found for %d, %d times.\n", a.element[i-1], counter+1);
            counter = 0;//reset
        }
    }
}

/*Find elements in the array that added up get to sum value
Time Complexity: O(n2), uses more time. For less time, but more space, we `ll try hashtable method below.*/
void FindSumElements(struct Array a, int sum)
{
    for (int i = 0; i < a.length; i++)
    {
        for (int j = i+1; j < a.length; j++)
        {
            if (a.element[i] + a.element[j] == sum)
            {
                printf("Sum of elements: %d + %d = %d\n", a.element[i], a.element[j], sum);
            }
        }
    }
}

/*Find elements in the array that added up get to sum value
Time Complexity: O(n)*/
void FindSumElements_Hash(struct Array a, int sum, int  max_val)
{
    int* H = (int*)malloc(sizeof(int) * (max_val+1));
    for (int x = 0; x < max_val + 1; x++)
    {
        H[x] = 0;
    }


    for (int i = 0; i < a.length; i++)
    {
        if (H[sum - a.element[i]] > 0 && sum - a.element[i] >=0)
        {
            printf("Hash: Found Sum of elements: %d + %d = %d\n", a.element[i], sum - a.element[i], sum);
        }
        H[a.element[i]]++;
    }
}

void Find_Min_Max(struct Array a, struct Array* out)
{
    int min = a.element[0];
    int max = a.element[0];

    for (int i = 1; i < a.length; i++)
    {
        if (a.element[i] < min) min = a.element[i];
        else if (a.element[i] > max) max = a.element[i];
    }
    out->element[0] = min;
    out->element[1] = max;
}

int main(void)
{   
    struct Array arr1_S = { {2,3,5,6,9,11},6 };  //sorted array
    struct Array arr2 = { {7,3,1,9,12,10},6 };  //sorted array
    struct Array arr3_S = { {6,6,8,8,10,12,15,15,15,15},10 };  //sorted array
    struct Array arr_sum = { {6,3,8,10,16,7,5,2,9,14},10 };

    struct Array min_max_in = { {5,8,3,9,6,2,10,7,-1,4},10 };  //sorted array
    struct Array min_max_out = { {0,0},2 };  //output array for min max function

    FindMissingElements(arr1_S);

    cout << endl;

    FindMissingElements_Unsorted(arr2,1,12);

    cout << endl;

    FindDuplicateElements(arr3_S);

    cout << endl;

    FindSumElements(arr2, 19);

    cout << endl;

    FindSumElements(arr_sum, 10);

    cout << endl;

    FindSumElements_Hash(arr_sum, 10, 16);

    cout << endl;

    Find_Min_Max(min_max_in, &min_max_out);
    Display("MinMax: ", min_max_out);

    return 0;
}