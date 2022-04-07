#include <stdio.h>
#include <iostream>
using namespace std;

class Rectangle
{
private:
	int lenght;
	int breadth;

public:
	Rectangle() { lenght=breadth = 0; };
	Rectangle(int l, int b);
	int area();
	int perimeter();
	int getLenght() { return lenght; }
	void setLength(int l) { lenght = l; };
	~Rectangle();
};

Rectangle::Rectangle(int l, int b)
{
	lenght = l;
	breadth = b;
}

int Rectangle::area()
{
	return lenght * breadth;
}

int Rectangle::perimeter()
{
	return 2 * (lenght + breadth);
}

Rectangle::~Rectangle()
{

}

int main()
{
	Rectangle r = {10,5};
	cout << r.area() << endl;
	cout << r.perimeter() << endl;
	r.setLength(3);
	cout << r.getLenght() << endl;
	return 0;
}