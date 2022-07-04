
#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{   
    int* p, *q;
    int arr_size = 5;

    p = (int *)(malloc(sizeof(int) * arr_size));
    for (int i = 0; i < arr_size; i++)
    {
        p[i] = i * 2;
        cout << p[i] << endl;
    }

    q = (int*)malloc(sizeof(int) * (arr_size + 1));
    q = p;
    for (int i = arr_size; i < arr_size+1; i++)
    {
        q[i] = i * 2;
        cout << q[i] << endl;
    }

    p = NULL;
    free(p);

    q = NULL;
    free(q);
    

    return 0;
}

