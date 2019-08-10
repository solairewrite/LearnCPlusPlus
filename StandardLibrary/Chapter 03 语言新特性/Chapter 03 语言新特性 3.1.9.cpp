#include <iostream>
#include <bitset>
#include <vector>
#include <functional>
#include <map>

using namespace std;

void print()
{

}

// variadic template: 个数不定,类型不定的实参
template<typename T, typename... Types>
void print(const T& firstArg, const Types& ... args)
{
	cout << firstArg << endl;
	// 必须提供非模板重载函数print(),才能结束整个递归操作
	print(args...);
}

// Lambda: 允许inline函数的定义式被用作一个参数,或是一个local对象
void Lambda()
{
	// 最小型的lambda函数没有参数,什么也不做
	[] {
		cout << "hello lambda 1" << endl;;
	};

	// 直接调用
	[] {
		cout << "hello lambda 2" << endl;
	}();

	// 传递给对象
	auto lambda1 = [] {
		cout << "hello lambda 3" << endl;
	};
	lambda1();

	// 参数
	auto lambda2 = [](const std::string& s) {
		cout << s << endl;
	};
	lambda2("hello lambda 4");

	// 返回值,自动推导
	[] {
		return 42;
	};

	// 返回值,指明
	[]()->double {
		return 42;
	};

}

void Lambda2()
{
	int x = 0;
	int y = 42;
	// []内访问外部作用域, =表示传值的方式访问, &表示以引用的方式访问
	// 这里x的值就是0,即使下面对x重新赋值
	auto qqq = [x, &y] {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		++y;
	};
	x = y = 77;
	qqq(); // x: 0, y: 77
	qqq(); // x: 0, y: 78
	cout << "final y:" << y << endl; // y: 79
}

void Lambda3()
{
	int id = 0;
	// mutable使lambda通过传值和传递引用混合
	auto f = [id]()mutable {
		// 这里id是通过值传递的,但是可以修改,而不改变外部的id值
		cout << "id: " << id << endl;
		++id;
	};
	id = 42;
	f(); // id: 0
	f(); // id: 1
	f(); // id: 2
	cout << id << endl; // id: 42
}

// 函数的返回类型为lambda
std::function<int(int, int)> returnLambda()
{
	return [](int x, int y) {
		return x * y;
	};
}

// 关键字 decltype: 让编译器找出表达式类型
void decltypeTest()
{
	std::map<std::string, float> coll;
	decltype(coll)::value_type elem;
}

// 新的函数声明语法,将函数的返回类型转而声明于参数列之后
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
	return x + y;
}

/**
int main()
{
	//print(7.5, "hello", std::bitset<16>(377), 42);

	//Lambda();
	//Lambda2();
	//Lambda3();

	//auto lf = returnLambda();
	//cout << lf(6, 7) << endl; // 42

	//decltypeTest();

	cout << int('b') << endl;
	cout << add('b', 1.2f) << endl;

	//system("pause");
}
*/