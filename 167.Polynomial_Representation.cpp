//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
    Polynomial Representation

    Scope:
    - show how to represent a polynomial in C
    - make operation of addition between two polynomials

*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Element {
    int coef;
    int expo;
};

struct Poly {
    int n_nonzero_elems;    //number of non zero elements
    struct Element* e;
};

int main(void)
{
    int x = 5;

    struct Poly p = {};
    p.n_nonzero_elems = x;
    p.e = new struct Element[p.n_nonzero_elems];

    cout << "Enter polynomial element: ";
    for (int i = 0; i < p.n_nonzero_elems; i++)
    {        
        printf("Enter coeficient and exponent #%d: ",i+1);
        cin >> p.e[i].coef >> p.e[i].expo;
    }

    printf("Polynomial is: p(x) = ");
    for (int i = 0; i < p.n_nonzero_elems; i++)
    {
        printf("%dx^%d ", p.e[i].coef, p.e[i].expo);
        if( i+1 < p.n_nonzero_elems) cout << "+ ";
    }

    return 0;
}