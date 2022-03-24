//https://luxoft.udemy.com/course/datastructurescncpp/learn
//Notes and writes by Bogdan Seceleanu

//Lesson 19. Functions - structure parameter passing
/*
    Pass by value       (uses return to get the result eg. int sum(a,b))
    Pass by address     (does not use return, it uses pointers eg. void swap(x,y)
    Pass by reference   (only in C++) (similar to pass by address in C, but simpler,
                        using "&" in the formal parameters and only simple variables
                        in the actual parameters)
*/

#include <stdio.h>
#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct Test
{
    int A[5];
    int n;
};


//demo for use of & call by reference (&) (only C++)
int area(Rectangle &rect)
{
    rect.breadth = 6;     //demo for use of & call by reference
    return rect.breadth * rect.length;
}


//demo for use of& call by address (* and &)
void changeLenght(Rectangle *p, int newSize)
{
    p->length = newSize;
    //(*p).length = newSize; //-- old school
}


//pass structure with array inside structure as formal parameter
void fun(Test* rz)
{
    rz->A[0] = 15;       //change value of first member of array    
}

int main()
{
   struct Rectangle r = { 10,5 };
   
   cout << r.breadth << endl;   //5
   cout << "Area of rectangle is: " << area(r) << endl;//60 - pass by reference (only C++)
   cout << r.breadth <<endl;   //6

   changeLenght(&r,7);//change length by passing address of what we want to change from structure
   cout << r.length << endl;   //7

   Test t = { {1,2,3,4,5},6 };
   fun(&t);     //actual parameter is address of Test structure
   cout << t.A[0] << endl;      //15
   return 0;
}