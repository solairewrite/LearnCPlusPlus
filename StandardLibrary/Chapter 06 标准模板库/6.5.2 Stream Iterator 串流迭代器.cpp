// 示例: stl/ioiter1.cpp

/* 6.5.3 Reverse Iterator 反向迭代器 */

// 示例: stl/reviter1.cpp
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//int main()
//{
//	vector<int> coll;
//
//	for (int i = 1; i <= 9; ++i)
//	{
//		coll.push_back(i);
//	}
//
//	copy(coll.crbegin(), coll.crend(),
//		ostream_iterator<int>(cout, " "));
//	cout << endl; // 9-1
//}