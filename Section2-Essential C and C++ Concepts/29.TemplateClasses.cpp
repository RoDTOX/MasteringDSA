#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class Arithmetic 
{
private:
	T a;
	T b;

public:
	Arithmetic(T a, T b);
	T add();
	T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
	return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
	return a - b;
}

int main()
{
	Arithmetic<int> ar(10,5);
	cout << ar.add() << endl;
	cout << ar.sub() << endl;

	Arithmetic<float> ari(10.9, 4.1);
	cout << ari.add() << endl;
	cout << ari.sub() << endl;

	return 0;
}