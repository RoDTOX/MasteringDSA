// FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

//recursive function
int simpleRecursion(int n)
{
    if (n > 0)
    {
        cout << n << endl; //this is called at recursive function call (tail recursion)
        simpleRecursion(n - 1);
        cout << n << endl; //this is called at recursive function return (head recursion)
    }
    return n;
}


// indirect recursion
/*
Here we call indirectRecurseA that calls indirectRecurseB, and so on, in a circular manner, but with reduction of N, so that it closes at some point.
Reminder: here we have a tail recursion combined with indirect recursion, because we first print and then recurse.
*/
void indirectRecurseB(int n);

void indirectRecurseA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirectRecurseB(n - 1);
    }
}

void indirectRecurseB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        indirectRecurseA(n / 2);
    }
}


// nested Recursion
int nestedRecursion(int n)
{
    if (n > 100) return n - 10;
    else return (nestedRecursion(nestedRecursion(n + 11)));
}


// sum using recursive function
int recursiveSum(int n)
{
    if (n == 0) return 0;
    else return recursiveSum(n - 1) + n;
}


// factorial using recursive function
int factorialRecursive(int n)
{
    if (n == 0) return 1;
    else return factorialRecursive(n - 1)* n;
}


// factorial using iterative function
int factorialIterative(int n)
{
    int result = 1;
    for (int i = n; i > 0; i--)
    {
        result = result * i;
    }

    return result;
}


// exponent using recursion (m^n)
int exponentialRecursive(int m, int n)
{
    if (n == 0) return 1;
    else return exponentialRecursive(m, n - 1) * m;
}



int main()
{   
    cout << "\n-------Simple recursion-------" << endl;
    simpleRecursion(3);  //321 123

    cout << "\n-------Indirect recursion-------" << endl;
    indirectRecurseA(20);

    cout << "\n-------Nested recursion-------" << endl;
    cout << nestedRecursion(99) << endl;

    cout << "\n-------Sum recursion-------" << endl;
    cout << recursiveSum(5) << endl;

    cout << "\n-------Factorial recursion-------" << endl;
    cout << factorialRecursive(4) << endl;

    cout << "\n-------Factorial iterative-------" << endl;
    cout << factorialIterative(4) << endl;

    cout << "\n-------Exponential recursive-------" << endl;
    cout << exponentialRecursive(2,3) << endl;
    
    return 0;
}

