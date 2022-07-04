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


void FindDuplicates_Bitwise(const char A[])
{
    //Input: finding\0

    int i;
    //next we need a hash table of 26 bits(4bytes x8 = 32 bits), that represent all small-capital letters a-z (97->122)
    int* H = (int*)calloc(4,4);   //allocates memory and initializes all bits to zero- or use malloc and b[0] = '\0';
                                    //long int Hi = 0; // same memory allocation as above, but in stack
    //long int H = 0;  //H represents all bits repr. of chars in A
    long int x = 0; //x here is used to do masking with H (or ing)
    
    if (H == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 'a');  //bitshift 5 bits left for letter 'f' in "finding"
        // check if at bit 5, the H has already a 1, if yes, then that character is duplicate, else make it as 1.
        if ((x & *H) > 0)
        {
            cout << A[i] << " is duplicate." << endl;
        }
        else
        {
            *H = x | *H;
        }
        //at endo fo this for, i is repr. length of the string
    }

    H = NULL;
    free(H);
}


int main(void)
{   
    FindDuplicates_Bitwise("finding");
    return 0;
}