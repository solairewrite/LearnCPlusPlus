// 示例: util/sharedptr1.cpp
#include <memory> // std::shared_ptr
#include <string>
#include <iostream>

using namespace std;

// 声明
void test_shared_ptr()
{
	// explicit构造函数
	std::shared_ptr<std::string> pNico1(new std::string("nico"));
	// 新式初始化语法
	shared_ptr<string> pNico2{ new string("nico") };
	// 使用便捷函数make_shared()
	shared_ptr<string> pNico3 = std::make_shared<string>("nico");
	// 先声明,再用reset()赋值
	shared_ptr<string> pNico4;
	pNico4.reset(new string("nico"));
}

// 定义Deleter
void test_lambda_deleter()
{
	auto lamb = [](string* p) {
		cout << "delete: " << *p << endl;
		delete p;
	};

	shared_ptr<string> sp(new string("nico"), lamb);

	sp = nullptr;
}

// 定义array deleter
void test_array_deleter()
{
	auto lamb = [](int* p) {
		delete[] p;
	};
	// lambda
	shared_ptr<int> p1(new int[10], lamb);
	// 或者辅助函数
	shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
}

int main()
{
	//test_shared_ptr();

	//test_lambda_deleter();

	test_array_deleter();
}