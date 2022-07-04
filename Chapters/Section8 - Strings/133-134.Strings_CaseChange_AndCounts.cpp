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

void LowerCase(const char x[])
{
    char* a = (char*)malloc(sizeof(x));
    int i;
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (i = 0; x[i] != '\0'; i++)
    {
        a[i] = x[i]+32;
    }
    a[i] = '\0';

    printf("Lowered case text is: %s\n", a);
    a = NULL;
    free(a);
}

void SwitchCase(const char x[])
{
    char* a = (char*)calloc(sizeof(x),sizeof(x));   //function allocates memory and initializes all bits to zero
    int i;

    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (i = 0; x[i] != '\0'; i++)
    {
        if (x[i] >= 65 && x[i] <= 90) { a[i] = x[i] + 32; } //if example with decimal representation
        else if (x[i] >= 'a' && x[i] <= 'z') { a[i] = x[i] - 32; } //if with "char" representation
        else
        {
            a[i] = x[i];    //without this else, the special character like "space"[32] is ignored.
        }
    }
    a[i] = '\0';

    printf("Swapped case text is: %s\n", a);
    a = NULL;
    free(a);
}

void CountVowelsConsonantsWords(const char x[])
{
    char* a = (char*)calloc(sizeof(x), sizeof(x));   //allocates memory and initializes all bits to zero
    int i;
    int vowels = 0, consonants = 0, words=0;
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (i = 0; x[i] != '\0'; i++)
    {
        if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u' || x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U') { vowels++; }
        else if ((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z')) { consonants++; } //here we check if are characters, except above ones
        else if (x[i] == ' ' && x[i-1]!= ' ') words++;  //avoid counting words sepparated by multiple white spaces
    }
    a[i] = '\0';

    printf("Text: %s; Words: %d; Vowels: %d; Consonants: %d\n", x, words+1, vowels, consonants);
    a = NULL;
    free(a);
}


int main(void)
{   
    LowerCase("WELCOME");
    SwitchCase("bOGDAN sECELEANU");
    CountVowelsConsonantsWords("Ana Are     Mere");
    return 0;
}