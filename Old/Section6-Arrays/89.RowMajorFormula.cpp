//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

/*
Representation of arrays in memory is governed by RowMajorFormula.

AddressOfAnyElement=L0+(i*n+j)*w

    where,
    L0  -   is starting of array address;
    i,j -   location of desired value (row, column);
    m,n -   dimensions of array (row, column);
    w   -   size of array data type

    e.g How the compiler gets the address of a array value:
    Given int array x of size i,j=4,3, get address of element m,n = 1,2; Start address is L0=200. Array data size 1byte.
    Address = 200 + 4*2+3 = 211

*/
#include <stdio.h>

int main()
{
    unsigned int x[4][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10,11,12}
    };
    unsigned int y[2][3] =
    {
        {11,12,13},
        {14,15,16}
    };

    printf("%lubytes\n", sizeof(int));

    //To extract value by using pointers, in 2D and 3D arrays, we need to double or tripe dereference a pointed value, since return value of array element is an address.
    printf("%u\n", *x[3]);
    printf("%u\n", **(x + 3));
    printf("%u\n", *(*(x + 3)));
    printf("%u\n", *(*(x + 2) + 3));

    printf("-----------------------\n");

    printf("%u\n", y[0][5]);            // atypical value getter
    printf("%u\n", *(*(y + 1) + 2));    //atypical pointer usage to dereference
    printf("%u\n", y[1][2]);            //classical value getter
    printf("%u\n", (unsigned int)(*(y + 1) + 2));        //atypical pointer usage to dereference
    printf("%u\n", (unsigned int)(&y[1][2]));        //classical address getter

    

    return 0;
}