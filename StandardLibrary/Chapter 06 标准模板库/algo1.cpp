#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//int main()
//{
//	vector<int> coll = { 2,5,4,1,6,3 };
//
//	// ���ص�����
//	auto minpos = min_element(coll.cbegin(), coll.cend());
//	cout << "min: " << *minpos << endl;
//	auto maxpos = max_element(coll.cbegin(), coll.cend());
//	cout << "max: " << *maxpos << endl;
//
//	sort(coll.begin(), coll.end());
//
//	auto pos3 = find(coll.begin(), coll.end(), 3);
//
//	// ��ת����λ��֮���Ԫ��
//	reverse(pos3, coll.end());
//
//	for (auto elem:coll)
//	{
//		cout << elem << ' ';
//	}
//	cout << endl;
//}