#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//int main()
//{
//	vector<int> coll = { 2,5,4,1,6,3 };
//
//	// 返回迭代器
//	auto minpos = min_element(coll.cbegin(), coll.cend());
//	cout << "min: " << *minpos << endl;
//	auto maxpos = max_element(coll.cbegin(), coll.cend());
//	cout << "max: " << *maxpos << endl;
//
//	sort(coll.begin(), coll.end());
//
//	auto pos3 = find(coll.begin(), coll.end(), 3);
//
//	// 逆转两个位置之间的元素
//	reverse(pos3, coll.end());
//
//	for (auto elem:coll)
//	{
//		cout << elem << ' ';
//	}
//	cout << endl;
//}