#include "../Public/第1章-让自己习惯C++.h"
#include <vector>

Chapter1::Chapter1()
{

}

void Chapter1::MainFunc()
{
	char greeting[] = "Hello";
	const char* p1 = greeting; // 常量数据
	char* const p2 = greeting; // 常量指针
	// const在*左边,表示数据是常量
	// const在*右边,表示指针是常量

	std::vector<int> vec;

	const std::vector<int>::iterator iter = vec.begin(); // iter的作用像个T* const
	*iter = 10;
	//++iter; // 错误

	std::vector<int>::const_iterator citer = vec.begin(); // citer的作用像个const T*
	//*citer = 10; // 错误
	++citer;
}
