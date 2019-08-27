// Ê¾Àý: stl/fo1.cpp
#include <deque>
#include <algorithm> // transform
#include <functional> // negate<>
#include <iostream>
#include "print.h"

using namespace std;

//int main()
//{
//	deque<int> coll = { 1,2,3,5,7 };
//
//	PRINT_ELEMENTS(coll, "init: ");
//
//	transform(coll.cbegin(), coll.cend(),
//		coll.begin(),
//		negate<int>());
//	PRINT_ELEMENTS(coll, "negated: ");
//
//	transform(coll.cbegin(), coll.cend(), // source 1
//		coll.cbegin(), // source 2
//		coll.begin(), // destination
//		multiplies<int>()); // operation
//	PRINT_ELEMENTS(coll, "squared: ");
//}