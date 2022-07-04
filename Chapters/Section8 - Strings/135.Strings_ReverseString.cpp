//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
    Strings

    Diff between lower can uppercase is 32.
    a-97    A-65
    z-122   Z-90
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


void ReverseString(const char x[])
{
    int i;
    char* a = (char*)calloc(sizeof(x), sizeof(x));   //allocates memory and initializes all bits to zero- or use malloc and b[0] = '\0';
    
    
    int vowels = 0, consonants = 0, words=0;
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (i = 0; x[i] != '\0'; i++)
    {
     //to find length of string-> i   
    }

    if (x[i] == '\0')
    {
        for (int j=0; j < i; j++)
        {
            a[j] = x[i-j-1];//-1 because last char is '\0'
        }
        //a[i] = '\0';
    }

    printf("Text: %s; Reverse: %s\n", x, a);
    a = NULL;
    free(a);
}


int main(void)
{   
    ReverseString("python");
    return 0;
}