//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
    Strings

    Diff between lower can uppercase is 32.
    a-97    A-65
    z-122   Z-90

    Bitwise operations:
    - left shift <<
    - bits OR ing
    - bits AND ing
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void perm(const char S[], int k)
{
    static int A[10] = { 0 };
    static char Res[10] = { 0 };
    int i=9999;

    if (S[k] == '\0') {
        Res[k] = '\0'; 
        cout << Res << endl; 
    }

    for (i = 0; S[i] != '\0'; i++)
    {
        if (A[i] == 0) { 
            Res[k] = S[i]; 
            A[i] = 1; 
            perm(S, k + 1);
            A[i] = 0;
        }
    }   
}


int main(void)
{   
    perm("ABC", 0);
    return 0;
}