#include <stdio.h>
#include <iostream>
using namespace std;

//Lesson 11. Pointer to structure
    /*
    struct Rectangle
    {
        int length;
        int breadth;
    };

    struct Rectangle r = { 10,5 };
    struct Rectangle* p = &r;

    (*p).length = 6;
    p->length = 4;

    //11.1 All in heap now:
    struct Rectangle* p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 10;
    p->breadth = 5;
    */

struct Rectangle
{
    int length;     //4bytes
    int breadth;    //4bytes
    short coco;     //2bytes
};

int main(void*)
{
    //12. Practice Pointer to structure
    //Normal structure call
    /*
    struct Rectangle r = { 10,5 };
    cout << r.length << endl;
    cout << r.breadth << endl;

    //Pointer to a structure
    Rectangle* p = &r;
    cout << p->length << endl;
    cout << p->breadth << endl;
    */

    //How to create all the above in heap
    struct Rectangle* p; //2bytes in Stack
    p = (struct Rectangle*)malloc(sizeof(struct Rectangle)); //heap
    if (p != NULL)
    {
        p->length = 15;
        p->breadth = 7;

        //cout << sizeof(short) << endl;  //2byte
        //cout << sizeof(int) << endl;    //4byte
        //cout << sizeof(struct Rectangle) << endl;   //8byte

        cout << p->length << endl;
        cout << p->breadth << endl;
    }
    return 0;
}