// ʾ��: stl/copy2.cpp
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>

using namespace std;

template<typename T>
void printCollection(const T& coll)
{
	for (auto it = coll.begin(); it != coll.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	list<int> coll1 = { 1,2,3,4,5,6,7,8,9 };

	// ʹ��push_back()������β�˰���Ԫ��,Ԫ�����д���Ͱ��������ͬ
	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(),
		back_inserter(coll2));

	// ʹ��push_front()������ǰ�˰���Ԫ��,Ԫ�����д���Ͱ�������෴
	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(),
		front_inserter(coll3));

	// ʹ��insert()��ָ��λ�ð���Ԫ��,Ԫ�����д���Ͱ��������ͬ
	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(),
		inserter(coll4, coll4.begin()));

	printCollection(coll1); // 1-9
	printCollection(coll2); // 1-9
	printCollection(coll3); // 9-1
	printCollection(coll4); // 1-9
}