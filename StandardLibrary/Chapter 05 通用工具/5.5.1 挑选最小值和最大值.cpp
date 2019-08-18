// 示例: util/minmax1.cpp
#include <algorithm>
#include <iostream>

using namespace std;

// 比较函数 return para1 < para2
bool int_ptr_less(int* a, int* b)
{
	return *a < *b;
}

//int main()
//{
//	int x = 17;
//	int y = 42;
//	int z = 33;
//	int* px = &x;
//	int* py = &y;
//	int* pz = &z;
//
//	int* pmax = std::max(px, py, int_ptr_less);
//	cout << *pmax << endl;
//
//	std::pair<int*, int*> extremes = std::minmax({ px,py,pz }, int_ptr_less);
//	cout << *extremes.first << ", " << *extremes.second << endl;
//
//	auto lam = [](int* a, int* b) {
//		return *a < *b;
//	};
//	auto extremes2 = minmax({ px,py,pz }, lam);
//	cout << *extremes2.first << ", " << *extremes2.second << endl;
//}