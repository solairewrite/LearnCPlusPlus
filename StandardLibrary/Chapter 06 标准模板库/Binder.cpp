// Ê¾Àý: stl/bind1.cpp
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional> // placeholders
#include <iostream>
#include "print.h"

using namespace std;
using namespace std::placeholders; // _1 Õ¼Î»·û

int main()
{
	set<int, greater<int>> coll1 = { 1,2,3,4,5,6,7,8,9 };
	deque<int> coll2;

	PRINT_ELEMENTS(coll1, "init: ");
	// 9-1

	transform(coll1.cbegin(), coll1.cend(),
		back_inserter(coll2),
		bind(multiplies<int>(), _1, 10));
	PRINT_ELEMENTS(coll2, "trans: ");
	// 90-10

	replace_if(coll2.begin(), coll2.end(),
		bind(equal_to<int>(), _1, 70),
		42);
	PRINT_ELEMENTS(coll2, "replaced: ");
	// 90 80 42 60-10

	auto predicate = bind(logical_and<bool>(),
		bind(greater_equal<int>(), _1, 50),
		bind(less_equal<int>(), _1, 80));

	coll2.erase(
		remove_if(coll2.begin(), coll2.end(), 
			predicate),
		coll2.end());
	PRINT_ELEMENTS(coll2, "removed: ");
	// 90 42 40-10

	auto f1 = bind(multiplies<int>(), _1, 10);
	cout << f1(99) << endl;
}