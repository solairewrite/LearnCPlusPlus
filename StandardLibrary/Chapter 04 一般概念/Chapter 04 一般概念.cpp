// util/exception.hpp 示范使用泛型打印异常

#include <iostream>
#include <memory> // std::shared_ptr
#include <functional> // std::bind

using namespace std;

void func(int x, int y)
{
	cout << "func(" << x << ", " << y << ")" << endl;
}

auto la = [](int x, int y) {
	cout << "la(" << x << ", " << y << ")" << endl;
};

class C
{
public:
	// 函数对象
	void operator()(int x, int y) const
	{
		cout << this << "\t" << "C(" << x << ", " << y << ")" << endl;
	}
	void memfunc(int x, int y) const
	{
		cout << this << "\t" << "memfunc(" << x << ", " << y << ")" << endl;
	}
};

int main()
{
	C c;
	std::shared_ptr<C> sp(new C);
	
	// Callable Object 可被调用的对象
	// bind() uses callable objects to bind arguments
	std::bind(func, 7, 3)(); // func(7, 3)
	std::bind(la, 7, 3)(); // la(7, 3)
	std::bind(C(), 7, 3)(); // C(7, 3)
	std::bind(&C::memfunc, c, 7, 3)(); // c.memfunc(7, 3)
	std::bind(&C::memfunc, sp, 7, 3)(); // sp->memfunc(7, 3)
}