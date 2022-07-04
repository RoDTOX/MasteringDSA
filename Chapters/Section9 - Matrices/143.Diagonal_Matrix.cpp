//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
    Matrix arrays

    Scope:
    - create a matrix array
    - set diagonal values, set the rest values to 0

    Conditional for diagonal of a matrix:
    M[i,j]=0; if(i!=j) => diagonal (all values except diagonal must be 0)
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Matrix {
    int A[10][10];
    int n;
};

void Set(struct Matrix* m, int values[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        m->A[i][i] = values[i];
    }
}


void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            cout << m.A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int valori[8] = { 1,2,3,4,5,6,7,8 };
    struct Matrix m = {0};
    m.n = 8;
    Set(&m, valori, 0, 7);
    Display(m);

    return 0;
}