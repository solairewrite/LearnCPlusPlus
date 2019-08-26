// ʾ��: stl/lambda1.cpp
// ʾ��: stl/sort2.cpp
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

void lambda1()
{
	deque<int> coll = { 1,3,19,5,13,7,11,2,17 };

	int x = 5;
	int y = 12;
	// [=]: x,y��by value����ʽ����lambda; [&]: by reference
	auto pos = find_if(coll.begin(), coll.end(),
		[=](int i) {
			return i > x && i < y;
		});

	cout << "first elem >5 and <12: " << *pos << endl;
}

//int main()
//{
//	lambda1();
//}