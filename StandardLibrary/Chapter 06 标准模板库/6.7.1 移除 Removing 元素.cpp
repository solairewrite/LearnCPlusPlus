// 示例: stl/remove1.cpp
#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>

using namespace std;

void remove1()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	cout << "pre:  ";
	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// remove()没有改变元素数量,数值为3的元素被后面的元素覆盖,集合尾端的元素不变
	remove(coll.begin(), coll.end(), 3);

	cout << "post: ";
	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// pre:  6 5 4 3 2 1 1 2 3 4 5 6
	// post: 6 5 4 2 1 1 2 4 5 6 5 6
}

void remove2()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_back(i);
		coll.push_front(i);
	}

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
	// 6 5 4 3 2 1 1 2 3 4 5 6

	// 迭代器end是"被修改集合"经过元素移除动作后的新逻辑终点
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

	copy(coll.begin(), end,
		ostream_iterator<int>(cout, " "));
	cout << endl;
	// 6 5 4 2 1 1 2 4 5 6

	cout << "number of removed elements: "
		<< distance(end, coll.end()) << endl;
	// 2

	// 删除元素
	coll.erase(end, coll.end());

	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
	// 6 5 4 2 1 1 2 4 5 6
}

int main()
{
	//remove1();
	remove2();
}