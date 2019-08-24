// 示例: stl/list1odd.cpp
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
//	// "只读"模式遍历
//	list<char>::const_iterator pos;
//	for (pos = coll.begin(); pos != coll.end(); ++pos)
//	{
//		cout << *pos << ' ';
//	}
//	cout << endl;
//
//	// "读写"模式遍历
//	list<char>::iterator iter;
//	for (iter = coll.begin(); iter != coll.end(); ++iter)
//	{
//		*iter = toupper(*iter);
//		cout << *iter << " ";
//	}
//	cout << endl;
//
//	// 读写遍历
//	for (auto it = coll.begin(); it != coll.end(); ++it)
//	{
//	}
//	// 只读遍历
//	for (auto it = coll.cbegin(); it != coll.cend(); ++it)
//	{
//	}
//}