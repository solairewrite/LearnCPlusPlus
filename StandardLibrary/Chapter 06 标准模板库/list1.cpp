#include <list>
#include <iostream>

using namespace std;

//int main()
//{
//	list<char> coll;
//
//	for (char c = 'a'; c <= 'z'; ++c)
//	{
//		coll.push_back(c);
//	}
//
//	// elem是当前被处理元素的copy,集合内部没有任何东西被改动
//	for (auto elem : coll)
//	{
//		cout << elem << ' ';
//	}
//	cout << endl;
//
//	// 如果想改动传入的集合的元素,必须将elem声明为一个非常量的reference
//	for (auto& elem : coll)
//	{
//	}
//
//	// 就像函数参数那样,通常你应该使用一个常量reference以避免一次copy操作
//	for (const auto& elem : coll)
//	{
//	}
//}