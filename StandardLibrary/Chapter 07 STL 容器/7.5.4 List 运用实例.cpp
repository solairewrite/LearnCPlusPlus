// 示例: cont/list1.cpp
#include <list>
#include <iostream>
#include <iterator> // ostream_iterator

using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
	cout << "list1: ";
	copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << "list2: ";
	copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main()
{
	list<int> list1, list2;

	for (int i = 0; i < 6; ++i)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	printLists(list1, list2);

	// 在list2中第一个元素值为3的位置前,插入所有list1的元素
	list2.splice(find(list2.begin(), list2.end(), 3),
		list1);
	printLists(list1, list2);

	// 将第一个元素移至最后
	list2.splice(list2.end(), // destination pos
		list2, // source list
		list2.begin()); // source pos
	printLists(list1, list2);

	list2.sort();
	list1 = list2;
	list2.unique(); // 删除重复元素
	printLists(list1, list2);

	// 将list2中的元素插入list1中,排好序
	list1.merge(list2);
	printLists(list1, list2);
}