#include <stdio.h>
#include <iostream>
using namespace std;

//Lesson 13. Functions
/*
    Monolithic programming - all in main
    Procedural or Modular is using functions to group instructions :)
*/


//prototype/header/signature of function
int add(int a, int b) //formal parameters a,b
{
    return a + b; //definition and declaration of functions
}

int main()
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);//x,y - actual parameters of add function

    cout << z << endl;
    
    return 0;
}