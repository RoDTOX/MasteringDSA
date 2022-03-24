// FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

enum card {no_card, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Queen, King };
enum shape {no_shape, Clover=10, Pike=11, Tile=12, Heart=13};
enum color {no_color, Black, Red};


/*struct declaration can also be: (cards_properties becomes global var)
struct Card
{
    int face;
    int shape;
    int color;
    enum shape Z;
}cards_properties;
*/



int main()
{
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

    //12. Practice Pointer to structure


    return 0;
}