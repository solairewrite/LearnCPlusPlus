// std::function<>提供多态外覆器,可以概括function pointer记号
// 通过函数指针调用函数
// 函数指针用于指向一个函数,函数名是函数体的入口地址
#include <iostream>
#include <functional> // std::function
#include <vector>

using namespace std;

void func(int x, int y)
{
	cout << "func(" << x << ", " << y << ") = " << x + y << endl;
}

class C
{
public:
	void memfunc(int x, int y) const
	{
		cout << "C::memfunc(" << x << ", " << y << ") = " << x + y << endl;
	}
};

int main()
{
	auto lam = [](int x, int y) {
		cout << "lam(" << x << ", " << y << ") = " << x + y << endl;
	};

	// 将函数加入数组中,依次执行
	std::vector<std::function<void(int, int)>> tasks;
	tasks.push_back(func);
	tasks.push_back(lam);

	for (std::function<void(int, int)> f : tasks)
	{
		f(33, 66);
	}
	cout << endl;

	// 成员函数的调用对象,必须作为第一个实参
	std::function<void(const C&, int, int)> mf;
	mf = &C::memfunc;
	mf(C(), 42, 77);
}