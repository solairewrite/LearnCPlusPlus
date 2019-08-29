// Ê¾Àý: cont/array1.cpp
#include <array>
#include <iostream>
#include <string>
#include "print.h"
#include <numeric> // accumulate
#include <algorithm> // transform
#include <functional> // negate

using namespace std;

void init()
{
	array<int, 4 > x = {};
	array<int, 5> coll = { 1,2,3,4,5 };
	array<int, 10> c2 = { 42 };
}

void tuple_interface()
{
	typedef array<string, 5> FiveStrings;

	FiveStrings a = { "hello","nico","how","are","you" };

	cout << std::tuple_size<FiveStrings>::value << endl;
	cout << typeid(tuple_element<1, FiveStrings>::type).name() << endl;
	cout << std::get<1>(a) << endl;
}

void array1()
{
	array<int, 10> a = { 1,2,3,4 };
	PRINT_ELEMENTS(a);

	a.back() = 9;
	a[a.size() - 2] = 8;
	PRINT_ELEMENTS(a);

	cout << "sum: "
		<< accumulate(a.begin(), a.end(), 0)
		<< endl;

	transform(a.begin(), a.end(),
		a.begin(),
		negate<int>());
	PRINT_ELEMENTS(a);
}

void main()
{
	//init();
	//tuple_interface();
	
	array1();
}