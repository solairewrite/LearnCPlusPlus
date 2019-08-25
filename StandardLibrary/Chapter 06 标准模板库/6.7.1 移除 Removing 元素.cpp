// ʾ��: stl/remove1.cpp
// ʾ��: stl/remove2.cpp
// ʾ��: stl/remove3.cpp
// ʾ��: stl/remove4.cpp
#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
#include <set>

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

	// remove()û�иı�Ԫ������,��ֵΪ3��Ԫ�ر������Ԫ�ظ���,����β�˵�Ԫ�ز���
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

	// ������end��"���޸ļ���"����Ԫ���Ƴ�����������߼��յ�
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

	copy(coll.begin(), end,
		ostream_iterator<int>(cout, " "));
	cout << endl;
	// 6 5 4 2 1 1 2 4 5 6

	cout << "number of removed elements: "
		<< distance(end, coll.end()) << endl;
	// 2

	// ɾ��Ԫ��
	coll.erase(end, coll.end());

	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
	// 6 5 4 2 1 1 2 4 5 6
}

void remove3()
{
	set<int> coll = { 1,2,3,4,5,6,7,8,9 };

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	int num = coll.erase(3);

	cout << "number of removed elements: " << num << endl;

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

void remove4()
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	// listֱ��ɾ��Ԫ��,������"����"
	coll.remove(4);

	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

//int main()
//{
//	//remove1();
//	//remove2();
//	//remove3();
//	remove4();
//}