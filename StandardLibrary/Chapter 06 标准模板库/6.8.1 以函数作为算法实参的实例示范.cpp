// 示例: stl/foreach1.cpp
// 示例: stl/transform1.cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iterator>
#include "print.h"

using namespace std;

void print(int elem)
{
	cout << elem << " ";
}

void foreach1()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
	{
		coll.push_back(i);
	}

	for_each(coll.cbegin(), coll.cend(),
		print);
	cout << endl;
}

int square(int value)
{
	return value * value;
}

void transform1()
{
	set<int> coll1;
	vector<int> coll2;

	for (int i = 1; i <= 9; ++i)
	{
		coll1.insert(i);
	}
	PRINT_ELEMENTS(coll1, "initialized: ");

	// 将coll1中的元素square()后,插入coll2中
	std::transform(coll1.cbegin(), coll1.cend(),
		std::back_inserter(coll2),
		square);

	PRINT_ELEMENTS(coll2, "squared:     ");
}

//int main()
//{
//	//foreach1();
//	transform1();
//}